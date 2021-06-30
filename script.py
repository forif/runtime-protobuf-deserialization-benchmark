import subprocess
# subprocess.run(['/protobuf_practice/static_reader', '10000', 'messages.txt'])
subprocess.run(["./static_reader", "10000", "messages.txt"], cwd = "protobuf_practice")
subprocess.run(["./dynamic_reader", "../../lib/protolib/crestmessage.proto", "../protobuf_practice/messages.txt", "CrestMessage", "10000"], cwd = "protobuf_noProto")