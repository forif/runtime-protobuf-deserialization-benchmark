#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sys/types.h>    
#include <sys/stat.h>    
#include <fcntl.h>
#include <memory>
#include <time.h>
#include <ctime>
 
#include <google/protobuf/descriptor.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/tokenizer.h>
#include <google/protobuf/compiler/parser.h>
#include <google/protobuf/util/json_util.h>


using namespace google::protobuf;
using namespace google::protobuf::io;
using namespace google::protobuf::compiler;
using namespace google::protobuf::util;
using namespace std;


shared_ptr<DescriptorPool> pool = make_shared<DescriptorPool>();

// This function removes the last part in a path
string removeLast(string path) {
    // if path is relative
    if (path.size() == 0) {
        return "../";
    } else if (path.rfind("../") == path.size() - 3) {
        return path + "../";
    } else {
        int index = path.find_last_of("/\\", path.size()-2);
        if (index == -1) {
            return "";
        } else {
            // path is relative or absolute
            return path.substr(0, index+1);
        }
    }
}

// This function returns a new path based on the old path and a relative path from it
string getNewPath(string old_path, string relative_path) {
    // if relative_path is absolute, return it directly
    if (relative_path.find_first_of("\\") != -1) {
        return relative_path;
    }

    // if it is indeed relative, build a new path from old_path
    old_path = removeLast(old_path);
    while (relative_path.find("../") != -1) {
        old_path = removeLast(old_path);
        relative_path = relative_path.substr(3);
    }

    return old_path + relative_path;
}

// This function build a Fild Descriptor and add it into the descriptor pool from the given proto definition file
// Try your absolute best to avoid importing the same dependency between two .proto files, 
// especially if they are not in the same folder, as this does not seem to be supported
const FileDescriptor* buildFileDescriptor(const string file_path, const std::string& file_name) {
    cout << "building file descriptor [" << file_path << "] name: " << file_name << endl;

    // open the proto definition file
    int def_messageFile = open(file_path.c_str(), O_RDONLY);
    FileInputStream file_input(def_messageFile);

    // if the .proto is already built, skip
    if (pool -> FindFileByName(file_name)) {
        return NULL;
    }

    // put the protobuf definition into FileDescriptorProto with Parser
    // FileDescriptorProto is an in-memory representation of the protobuf definition, 
    // and unlike the poor api description made by Google, it has useful functions
    Tokenizer input(&file_input, NULL);
    FileDescriptorProto file_desc_proto;
    Parser parser;
    if (!parser.Parse(&input, &file_desc_proto)) {
        cerr << "Failed to parse .proto definition:" << endl;
        return NULL;
    }

    // check if there are any dependency messages. If there is, build them first
    for (int i = 0; i < file_desc_proto.dependency_size(); i ++) {
        string temp = file_desc_proto.dependency(i);
        cout << "found dependency proto file: " << temp << endl;
        buildFileDescriptor(getNewPath(file_path, temp), temp);
    }

    // give the file a name if it does not have one, otherwise FileDescriptor will fail
    if (!file_desc_proto.has_name()) {
        file_desc_proto.set_name(file_name);
    }

    // use DescriptorPool to build a FileDescriptor
    const FileDescriptor* file_desc = pool -> BuildFile(file_desc_proto);
    if (file_desc == NULL) {
        cerr << "Cannot get file descriptor from file descriptor proto: " << file_name << endl;
        return NULL;
    }

    return file_desc;
}


// This function checks if a file exists
bool fileExists(const string& fileName) {
    ifstream infile(fileName);
    return infile.good();
}


// This function finds the file index of the message type with corresponding given name in the File Descriptor
// returns -1 if not found
int findFileIndex(const FileDescriptor* file_desc, string message_name) {
    int message_count = file_desc -> message_type_count();
    int ser_file_index = -1;
    for (int message_index = 0; message_index < message_count; message_index ++) {
        // check the message with current index
        string message_type = file_desc -> message_type(message_index) -> name();
        if (message_type == message_name) {
            ser_file_index = message_index;
        }

        // print the fields of this message
        // format: name: type (label) (number)
        // all this can be commented out if not needed
        // const google::protobuf::Descriptor* message_desc = file_desc->FindMessageTypeByName(message_type);
        // if (message_desc == NULL) {
        //     std::cerr << "Cannot get message descriptor of message: " << message_type
        //     << ", DebugString(): " << file_desc->DebugString();
        //     return -6;
        // }

        // cout << message_type << endl;
        // uint8_t c = 0;
        // for (int i = 1; c < message_desc->field_count(); i++) {
        //     const FieldDescriptor* field = message_desc->FindFieldByNumber(i);
        //     if (field) {
        //         std::cout << field->name() << ": " << field->type_name() << " ("
        //                     << field->label() << ")" << " ("
        //                     << field->number() << ")" << std::endl;
        //         c ++;
        //     }
            
        //     if (i > 536870911) {
        //         std::cerr << "Error fieldDescriptor object is NULL, field_count() = "
        //                     << message_desc->field_count() << std::endl;
        //     }
        // }

        // // change a line for aesthetic
        // cout << endl;
    }

    if (ser_file_index == -1) {
        std::cerr << "Given message type [" << message_name << "] not found." << endl;
        return -7;
    }

    return ser_file_index;
}

// This function prints out the deserialized result
void readMessage(const Message& mutable_msg) {
    string output;
    JsonPrintOptions options;
    options.add_whitespace = false;
    options.always_print_primitive_fields = false;
    options.preserve_proto_field_names = true;
    MessageToJsonString(mutable_msg, &output, options);
    // cout << output << endl;
}

// Main function: generate deserialze the messages and print them
// sample: ./pb_reader ../../lib/protolib/crestmessage.proto ../protobuf_practice/messages.txt CrestMessage 5
// compile cmd: g++ -o pb_reader pb_reader.cc -lprotobuf -lpthread
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    // 4 arguments, including argv[0]
    // argv[1] is the path of given .proto file that contains the protobuf definition
    // argv[2] is the path of serialized file that will needs to be deserialized
    // argv[3] is the name of the message in the serialized file
    if (argc > 4) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // default path of proto definition (argv[1]) is ../../lib/protolib/crestmessage.proto
    string definition_path = "../msgs/crestmessage.proto";
    if (argc > 1) {
        definition_path = argv[1];
    }
    if (!fileExists(definition_path)) {
        cerr << "Proto definition file does not exist." << endl;
        return -2;
    }

    // default path of serialized file (argv[2]) is ../protobuf_practice/messages.txt
    string ser_file_path = "../msgs.pbbin";
    if (argc > 2) {
        ser_file_path = argv[2];
    }
    if (!fileExists(ser_file_path)) {
        cerr << "Serialized file does not exist: " << ser_file_path << endl;
        return -3;
    }

    // default message name (argv[3]) is CrestMessage
    string message_name = "CrestMessage";
    if (argc > 3 and *argv[3]) {
        message_name = argv[3];
    }

    // FileDescriptor contains all necessary meta data to describe all the members of a message that adheres to the proto definition
    string file_name = definition_path.substr(definition_path.find_last_of("/\\") + 1);
    const FileDescriptor* file_desc = buildFileDescriptor(definition_path, file_name);
    if (!file_desc) return -4;

    // there may be multiple messages in one file, loop through them and
    // find the message matching the one in the serialized file
    // cout << "looking for file index for " << message_name << ": " << endl;
    int ser_file_index = findFileIndex(file_desc, message_name);

    // Create an empty Message object that will hold the deserialized message with Descriptor
    string message_type = file_desc -> message_type(ser_file_index) -> name();

    const Descriptor* message_desc = file_desc->FindMessageTypeByName(message_type);

    std::unique_ptr<DynamicMessageFactory> factory(new DynamicMessageFactory);
    const Message* prototype_msg = factory->GetPrototype(message_desc);
    if (prototype_msg == NULL) {
        cerr << "Cannot create prototype message from message descriptor";
        return -8;
    }
    
    std::unique_ptr<Message> mutable_msg(prototype_msg->New());
    if (mutable_msg == NULL) {
        cerr << "Failed in prototype_msg->New(); to create mutable message";
        return -9;
    }

    // open the serialized file
    // As before, the first four bytes will represent the size of the message
    ifstream ser_messageFile;
    ser_messageFile.open(ser_file_path, ios::in | ios::binary);

    int repeats = 0;
    ser_messageFile.read(reinterpret_cast<char*>(&repeats), sizeof(repeats));
    cout << "total " << repeats << " messages in " << ser_file_path << endl;

    // start the time and byte counter
    int64_t totalBytes = 0;
    double totalTime = 0;
    clock_t clk;

    // repeat reading the message
    for (int i = 0; i < repeats; i ++) {
        // read the data in serialized file into the created empty message object
        int size;
        ser_messageFile.read(reinterpret_cast<char*>(&size), sizeof(int));

        // read in the message
        vector<char> buffer(size);
        ser_messageFile.read(buffer.data(), size);

        // for each message, start the timer individually, starting from deserializing
        clk = clock();
        if (!mutable_msg -> ParseFromArray(buffer.data(), size)) {
            cerr << "Error parsing message." << endl;
            return 10;
        }

        // convert the deserialized message to json and read it
        readMessage(*mutable_msg);

        // increment time and byte counter
        totalTime += (double) (clock() - clk) / CLOCKS_PER_SEC;
        totalBytes += size;

        // clear the message
        mutable_msg -> Clear();
    }

    // calculate performance
    cout << "Performance of c++ dynamic reader: total " << totalTime << "s" << endl;
    cout << "Number of messages processed per second: " << repeats / totalTime << endl;
    cout << "Number of bytes processed per second: " << totalBytes / totalTime << endl;

    // close the pool
    mutable_msg.reset();
    factory.reset();
    pool.reset();
    return 0;
}
