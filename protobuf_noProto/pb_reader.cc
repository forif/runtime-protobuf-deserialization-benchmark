#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sys/types.h>    
#include <sys/stat.h>    
#include <fcntl.h>
 
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

// This function checks if a file exists
bool fileExists(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

// Main function: generate deserialze the messages and print them
// sample.txt for testing:
// Message ID: 1804289383
// Message val: 0.394383
// Message name: RBBMQBHCDARZOWKKYHIDDQSCDXRJMOWFRXSJYBLDBEFSARCBYNECDYGGXXPKLORELLNMPAPQFWKHOP
// Message checked: 1
// Message size: 97
// compile cmd: g++ -o pb_reader pb_reader.cc -lprotobuf
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

    // default path of proto definition (argv[1]) is ../topmessage.proto
    string definition_path = "topmessage.proto";
    if (argc > 1 and *argv[1]) {
        definition_path = argv[1];
    }
    if (!fileExists(&definition_path[0])) {
        cerr << "Proto definition file does not exist." << endl;
        return -2;
    }

    // default path of serialized file (argv[2]) is ../sample.txt
    string ser_file_path = "sample.txt";
    if (argc > 2 and *argv[2]) {
        ser_file_path = argv[2];
    }
    if (!fileExists(&ser_file_path[0])) {
        cerr << "Serialized file does not exist." << endl;
        return -3;
    }

    // default message name (argv[3]) is TopMessage
    string message_name = "TopMessage";
    if (argc > 3 and *argv[3]) {
        message_name = argv[3];
    }

    // open the proto definition file
    int def_messageFile = open(definition_path.c_str(), O_RDONLY);
    FileInputStream file_input(def_messageFile);

    // put the protobuf definition into FileDescriptorProto with Parser
    // FileDescriptorProto is just an in-memory representation of the protobuf definition, it merely has any useful function
    Tokenizer input(&file_input, NULL);
    FileDescriptorProto file_desc_proto;
    Parser parser;
    if (!parser.Parse(&input, &file_desc_proto)) {
        std::cerr << "Failed to parse .proto definition:" << endl;
        return -4;
    }

    // give the file a name if it does not have one, otherwise FileDescriptor will fail
    string file_name = "ABigAPIName";
    if (!file_desc_proto.has_name()) {
        file_desc_proto.set_name(file_name);
    }

    // use DescriptorPool to build a FileDescriptor
    // FileDescriptor contains all necessary meta data to describe all the members of a message that adheres to the proto definition
    google::protobuf::DescriptorPool pool;
    const google::protobuf::FileDescriptor* file_desc = pool.BuildFile(file_desc_proto);
    if (file_desc == NULL) {
        std::cerr << "Cannot get file descriptor from file descriptor proto"
        << file_desc_proto.DebugString();
        return -5;
    }

    // there may be multiple messages in one file, loop through them and
    // find the message matching the one in the serialized file
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
        const google::protobuf::Descriptor* message_desc =
            file_desc->FindMessageTypeByName(message_type);
        if (message_desc == NULL) {
            std::cerr << "Cannot get message descriptor of message: " << message_type
            << ", DebugString(): " << file_desc->DebugString();
            return -6;
        }

        cout << message_type << endl;
        uint8_t c = 0;
        for (int i = 1; c < message_desc->field_count(); i++) {
            const FieldDescriptor* field = message_desc->FindFieldByNumber(i);
            if (field) {
                std::cout << field->name() << ": " << field->type_name() << " ("
                            << field->label() << ")" << " ("
                            << field->number() << ")" << std::endl;
                c ++;
            }
            
            if (i > 536870911) {
                std::cerr << "Error fieldDescriptor object is NULL, field_count() = "
                            << message_desc->field_count() << std::endl;
            }
        }

        // change a line for aesthetic
        cout << endl;
    }

    if (ser_file_index == -1) {
        std::cerr << "Given message type not found." << endl;
        return -7;
    }

    // Create an empty Message object that will hold the deserialized message with Descriptor
    string message_type = file_desc -> message_type(ser_file_index) -> name();
    cout << message_type << endl;

    const google::protobuf::Descriptor* message_desc =
        file_desc->FindMessageTypeByName(message_type);

    google::protobuf::DynamicMessageFactory factory;
    const google::protobuf::Message* prototype_msg =
        factory.GetPrototype(message_desc);
    if (prototype_msg == NULL) {
        std::cerr << "Cannot create prototype message from message descriptor";
        return -8;
    }
    
    google::protobuf::Message* mutable_msg = prototype_msg->New();
    if (mutable_msg == NULL) {
        std::cerr << "Failed in prototype_msg->New(); to create mutable message";
        return -9;
    }

    // open the serialized file and read it into the created empty message object
    ifstream ser_messageFile;
    ser_messageFile.open(ser_file_path, ios::in | ios::binary);

    int size;
    char sizeBuffer[4];
    ser_messageFile.read(sizeBuffer, 4);
    size = atoi(sizeBuffer);

    char buffer[size];
    ser_messageFile.read(buffer, size);
    mutable_msg -> ParseFromArray(buffer, size);

    // print out the deserialized result
    string output;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    MessageToJsonString(*mutable_msg, &output, options);
    std::cout << output << std::endl;

    // close the file

    return 0;
}