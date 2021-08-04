#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "crestmessage.pb.h"
#include "test/topmessage.pb.h"


using namespace std;
using namespace google::protobuf;


// This function generates a random string with length [1,100]
string generateRandomString() {
    size_t length = rand() % 100 + 1;
    const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t charmapLength = strlen(charmap);
    auto generator = [&](){ return charmap[rand()%charmapLength]; };
    string result;
    result.reserve(length + 1);
    generate_n(back_inserter(result), length, generator);
    //result.push_back('\0');
    return result;
}


void generateCrest(CrestMessage* message) {
    message -> set_id(rand());

    message -> add_name(generateRandomString());
    message -> add_name(generateRandomString());

    int r = rand() % 10 + 5;
    for (int i = 0; i < r; i ++) {
        (*message->mutable_hash())[i] = generateRandomString();
    }
    
    int f = rand() % 6;
    message -> set_fruit(static_cast<CrestMessage::EnumFruits>(f));

    int c = rand() % 2;
    switch (c) {
        case 0: message -> set_red(true); break;
        case 1: message -> set_blue(true); break;
    }

    message -> mutable_topm() -> set_id(rand());
    message -> mutable_topm() -> set_name(generateRandomString());
    message -> mutable_topm() -> set_val(((double) rand() / (double) RAND_MAX));
    message -> mutable_topm() -> set_checked(rand() % 2 == 0);

    message -> mutable_nestm() -> set_id(rand());
    message -> mutable_nestm() -> set_name(generateRandomString());
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
    // argv[2] is the path of folder for messages, default messages.txt
    int repeat = 100000;
    string path = "msgs.pbbin";
    
    if (argc > 1 && atoi(argv[1]) > 0) {
        repeat = atoi(argv[1]);
    }

    if (argc > 2) {
        path = argv[2];
    }

    // open the file saving messages
    ofstream messageFile;
    messageFile.open(path, ios::out | ios::binary);
    messageFile.write(reinterpret_cast<char*>(&repeat), sizeof(int));

    // repeat generating one message
    string serializedMessage;
    for(int i = 0; i < repeat; i ++) {
        // generate a new message
        CrestMessage message;
        generateCrest(&message);

        // serialize and save the new message and its size in the file
        message.SerializeToString(&serializedMessage);

        size_t sz = serializedMessage.size();
        messageFile.write(reinterpret_cast<char*>(&sz), sizeof(size_t));
        messageFile.write(serializedMessage.data(), sz);
    }

    // close the file
    messageFile.close();
    return 0;
}
