#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../dst/topmessage.pb.h"
using namespace std;

// print the information of the given message
void readMessage(TopMessage* message) {
    cout << "Message ID :" << message -> id() << endl;
    cout << "Message val: " << message -> val() << endl;
    cout << "Message name: " << message -> name() << endl;
    cout << "Message checked: " << message -> checked() << endl;
}

// This function checks if a file exists
bool fileExists(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

// Main function: generate deserialze the messages and print them
// compile cmd: g++ -o pb_reader pb_reader.cc ../dst/topmessage.pb.cc -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc > 3) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // argv[1] is number of repeats, default 5
    // argv[2] is the path of folder for messages, default ../files/messageX.txt
    int repeat = 5;
    string path = "files";
    
    if (argc > 1 and atoi(argv[1]) > 0) {
        repeat = atoi(argv[1]);
    }
    cout << "The Value of repeat is " << repeat << endl;

    if (argc > 2 and *argv[2]) {
        path = argv[2];
    }
    if (!fileExists(&path[0])) {
        cerr << "File does not exist." << endl;
        return -1;
    }
    cout << "The path for messages is " << path << endl;

    // repeat generating one message
    for(int i = 0; i < repeat; i ++) {
        // check the local file, return error if not exist
        string fileName = path + "/message" + to_string(i) + ".txt";
        cout << "Current file: " << fileName;
        cout << endl;
        char* charFileName = &fileName[0];
        if (!fileExists(charFileName)) {
            cerr << "File does not exist." << endl;
            return -1;
        }
        TopMessage message;

        // deserialize and read the message
        ifstream messageFile;
        messageFile.open(fileName, ios::in | ios::binary);
        string serializedMessage;
        messageFile >> serializedMessage;
        message.ParseFromString(serializedMessage);
        readMessage(&message);
        messageFile.close();
    }

    return 0;
}
