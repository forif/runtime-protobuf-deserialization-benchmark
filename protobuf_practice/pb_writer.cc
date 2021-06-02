#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../dst/topmessage.pb.h"
using namespace std;

// This function generates a random string
string generateRandomString() {
    size_t length = sizeof(string);
    const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t charmapLength = strlen(charmap);
    auto generator = [&](){ return charmap[rand()%charmapLength]; };
    string result;
    result.reserve(length);
    generate_n(back_inserter(result), length, generator);
    return result;
}

// This function fills a TopMessage with random values for each field
void generateOne(TopMessage* message) {
    message -> set_id(rand());
    message -> set_val(((double)rand()/(double)RAND_MAX));
    message -> set_name(generateRandomString());
    message -> set_checked(rand() % 2 == 0);

    // print out all values for checking
    cout << "Message ID: " << message -> id() << endl;
    cout << "Message val: " << message -> val() << endl;
    cout << "Message name: " << message -> name() << endl;
    cout << "Message checked: " << message -> checked() << endl;
}

// This function checks if a file exists
bool fileExists(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

// Main function: generate a # (specified by user) of messages and serialize them
// compile cmd: g++ -o pb_writer pb_writer.cc ../dst/topmessage.pb.cc -lprotobuf
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
        // create the local file
        string fileName = path + "/message" + to_string(i) + ".txt";
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
