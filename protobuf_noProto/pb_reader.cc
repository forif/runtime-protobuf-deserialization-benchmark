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

using namespace google::protobuf;
using namespace google::protobuf::io;
using namespace google::protobuf::compiler;
using namespace std;

char text[] = "syntax = \"proto2\";\n"
  "message APIPort3 {"
  "required uint32 AppLedStateOn = 1;"
  "required uint32 PotiPercentage = 2;"
  "required uint32 VDD = 3;"
  "}";

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
// compile cmd: g++ -o pb_reader pb_reader.cc ../dst/topmessage.pb.cc -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc > 2) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // argv[1] is the path of given .proto file that contains the protobuf definition
    // default is ../"topmessage.proto"
    string path = "topmessage.proto";

    if (argc > 1 and *argv[1]) {
        path = argv[1];
    }
    if (!fileExists(&path[0])) {
        cerr << "File does not exist." << endl;
        return -1;
    }
    // cout << "The path for messages is " << path << endl;

    // open the file saving the proto definition
    int messageFile = open(path.c_str(), O_RDONLY);

    // deserialize the message
    // protoInput is a ZeroCopyInputStream containing raw serialized protobuf
    // ZeroCopyInputStream* input = new FileInputStream(messageFile);
    // int sizeOfSize = 4;
    // const void* sizeBuffer;
    // input -> Next(&sizeBuffer, &sizeOfSize);
    // void* temp1 = const_cast<void *>(sizeBuffer);
    // char* temp2 = static_cast<char *>(temp1);
    // int size = atoi(temp2);
    // cout << "size: " << size << endl;

    FileInputStream file_input(messageFile);

    // put the protobuf definition into FileDescriptorProto with Parser
    // FileDescriptorProto is just an in-memory representation of the protobuf definition, it merely has any useful function
    Tokenizer input(&file_input, NULL);
    FileDescriptorProto file_desc_proto;
    Parser parser;
    if (!parser.Parse(&input, &file_desc_proto)) {
        std::cerr << "Failed to parse .proto definition:" << endl;
        return -1;
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
        return -1;
    }

    // there may be multiple messages in one file, loop through them
    int message_count = file_desc -> message_type_count();
    for (int message_index = 0; message_index < message_count; message_index ++) {
        // find the message with given index
        string message_type = file_desc -> message_type(message_index) -> name();
        cout << message_type << endl;

        const google::protobuf::Descriptor* message_desc =
            file_desc->FindMessageTypeByName(message_type);
        if (message_desc == NULL) {
            std::cerr << "Cannot get message descriptor of message: " << message_type
            << ", DebugString(): " << file_desc->DebugString();
            return -2;
        }

        // print the fields of this message
        // format: name: type (label) (number)
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

    

    // close the file

    return 0;
}