#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../protolib/test/topmessage.pb.h"
#include "../protolib/crestmessage.pb.h"
using namespace std;
using namespace google::protobuf;

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
    message -> set_id(rand());
    message -> set_name(1, generateRandomString());
    message -> set_name(2, generateRandomString());

    cout << "Message ID: " << message -> id() << endl;
    cout << "Message name 1: " << message -> name(1) << endl;
    cout << "Message name 2: " << message -> name(2) << endl;

    int r = rand() % 10 + 5;
    for (int i = 0; i < r; i ++) {
        (*message->mutable_hash())[rand()] = generateRandomString();
    }
    
    // std::map<int32, string> standard_map(message.weight().begin(), message.weight().end());
    for(auto elem : message->hash()) {
        std::cout << elem.first << " " << elem.second << endl;
    }

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

    cout << "Message fruit enum: " << message -> fruit() << endl;
    cout << "Message oneof red: " << message -> red() << endl;
    cout << "Message oneof blue: " << message -> blue() << endl;

    TopMessage* top;
    generateTop(top);
    message -> set_allocated_topm(top);

    NestMessage* nest;
    generateNest(nest);
    message -> set_allocated_nestm(nest);
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
