
var net = require('net');

//============================
// CONNECTION STEP
//============================

function	connection(client, from, data) {
	if (from == "SERVER") {
		if (client.connected === false && data == "BIENVENUE") {
			client.connected = true;
		}
		else if (client.type == "IA" && client.id === undefined)
			client.id = data;
	}
	else if (from == "CLIENT" && client.type == "IA" && client.team === undefined)
		client.team = data;
}

//============================
// CHUNK: remove \n
//============================

function	chunk(string) {
	return (string.replace("\n", ""));
}
	
//============================
// CLIENT BASE CLASS
//============================

function	Client(host, port) {
	this.host = host;
	this.port = port;
	this.connected = false;
}

//============================
// GRAPHICAL CLIENT CLASS: inherit from Client
//============================

function	GraphicalClient(host, port, web_sock, client_pool) {
	Client.call(this, host, port);
	
	var _this = this;
	
	this.server_tcp_sock = net.connect(4141, "172.16.138.128");
	
	this.type = "GRAPHIC";
	this.web_sock = web_sock;
	this.client_pool = client_pool;
	
	this.server_tcp_sock.on('data', function (data) {
		var content = chunk(data.toString());
		connection(_this, "SERVER", content);
		var trs = data.toString().split("\n");
		for (var i = 0; i < trs.length; i++) {
			if (trs[i] != "") {
				console.log("[RECEIVED] : " + trs[i]);
				_this.web_sock.emit('commands', trs[i]);
			}
		}
	});
	this.web_sock.on('commands', function (data) {
		_this.server_tcp_sock.write(data);
	});
	this.web_sock.on('rts', function (data) {
		var content = chunk(data);
		var res = _this.play(content);
		if (res !== null)
			_this.server_tcp_sock.write(res);
	});
}

GraphicalClient.prototype = new Client();
GraphicalClient.prototype.constructor = GraphicalClient;

GraphicalClient.prototype.play = function (data) {
	var tr = data.name + " " + data.args;
	this.client_pool.sendToClient(data.client_id, tr);
};

//============================
// IA CLIENT CLASS: inherit from Client
//============================

function	IaClient(host, port, input_tcp_sock) {
	Client.call(this, host, port);
	
	var	_this = this;
	
	this.server_tcp_sock = net.connect(4141, "172.16.138.128");
	
	this.type = "IA";
	this.id = undefined;
	this.team = undefined;
	this.client_tcp_sock = input_tcp_sock;
	
	this.server_tcp_sock.on('data', function (data) {
		var content = chunk(data);
		connection(_this, "SERVER", content);
		_this.client_tcp_sock.write(content);
	});
	this.client_tcp_sock.on('data', function (data) {
		var content = chunk(data);
		connection(_this, "CLIENT", content);
		_this.server_tcp_sock.write(content);
	});
}

IaClient.prototype = new Client(); 
IaClient.prototype.constructor = IaClient;

//============================
// EXPORT MODULE
//============================

exports.GraphicalClient = GraphicalClient;
exports.IaClient = IaClient;