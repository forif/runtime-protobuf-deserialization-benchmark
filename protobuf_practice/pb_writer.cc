#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../dst/topmessage.pb.h"
using namespace std;

// This function fills in a TopMessage with random numbers
void generateOne(TopMessage* message) {
    message -> set_id(rand());
    cout<< "Message ID:"<< message -> id() << endl;
}

// Main function: generate a # (specified by user) of messages and serialize them
// compile cmd: g++ -o pb_writer pb_writer.cc ../dst/topmessage.pb.cc -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc > 1) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // argv[0] is number of repeats, default 500
    int repeat = atoi(argv[0]);
    if (repeat == 0) {
        repeat = 5;
    }
    cout << "The Value of repeat is " << repeat;
    cout << endl;

    // repeat generating one message
    for(int i = 0; i < repeat; i ++) {
        // create the local file
        string fileName = "files/message" + to_string(i) + ".txt";
        cout << "Current file: " << fileName;
        cout << endl;
        char* charFileName = &fileName[0];

        // generate a new message
        TopMessage message;
        generateOne(&message);

        // save the new message in the created file
        ofstream messageFile;
        messageFile.open(fileName, ios::out | ios::binary);
        string serializedMessage;
        message.SerializeToString(&serializedMessage);
        messageFile << serializedMessage;
        messageFile.close();
    }

    return 0;
}
