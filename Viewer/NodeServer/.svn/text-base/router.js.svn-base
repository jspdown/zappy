
//==========================
// IMPORT MODULE : charge les modules necessaire
//==========================

var url = require('url');
var qs = require('querystring');
var path = require('path');
var fs = require('fs');

var handle = [];
handle["/"] = '../GraphicalClient/index.html';
handle["/css/style.css"] = '../GraphicalClient/css/style.css';
handle["/css/bootstrap.min.css"] = '../GraphicalClient/css/bootstrap.min.css';
handle["/lib/zappyGraphicalAPI.js"] = '../GraphicalClient/lib/zappyGraphicalAPI.js';
handle["/lib/kinetic.min.js"] = '../GraphicalClient/lib/kinetic.min.js';
handle["/js/utils.js"] = '../GraphicalClient/js/utils.js';
handle["/js/loader.js"] = '../GraphicalClient/js/loader.js';
handle["/js/player.js"] = '../GraphicalClient/js/player.js';
handle["/js/map.js"] = '../GraphicalClient/js/map.js';
handle["/assets/tile.png"] = '../GraphicalClient/assets/tile.png';
handle["/assets/bg.jpg"] = '../GraphicalClient/assets/bg.jpg';
handle["/assets/food.png"] = '../GraphicalClient/assets/food.png';
handle["/assets/rock1.png"] = '../GraphicalClient/assets/rock1.png';
handle["/assets/rock2.png"] = '../GraphicalClient/assets/rock2.png';
handle["/assets/rock3.png"] = '../GraphicalClient/assets/rock3.png';
handle["/assets/rock4.png"] = '../GraphicalClient/assets/rock4.png';
handle["/assets/rock5.png"] = '../GraphicalClient/assets/rock5.png';
handle["/assets/rock6.png"] = '../GraphicalClient/assets/rock6.png';
handle["/assets/icon_food.png"] = '../GraphicalClient/assets/icon_food.png';
handle["/assets/icon_rock1.png"] = '../GraphicalClient/assets/icon_rock1.png';
handle["/assets/icon_rock2.png"] = '../GraphicalClient/assets/icon_rock2.png';
handle["/assets/icon_rock3.png"] = '../GraphicalClient/assets/icon_rock3.png';
handle["/assets/icon_rock4.png"] = '../GraphicalClient/assets/icon_rock4.png';
handle["/assets/icon_rock5.png"] = '../GraphicalClient/assets/icon_rock5.png';
handle["/assets/icon_rock6.png"] = '../GraphicalClient/assets/icon_rock6.png';
handle["/assets/color.png"] = '../GraphicalClient/assets/color.png';
handle["/assets/sprite_selected.png"] = '../GraphicalClient/assets/sprite_selected.png';
handle["/assets/eggs.png"] = '../GraphicalClient/assets/egg.png';
handle["/assets/incante1.png"] = '../GraphicalClient/assets/incante1.png';
handle["/assets/incante2.png"] = '../GraphicalClient/assets/incante2.png';
handle["/assets/incante3.png"] = '../GraphicalClient/assets/incante3.png';
handle["/assets/incante4.png"] = '../GraphicalClient/assets/incante4.png';
handle["/assets/incante5.png"] = '../GraphicalClient/assets/incante5.png';
handle["/assets/incante6.png"] = '../GraphicalClient/assets/incante6.png';
handle["/assets/incante7.png"] = '../GraphicalClient/assets/incante7.png';
handle["/assets/incante8.png"] = '../GraphicalClient/assets/incante8.png';
handle["/favicon.ico"] = '../GraphicalClient/assets/favicon.ico';
handle["/lib/pixastic.custom.js"] = '../GraphicalClient/lib/pixastic.custom.js';
handle["/assets/sprite0.png"] = '../GraphicalClient/assets/sprite0.png';
handle["/assets/sprite1.png"] = '../GraphicalClient/assets/sprite1.png';
handle["/assets/sprite2.png"] = '../GraphicalClient/assets/sprite2.png';
handle["/assets/sprite3.png"] = '../GraphicalClient/assets/sprite3.png';
handle["/assets/sprite4.png"] = '../GraphicalClient/assets/sprite4.png';
handle["/assets/sprite5.png"] = '../GraphicalClient/assets/sprite5.png';
handle["/assets/sprite6.png"] = '../GraphicalClient/assets/sprite6.png';
handle["/assets/sprite7.png"] = '../GraphicalClient/assets/sprite7.png';
handle["/assets/tile_selected.png"] = '../GraphicalClient/assets/tile_selected.png';





//==========================
// SEND FILE : recupere le fichier et l'envoi a travers le pipe
//==========================

function	sendFile(file, out) {
	var filePath = path.join(__dirname, file);
		console.log(filePath);
	try {
	    var fileStream = fs.createReadStream(filePath);
	    fileStream.pipe(out);
    }
    catch (err) {
    	console.log("unknow file: " + filePath);
	}
}

//==========================
// RESSOURCES REQUEST : envoyer une ressource (html, css, ...)
//==========================

function	requestRessources(pathname, string, res) {
	sendFile(pathname, res);
}

//==========================
// ROUTER : dispatch les requetes
//==========================

function	route(string, res) {
	var pathname = url.parse(string).pathname;
	try {
		console.log(pathname);
		
		if (pathname.search("/assets/tile/") == 0) {
			console.log("in if");
			requestRessources("../GraphicalClient" + pathname, string, res);
		}
		else
			requestRessources(handle[pathname], string, res);
	}
	catch (err) {
		console.log("[ERROR] : Unknow " + pathname);
	}
}

//==========================
// EXPORTE MODULE : export de la fonction route
//==========================

exports.route = route;