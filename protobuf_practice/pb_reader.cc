#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <google/protobuf/util/json_util.h>
#include "../../lib/protolib/test/topmessage.pb.h"
#include "../../lib/protolib/crestmessage.pb.h"
using namespace std;
using namespace google::protobuf::util;

// print the information of the given message
void readMessage(CrestMessage* message) {
    cout << "Message ID : " << message -> id() << endl;
    cout << "Message name 1: " << message -> name(0) << endl;
    cout << "Message name 2: " << message -> name(1) << endl;

    int count = 0;
    for(auto elem : message->hash()) {
        std::cout << "map element " << count << ": " << elem.first << " " << elem.second << endl;
        count++;
    }

    cout << "Message fruit enum: " << message -> fruit() << endl;
    cout << "Message oneof red: " << message -> red() << endl;
    cout << "Message oneof blue: " << message -> blue() << endl;

    cout << "TopMessage:" << endl;
    cout << "Message id: " << message -> topm().id() << endl;
    cout << "Message name: " << message -> topm().name() << endl;
    cout << "Message val: " << message -> topm().val() << endl;
    cout << "Message checked: " << message -> topm().checked() << endl;

    cout << "NestMessage:" << endl;
    cout << "Message id: " << message -> nestm().id() << endl;
    cout << "Message name: " << message -> nestm().name() << endl;
}

// convert the message to json
void convertToJSON(CrestMessage* msg) {
    string output;
    JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    MessageToJsonString(*msg, &output, options);
    // cout << output << endl;
}

// This function checks if a file exists
bool fileExists(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

// Main function: generate deserialze the messages and print them
// sample: ./pb_reader 5 messages.txt
// compile cmd: g++ -o pb_reader pb_reader.cc ../../lib/protolib/test/topmessage.pb.cc ../../lib/protolib/crestmessage.pb.cc -I ../../lib/protolib/ -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc > 3) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // argv[1] is number of repeats, default 5
    // argv[2] is the path of folder for messages, default messages.txt
    int repeat = 1;
    string path = "messages.txt";
    
    if (argc > 1 and atoi(argv[1]) > 0) {
        repeat = atoi(argv[1]);
    }
    // cout << "The Value of repeat is " << repeat << endl;

    if (argc > 2 and *argv[2]) {
        path = argv[2];
    }
    if (!fileExists(&path[0])) {
        cerr << "File does not exist." << endl;
        return -1;
    }
    // cout << "The path for messages is " << path << endl;

    // open the file saving messages
    ifstream messageFile;
    messageFile.open(path, ios::in | ios::binary);
    CrestMessage message;

    // start the time and byte counter
    int totalBytes = 0;
    double totalTime = 0;
    clock_t clk;

    // repeat generating one message
    for(int i = 0; i < repeat; i ++) {
        // cout << "Current message #: " << i << endl;

        // deserialize the message
        int size;
        char sizeBuffer[4];
        messageFile.read(sizeBuffer, 4);
        size = atoi(sizeBuffer);
        // cout << "Message size: " << size << endl;

        char buffer[size];
        // string serializedMessage;
        messageFile.read(buffer, size);
        // serializedMessage = buffer;
        // message.ParseFromString(serializedMessage);

        // for each message, start the timer individually, starting from deserializing
        clk = clock();
        message.ParseFromArray(buffer, size);

        // convert deserialized message to json and read it
        convertToJSON(&message);

        // increment time and byte counter
        totalBytes += size;
        totalTime += (float) (clock() - clk) / CLOCKS_PER_SEC;
    }

    // calculate performance
    cout << "Performance of c++ static reader:" << endl;
    cout << "Number of messages processed per second: " << repeat / totalTime << endl;
    cout << "Number of bytes processed per second: " << totalBytes / totalTime << endl;

    // close the file
    messageFile.close();
    return 0;
}
