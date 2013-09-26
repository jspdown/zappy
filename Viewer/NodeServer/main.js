
var server = require('./server.js');
var httpServer = require('./httpServer');
var router = require('./router.js');

server.Server(4141, "172.16.138.128");
httpServer.start(router.route, 80);