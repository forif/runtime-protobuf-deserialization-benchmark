#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../dst/topmessage.pb.h"
using namespace std;

// print the information of the given message
void readMessage(TopMessage* message) {
    cout << "Message ID:" << message -> id() << endl;
}

// Main function: generate deserialze the messages and print them
// compile cmd: g++ -o pb_reader pb_reader.cc ../dst/topmessage.pb.cc -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    int repeat = 5;

    // repeat generating one message
    for(int i = 0; i < repeat; i ++) {
        // create the local file
        string fileName = "files/message" + to_string(i) + ".txt";
        cout << "Current file: " << fileName;
        cout << endl;
        char* charFileName = &fileName[0];
        TopMessage message;

        ifstream messageFile;
        messageFile.open(fileName, ios::in | ios::binary);
        int messageSize;
        string serializedMessage;
        messageFile >> serializedMessage;
        message.ParseFromString(serializedMessage);
        cout << "Message ID:" << message.id() << endl;
        messageFile.close();
    }

    return 0;
}
