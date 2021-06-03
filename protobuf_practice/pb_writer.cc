#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../dst/topmessage.pb.h"
using namespace std;

// This function generates a random string with length [1,100]
string generateRandomString() {
    size_t length = rand() % 100 + 1;
    const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
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
    message -> set_val(((double) rand() / (double) RAND_MAX));
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
    // argv[2] is the path of folder for messages, default ../messages.txt
    int repeat = 1;
    string path = "messages.txt";
    
    if (argc > 1 and atoi(argv[1]) > 0) {
        repeat = atoi(argv[1]);
    }
    // cout << "The Value of repeat is " << repeat << endl;

    if (argc > 2 and *argv[2]) {
        path = argv[2];
    }
    // if (!fileExists(&path[0])) {
    //     cerr << "File does not exist." << endl;
    //     return -1;
    // }
    // cout << "The path for messages is " << path << endl;

    // open the file saving messages
    ofstream messageFile;
    messageFile.open(path, ios::out | ios::binary);

    // repeat generating one message
    for(int i = 0; i < repeat; i ++) {
        cout << "Current message #: " << i << endl;

        // generate a new message
        TopMessage message;
        generateOne(&message);

        // serialize and save the new message and its size in the file
        string serializedMessage;
        message.SerializeToString(&serializedMessage);

        const char* buffer = serializedMessage.data();
        int size = serializedMessage.size();
        cout << "Message size: " << size << endl;
        messageFile.write(to_string(size).c_str(), 4);
        messageFile.write(buffer, size);
    }

    // close the file
    messageFile.close();
    return 0;
}
