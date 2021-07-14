import subprocess
import os
import sys

dataGen = "F"
repeats = "5"
path = "messages.txt"

# argv[1] is whether to write a new file or not, default "F" (no), "T" if yes
# argv[2] is number of messages, default 5
# argv[3] is path of file, default messages.txt

if len(sys.argv) > 1:
    dataGen = sys.argv[1]
if len(sys.argv) > 2:
    repeats = sys.argv[2]
if len(sys.argv) > 3:
    path = sys.argv[3]

if dataGen == "T":
    p0 = subprocess.Popen(["./pb_writer", repeats, path], cwd = "protobuf_practice")
    p0.wait()

p1 = subprocess.Popen(["./static_reader", repeats, path], cwd = "protobuf_practice")
p1.wait()
p2 = subprocess.Popen(["./dynamic_reader", "../../lib/protolib/crestmessage.proto", os.path.join("../protobuf_practice", path), "CrestMessage", repeats], cwd = "protobuf_noProto")
p2.wait()
p3 = subprocess.Popen(["node", "nodejs_reader.js", "../../lib/protolib/crestmessage.proto", os.path.join("../protobuf_practice", path), "CrestMessage", repeats], cwd = "protobuf_noProto")
p3.wait()