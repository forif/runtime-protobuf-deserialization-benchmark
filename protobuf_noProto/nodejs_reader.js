const protobuf = require("protobufjs");
const fs = require("fs");
const util = require('util');
const { toNamespacedPath } = require("path");

// argv[2] is the path of given .proto file that contains the protobuf definition
// argv[3] is the path of serialized file that will needs to be deserialized
// argv[4] is the name of the message in the serialized file
// argv[5] is the number of repeats
var proto_path = "../../lib/protolib/crestmessage.proto";
var file_path = "../protobuf_practice/messages.txt";
var message_name = "CrestMessage";
var repeats = 500;

if (process.argv.length > 2) proto_path = process.argv[2];
if (process.argv.length > 3) file_path = process.argv[3];
if (process.argv.length > 4) message_name = process.argv[4];
if (process.argv.length > 5) repeats = process.argv[5];


protobuf.load(proto_path, function (err, root) {
	if (err) throw err;

	// open the file
	fs.open(file_path, 'r+', async function (err, fd) {
		if (err) {
			return console.error(err);
		}

		// read the file
		// set up variables, i is index of messages, pos is current position in the file
		var pos = 0;
		var i = 0;
		var totalTime = 0;
		var totalBytes = 0;

		// create a promise version of fs.read()
		fs.readAsync = util.promisify(fs.read);

		// a function that reads the size of message (4 bytes)
		async function read_size () {
			var sizeBuffer = new Buffer.alloc(4);
			var size = 0;
			await fs.readAsync(fd, sizeBuffer, 0, 4, pos).then(data => {
				// console.log(data);
				size = parseInt(sizeBuffer.slice(0, data['bytesRead']).toString());
				pos += 4;
			});

			return size;
		}

		// a function that reads the message
		async function read_message (size) {
			var buffer = new Buffer.alloc(size);
			await fs.readAsync(fd, buffer, 0, size, pos).then(data => {
				pos += size;
				i += 1;

				// keep track of time and bytes taken by decoding the array to message and converting it to json object
				var hrstart = process.hrtime()
				let msg = message.decode(buffer);
				var hrend = process.hrtime(hrstart);
				totalTime = totalTime + hrend[0] + hrend[1] / 1000000000; // hrend[0] is sec, hrend[1] is nanosec
				totalBytes += size;

				// print out the deserialized message
				// let object = message.toObject(msg, {
				// 	longs: String,
				// 	enums: String,
				// 	bytes: String,
				// });
				// console.log("object", object);
			});
		}

		// a function that reads the size and then the content of the message
		async function read_whole () {
			// await console.log(i + "th file");

			message_size = await read_size();
			await read_message(message_size);
		}

		// repeat reading for the given number of times
		const message = root.lookupType(message_name);
		for (let i = 0; i < repeats; i ++) {
			await read_whole();
		}

		// print results
		console.log("Performance of Nodejs dynamic reader:");
		console.log("Number of messages processed per second: " + repeats / totalTime);
		console.log("Number of bytes processed per second: " + totalBytes / totalTime);
	});
});