#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

#include <google/protobuf/util/json_util.h>

#include "crestmessage.pb.h"
#include "test/topmessage.pb.h"


using namespace std;
using namespace google::protobuf::util;


// convert the message to json
void convertToJSON(CrestMessage* msg) {
    string output;
    JsonPrintOptions options;
    options.add_whitespace = false;
    options.always_print_primitive_fields = false;
    options.preserve_proto_field_names = true;
    MessageToJsonString(*msg, &output, options);
    //cout << output << endl;
}


// This function checks if a file exists
bool fileExists(const std::string& fileName) {
    ifstream infile(fileName);
    return infile.good();
}


// Main function: generate deserialze the messages and print them
// sample: ./pb_reader 5 messages.txt
// compile cmd: g++ -o pb_reader pb_reader.cc ../../lib/protolib/test/topmessage.pb.cc ../../lib/protolib/crestmessage.pb.cc -I ../../lib/protolib/ -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc > 2) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // argv[1] is the path of folder for messages, default msgs.pbbin 
    string path = "msgs.pbbin";
    
    if (argc > 1) {
        path = argv[1];
    }
    if (!fileExists(path)) {
        cerr << "File does not exist." << endl;
        return -1;
    }

    // open the file saving messages
    ifstream messageFile;
    messageFile.open(path, ios::in | ios::binary);

    CrestMessage message;

    // start the time and byte counter
    int64_t totalBytes = 0;
    double totalTime = 0;
    clock_t clk;

    int repeat = 0;
    messageFile.read(reinterpret_cast<char*>(&repeat), sizeof(repeat));
    cout << "total " << repeat << " messages in " << path << endl;

    // repeat generating one message
    for(int i = 0; i < repeat; i ++) {
        // cout << "Current message #: " << i << endl;

        // deserialize the message
        int size;
        messageFile.read(reinterpret_cast<char*>(&size), sizeof(int));

        vector<char> buffer(size);
        messageFile.read(buffer.data(), size);

        // for each message, start the timer individually, starting from deserializing
        clk = clock();
        if (!message.ParseFromArray(buffer.data(), size)) {
            cerr << "Error parsing message." << endl;
            return 10;
        }

        // convert deserialized message to json and read it
        convertToJSON(&message);

        // increment time and byte counter
        totalTime += (double) (clock() - clk) / CLOCKS_PER_SEC;
        totalBytes += size;
    }

    // calculate performance
    cout << "Performance of c++ static reader:" << endl;
    cout << "Number of messages processed per second: " << repeat / totalTime << endl;
    cout << "Number of bytes processed per second: " << totalBytes / totalTime << endl;

    // close the file
    messageFile.close();
    return 0;
}
