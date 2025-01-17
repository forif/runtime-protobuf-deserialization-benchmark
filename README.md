# protocol buffer deserialization performance testing, comparison between static and dynamic parsing

1. ./install_protobuf_locally.sh
2. setup nodejs runtime environment
3. install python 3.6 or above
4. LD_LIBRARY_PATH=protobuf-3.12.2/installed/lib/ python3 script.py

example output:
```bash
>>>>>>>>>>>>>>>> total 100000 messages in /home/dev/pb_test/msgs.pbbin
Performance of c++ static reader: 2.057s/2.270s
Number of messages processed per second: 48625
Number of bytes processed per second: 38.131M
>>>>>>>>>>>>>>>> total 100000 messages in /home/dev/pb_test/msgs.pbbin
Performance of c++ dynamic reader: 2.965s/3.347s
Number of messages processed per second: 33728
Number of bytes processed per second: 26.449M
>>>>>>>>>>>>>>>> total 100000 messages in file /home/dev/pb_test/msgs.pbbin
Performance of Nodejs dynamic reader: 1.313s/2.486s
Number of messages processed per second: 76134
Number of bytes processed per second: 59.703M
```

## program argument inputs:
1. pb_writer\
   argv[1] is number of repeats, default 100000\
   argv[2] is the path of folder for messages, default msgs.pbbin
2. static_reader\
   argv[1] is the path of folder for messages, default msgs.pbbin
3. dynamic_reader\
   argv[1] is the path of given .proto file that contains the protobuf definition, default "msgs/crestmessage.proto"\
   argv[2] is the path of serialized file that will needs to be deserialized, default "msgs.pbbin"\
   argv[3] is the name of the message in the serialized file, default "CrestMessage"
4. script.py\
   argv[1] is the number of messages been generated, default 100000
