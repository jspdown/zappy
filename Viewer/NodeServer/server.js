
var io = require('socket.io');
var net = require('net');
var http = require('http');
var client = require('./client.js');
var cp = require('./client_pool.js');

//============================
// CLIENTS POOL
//============================

var	client_pool = new cp.ClientPool();

//============================
// SERVER: bridge between C-server and ClientUI, IA
//============================

function	Server(port, host) {
	//new graphical user (over websocket)
	var serv = io.listen(8000);
	serv.set('log level', 1);
	serv.sockets.on('connection', function (web_sock) {
		console.log("connected");
		var cl = new client.GraphicalClient(port, host, web_sock, client_pool);
		client_pool.push(cl);
	});
	//new ia user (over tcp)
	net.createServer(function (sock) {
		var cl = new client.IaClient(port, host, sock);
		client_pool.push(cl);
	});
}

exports.Server = Server;