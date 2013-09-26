
function	ClientPool() {
	this.clients = [];
}

ClientPool.prototype.push = function (elm) {
	this.clients.push(elm);
};

ClientPool.prototype.sendToClient = function (id, data) {
	for (var i = 0; i < this.clients.length; i++) {
		if (this.clients[i].type == "IA" && this.clients[i].id == id) {
			this.clients[i].server_tcp_sock.write(data);
			break;
		}
	}
};

exports.ClientPool = ClientPool;
