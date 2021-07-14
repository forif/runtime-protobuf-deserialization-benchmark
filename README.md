# protocol buffer write and read, comparison between static and dynamic reading

program argument inputs:
1. pb_writer\
   argv[1] is number of repeats, default 5\
   argv[2] is the path of folder for messages, default messages.txt
2. static_reader\
   argv[1] is number of repeats, default 5\
   argv[2] is the path of folder for messages, default messages.txt
3. dynamic_reader\
   argv[1] is the path of given .proto file that contains the protobuf definition, default "../../lib/protolib/crestmessage.proto"\
   argv[2] is the path of serialized file that will needs to be deserialized, default "../protobuf_practice/messages.txt"\
   argv[3] is the name of the message in the serialized file, default "CrestMessage"\
   argv[4] is the number of repeats，default 5
4. script.py\
   argv[1] is whether to write a new file or not, default "F" (no), "T" if yes\
   argv[2] is number of messages, default 5\
   argv[3] is path of file, default "messages.txt"
