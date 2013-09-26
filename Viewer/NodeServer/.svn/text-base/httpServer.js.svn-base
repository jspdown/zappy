
//==========================
// IMPORT MODULE : le server http
//==========================

var http = require('http');

//==========================
// SERVER : creation du server
//==========================

function	start(route, port) {
	function	onRequest(req, res) {
		route(req.url, res);
	}
	http.createServer(onRequest).listen(port);
	console.log("[INFO]:\tSERVER RUNING ON PORT " + port);
}

//==========================
// EXPORT MODULE : export de la fonction start
//==========================

exports.start = start;
