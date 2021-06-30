#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../../lib/protolib/test/topmessage.pb.h"
#include "../../lib/protolib/crestmessage.pb.h"
using namespace std;
using namespace google::protobuf;

// This function generates a random string with length [1,100]
string generateRandomString() {
    size_t length = rand() % 100 + 1;
    const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t charmapLength = strlen(charmap);
    auto generator = [&](){ return charmap[rand()%charmapLength]; };
    string result;
    result.reserve(length);
    generate_n(back_inserter(result), length, generator);
    result += "\0";
    return result;
}

// This function fills a TopMessage with random values for each field
void generateTop(TopMessage* message) {
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

void generateNest(NestMessage* message) {
    message -> set_id(rand());
    message -> set_name(generateRandomString());

    cout << "Message ID: " << message -> id() << endl;
    cout << "Message name: " << message -> name() << endl;
}

void generateCrest(CrestMessage* message) {
    // cout << "CrestMessage:" << endl;
    message -> set_id(rand());
    // cout << "Message ID: " << message -> id() << endl;

    message -> add_name(generateRandomString());
    message -> add_name(generateRandomString());
    // cout << "Message name 1: " << message -> name(0) << endl;
    // cout << "Message name 2: " << message -> name(1) << endl;

    int r = rand() % 10 + 5;
    for (int i = 0; i < r; i ++) {
        (*message->mutable_hash())[i] = generateRandomString();
    }
    
    // std::map<int32, string> standard_map(message.weight().begin(), message.weight().end());
    // int count = 0;
    // for(auto elem : message->hash()) {
    //     std::cout << "map element " << count << ": " << elem.first << " " << elem.second << endl;
    //     count++;
    // }

    int f = rand() % 6;
    switch (f) {
        case 0: message -> set_fruit(CrestMessage::APPLE); break;
        case 1: message -> set_fruit(CrestMessage::PEAR); break;
        case 2: message -> set_fruit(CrestMessage::PEACH); break;
        case 3: message -> set_fruit(CrestMessage::BANANA); break;
        case 4: message -> set_fruit(CrestMessage::STRAWBERRY); break;
        case 5: message -> set_fruit(CrestMessage::CHOCOLATE); break;
    }

    int c = rand() % 2;
    switch (c) {
        case 0: message -> set_red(true); break;
        case 1: message -> set_blue(true); break;
    }

    // cout << "Message fruit enum: " << message -> fruit() << endl;
    // cout << "Message oneof red: " << message -> red() << endl;
    // cout << "Message oneof blue: " << message -> blue() << endl;

    // cout << "TopMessage:" << endl;
    message -> mutable_topm() -> set_id(rand());
    message -> mutable_topm() -> set_name(generateRandomString());
    message -> mutable_topm() -> set_val(((double) rand() / (double) RAND_MAX));
    message -> mutable_topm() -> set_checked(rand() % 2 == 0);
    // cout << "Message id: " << message -> topm().id() << endl;
    // cout << "Message name: " << message -> topm().name() << endl;
    // cout << "Message val: " << message -> topm().val() << endl;
    // cout << "Message checked: " << message -> topm().checked() << endl;

    // cout << "NestMessage:" << endl;
    message -> mutable_nestm() -> set_id(rand());
    message -> mutable_nestm() -> set_name(generateRandomString());
    // cout << "Message id: " << message -> nestm().id() << endl;
    // cout << "Message name: " << message -> nestm().name() << endl;

    // cout << "CrestMessage size: " << message -> ByteSizeLong() << endl;
}

// This function checks if a file exists
bool fileExists(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

// Main function: generate a # (specified by user) of messages and serialize them
// compile cmd: g++ -o pb_writer pb_writer.cc ../../lib/protolib/test/topmessage.pb.cc ../../lib/protolib/crestmessage.pb.cc -I ../../lib/protolib/ -lprotobuf
int main(int argc, char* argv[]) {
    // GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc > 3) {
        cerr << "Too many arguments." << endl;
        return -1;
    }

    // argv[1] is number of repeats, default 5
    // argv[2] is the path of folder for messages, default ../messages.txt
    int repeat = 5;
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
        CrestMessage message;
        generateCrest(&message);
        // cout << "Message generation ends" << endl;

        // serialize and save the new message and its size in the file
        // cout << "Serialization begins" << endl;
        string serializedMessage;
        message.SerializeToString(&serializedMessage);
        // cout << "Serialization ends" << endl;

        const char* buffer = serializedMessage.data();
        int size = serializedMessage.size();
        // cout << "Message size: " << size << endl;
        messageFile.write(to_string(size).c_str(), 4);
        messageFile.write(buffer, size);
    }

    // close the file
    messageFile.close();
    return 0;
}
