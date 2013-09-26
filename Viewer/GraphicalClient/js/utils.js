
var tileSize = {x: 128 / 2.0, y: 64 / 2.0, offset: 15 / 2.0};
var incanteSize = {x: 64, y: 75, offset: 50};
var loader = new Loader();
var map_offset = {x: 0, y: 0};

///////////////////////////////
//	Tools: set n' config
///////////////////////////////

var move_accurency = 40;
var scale_lvl = 1;
function	moveLeft(father, args) {
	father.map.move({x: -move_accurency, y: -move_accurency / 2.0});
}

function	moveRight(father, args) {
	father.map.move({x: move_accurency, y: move_accurency / 2.0});
}

function	moveTop(father, args) {
	father.map.move({x: move_accurency, y: -move_accurency / 2.0});
}

function	moveBottom(father, args) {
	father.map.move({x: -move_accurency, y: move_accurency / 2.0});
}


////////////////////////////////
// Eggs
/////////////////////////////////

function	EggsHandler(map, sheet) {
	this.sheet = sheet;
	this.eggs = [];
	this.map = map;
}

EggsHandler.prototype.addEggs = function (pos, id, pl_id) {
	var rel_pos = convertCoordToIso(pos, tileSize, true, sprite_rect[0]);
	var el = new Kinetic.Sprite({
		x:	rel_pos.x,
		y:	rel_pos.y,
		width:	32,
		height:	48,
		image: this.sheet,
		animation:	'eggs',
		animations:	sprites,
		frameRate:	5,
		index: 0
	});
	this.eggs.push({'id': id, 'player_id': pl_id, 'sprite': el, 'pos': rel_pos});
	return (el);
};

EggsHandler.prototype.eclosion = function (pl_team, id, pl_pos, pl_direction) {
	var _this = this;
	for (var i = 0; i < this.eggs.length; i++) {
		if (this.eggs[i].id == id) {
			this.eggs[i].sprite.start();
			this.eggs[i].sprite.afterFrame(3, function(idx) {
				return (function () {
					for (var u = 0; u < _this.eggs.length; u++) {
						if (_this.eggs[u].id == id) {
							_this.eggs[u].sprite.stop();
							_this.eggs[u].sprite.hide();
							_this.eggs.splice(u, 1);
						}
					}
					
				});
			}(id));
			break;
		}
	}
	this.map.addPlayer(pl_team, id, pl_pos, pl_direction);
}

////////////////////////////////
// Incante
/////////////////////////////////

function	IncanteHandler(map, sheet) {
	this.sheet = sheet;
	this.incantation = [];
	this.map = map;
	this.tell = [];
}

IncanteHandler.prototype.addIncante = function (pos, lvl) {
	console.log(lvl);
	var rel_pos = convertCoordToIso(pos, tileSize, true, sprite_rect[0]);
	var el = new Kinetic.Sprite({
		x:	rel_pos.x - 15,
		y:	rel_pos.y - 5,
		width:	tileSize.x,
		height:	tileSize.y,
		image: this.sheet["assets/incante" + lvl + ".png"],
		animation:	'incante',
		animations:	sprites,
		frameRate:	5,
		index: 0
	});
	this.incantation.push({'pos': pos, 'sprite': el, 'pos': rel_pos});
	var _this = this;
	el.afterFrame(3, function() {
		for (var i = 0; i < _this.incantation.length; i++) {
			if (_this.incantation[i].sprite == el) {
				_this.incantation[i].sprite.stop();
				_this.incantation[i].sprite.hide();
				_this.incantation.splice(i, 1);
			}
		}
	});
	return (el);
};

///////////////////////////////
// EventHandler: manage internal event (resize...)
///////////////////////////////


var event_queue = [];

var handleEvent = {
	'moveLeft':		moveLeft,
	'moveRight':	moveRight,
	'moveTop':		moveTop,
	'moveBottom':	moveBottom,
};

function	EventManager(father, refresh) {
	this.refresh = refresh;
	this.queue = [];
	var _this = this;
	setInterval(function () {
		while (_this.queue.length > 0) {
			var op = _this.queue.pop();
			try {
				handleEvent[op.name](father, op.args);
			}
			catch (err) {
				console.log("[Error]: unknown Event");
			}
		}
	}, refresh);
}

EventManager.prototype.addEvent = function (name, args) {
	this.queue.push({'name': name, 'args': args});
};


function	convertCoordToIso(pos, size, centred, size_pl) {
	var r = {};
	r.x = ((pos.x - pos.y) * size.x / 2.0);
    r.y = ((pos.x + pos.y) * size.y / 2.0);
    if (centred !== undefined && size_pl !== undefined) {
		r.x += size.x / 2.0 - size_pl.x / 2.0;
		r.y -= size.y /2.0 + size_pl.offset;
    }
    return (r);
}

//////////////////////////////////
// Class NavCircle
//////////////////////////////////

function	NavCircle(event_manager, pos, circle_radius) {
    var _this = this;
	this.shape = new Kinetic.Layer();
	this.buttons = new Kinetic.Group();
	this.circle = new Kinetic.Circle({
		x:			pos.x,
		y:			pos.y,
		radius:		circle_radius,
		fill:		'black',
		opacity:	0.3
	});
	this.quarter = [];
	var offset = 4;
	var border_offset = 4;
	var angle = [{
			x:	offset,
			y:	offset,
			a:	0,
			event: 'moveRight'
		},
		{
			x:	-offset,
			y:	offset,
			a:	90,
			event: 'moveBottom'
		},
		{
			x:	-offset,
			y:	-offset,
			a:	180,
			event: 'moveLeft'
		},
		{
			x:	offset,
			y:	-offset,
			a:	270,
			event: 'moveTop'
		}
	];
	for (var i = 0; i < 4; i++) {
		this.quarter[i] = new Kinetic.Wedge({
			x:				pos.x + angle[i].x,
			y:				pos.y + angle[i].y,
			radius:			circle_radius - 4 * border_offset,
			angleDeg:		90,
			fill:			'black',
			opacity:		0.5,
			rotationDeg:	angle[i].a
		});
		this.quarter[i].on('mouseover', function(idx) {
    		return (function () {
	    		_this.quarter[idx].setOpacity(0.2);
				_this.quarter[idx].setFill('white');
				_this.shape.draw();
    		});
		}(i));
		this.quarter[i].on('mouseout', function(idx) {
			return (function () {
				_this.quarter[idx].setOpacity(0.3);
				_this.quarter[idx].setFill('black');
				_this.shape.draw();				
			});
		}(i));
		this.quarter[i].on('mousedown', function(idx) {
			return (function () {
				event_manager.addEvent(angle[idx].event);
			});
		}(i));
	}
    this.shape.add(this.circle);

    for (var i = 0; i < 4; i++) {
    	this.shape.add(this.quarter[i]);
	}
}

NavCircle.prototype.draw = function (stage) {
	stage.add(this.circle);
  	stage.add(this.quarter[0]);
  	
  	var _this = this;
}

///////////////////////////////////////////
//	screen to map coord: using mouse position
///////////////////////////////////////////
/*
function	ReferenceTile(size) {
	this.quad = [];
	this.tri = [];
	this.set(size);
}

ReferenceTile.prototype.interTri = function (pt, id) {
	var sign = function (p1, p2, p3) {
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	};

	var b1, b2, b3;
	b1 = sign(pt, this.tri[id][0], this.tri[id][1]) < 0.0;
	b2 = sign(pt, this.tri[id][1], this.tri[id][2]) < 0.0;
	b3 = sign(pt, this.tri[id][2], this.tri[id][0]) < 0.0;
	
	return ((b1 == b2) && (b2 == b3));
};

ReferenceTile.prototype.where = function (pt) {
	var add_pos = {x: 0, y: 0};
	for (var i = 0; i < this.tri.length; i++) {
		if (this.interTri(pt, i))
			add_pos = n_pos[i];
	}
	return (add_pos);
};

ReferenceTile.prototype.getPos = function (pos) {
	
};

ReferenceTile.prototype.set = function (size) {
	this.size = size;
	this.n_pos = [
		{x: -1, y: 0},
		{x: 0, y: -1},
		{x: 1, y: 0},
		{x: 0, y: 1},
	];
	this.tri = [
		[
			{x: 0, y: 0},
			{x: size.x / 2.0, y: 0},
			{x: 0, y: size.y / 2.0},
		],
		[
			{x: size.x / 2.0, y: 0},
			{x: size.x, y: 0},
			{x: size.x, y: size.y / 2.0},
		],
		[
			{x: size.x, y: size.y / 2.0},
			{x: size.x, y: size.y},
			{x: size.x / 2.0, y: size.y},
		],
		[
			{x: size.x / 2.0, y: size.y},
			{x: 0, y: size.y},
			{x: 0, y: size.y / 2.0},
		]
	];
};
*/
////////////////////////////////////////////
// MessageBox: draw info during a moment.
////////////////////////////////////////////

function	MessageBoxHandler(father) {
	this.messages = [];
	this.father = father;
	this.shape = new Kinetic.Group();
	var _this = this;
	setInterval(function () {
		for (var i = 0; i < _this.messages.length; i++) {
			if (Date.now() - _this.messages[i].begin >= _this.messages[i].time)
				_this.removeMessage(i);
		}
	}, 100);
}

MessageBoxHandler.prototype.addMessage = function	(pos, title, msg, time, type) {
	var m = new MessageBox(pos, msg, type);
	this.shape.add(m.shape);
	this.messages.push({'begin': Date.now(), 'time': time, 'box': m});
	return (m.shape);
}

MessageBoxHandler.prototype.removeMessage = function (id) {
	this.messages[id].box.shape.remove();
	this.messages.splice(id, 1);
	this.father.move({x:0, y: 0});
}

function	MessageBox(pos, title, msg, type) {
	this.pos = pos;
	this.shape = new Kinetic.Group();
	
	var font_size = 12;
	var offset = 5;
	
	var size = {
		x:	(msg.length * font_size) / 2.0 + 2 * offset,
		y:	font_size + 2 * offset,
	};
	
	var txt_pos = {
		x:	this.pos.x + offset,
		y:	this.pos.y + offset
	};
	
	this.box = new Kinetic.Rect({
		x:	pos.x,
		y:	pos.y,
		width: size.x,
		height:	size.y,
		fill:	'black',
		cornerRadius:	10,
		opacity:	0.2,
		shadowColor: 'black',
        shadowBlur: 40,
        shadowOffset: 20,
        shadowOpacity: 1.0
	});
	this.msg = new Kinetic.Text({
		x:	txt_pos.x,
		y:	txt_pos.y,
		text: msg,
        fontSize: font_size,
        fontFamily: 'Calibri',
        fill: 'white'
	});
	this.shape.add(this.box);
	this.shape.add(this.msg);
}

////////////////////////////////////////
//  ContentWindow: show ressources and people on tile
////////////////////////////////////////

function	ContentWindow(images, pos) {
	this.pos = pos;
	this.font_size = 12;
	this.icon_size = {x:32, y:32};
	this.offset = 4;
	this.icon_offset = 2;
	this.nbr_offset = this.icon_size.x + 50;
	this.ressources = [
		{name: "Food", asset: "assets/icon_food.png", nbr: 0},
		{name: "Linemate", asset: "assets/icon_rock1.png", nbr: 0},
		{name: "Deraumere", asset: "assets/icon_rock2.png", nbr: 0},
		{name: "Sibur", asset: "assets/icon_rock3.png", nbr: 0},
		{name: "Mendiane", asset: "assets/icon_rock4.png", nbr: 0},
		{name: "Phiras", asset: "assets/icon_rock5.png", nbr: 0},
		{name: "Thystame", asset: "assets/icon_rock6.png", nbr: 0}
	];
	this.size = {
		x: 150,
		y: (this.icon_size.x + this.icon_offset) * this.ressources.length,
	};
	this.shape = new Kinetic.Layer();
	this.ressources_g = new Kinetic.Group();
	this.nbr_res = [];
	
	for (var i = 0; i < this.ressources.length; i++) {
		this.ressources_g.add(new Kinetic.Image({
			x: this.pos.x + this.offset,
			y: this.pos.y + this.offset + i * (this.icon_size.y + this.icon_offset),
			image:	images[this.ressources[i].asset],
			width:	this.icon_size.x,
			height:	this.icon_size.y
		}));
		this.ressources_g.add(new Kinetic.Text({
			x: this.pos.x + this.offset + this.icon_size.x + this.icon_offset,
			y: this.pos.y + this.offset + i * (this.icon_size.y + this.icon_offset),
			text:	this.ressources[i].name + ": ",
			fontSize: this.font_size,
			fontFamily: 'Calibri',
			fill:	'white'
		}));
		var txt = new Kinetic.Text({
			x: this.pos.x + this.offset + this.icon_size.x + this.icon_offset + this.nbr_offset,
			y: this.pos.y + this.offset + i * (this.icon_size.y + this.icon_offset),
			text:	this.ressources[i].nbr,
			fontSize: this.font_size,
			fontFamily: 'Calibri',
			fill:	'red'
		});
		this.ressources_g.add(txt);
		this.nbr_res[i] = txt;
	}
	this.box = new Kinetic.Rect({
		x:	pos.x,
		y:	pos.y,
		width:	this.size.x,
		height:	this.size.y,
		fill:	'black',
		cornerRadius:	10,
		opacity:	0.2,
		shadowColor: 'black',
        shadowBlur: 40,
        shadowOffset: 20,
        shadowOpacity: 1.0
	});
	this.shape.add(this.box);
	this.shape.add(this.ressources_g);
}

ContentWindow.prototype.setRessources = function (res) {
	console.log(res);
	for (var i = 0; i < this.ressources.length; i++) {
		this.nbr_res[i].setText(res[i]);
	}
	this.shape.draw();
}

////////////////////////////////////////
//  PlayerWindow
////////////////////////////////////////

function	PlayerWindow(map, images, pos) {
	var font_size = 12;
	this.images = images;
	this.map = map;
	var offset = 4;
	var icon_offset = 2;

	var size = {
		x: 150,
		y: 100
	};

	//image player
		
	var icon_size = {
		x:32, 
		y:48
	};
	var ico_player_pos = {
		x: pos.x + icon_offset,
		y: pos.y + icon_offset
	};
	this.ico_player = new Kinetic.Sprite({
		x:	ico_player_pos.x,
		y:  ico_player_pos.y,
		width:	icon_size.x,
		height:	icon_size.y,
		image:	images["assets/sprite0.png"],
		animation: 'idle_bottom',
		animations: sprites,
		frameRate: 5,
		index: 0
	});	
	//team
	var team_pos = {
		x:	ico_player_pos.x + icon_size.x + offset,
		y:	pos.y + icon_offset
	};
	this.team = new Kinetic.Text({
			x: team_pos.x,
			y: team_pos.y,
			text:	"Team: " + "Petit Poney!",
			fontSize: font_size,
			fontFamily: 'Calibri',
			fill:	'white'
	});
	//lvl
	var lvl_pos = {
		x:	ico_player_pos.x + icon_size.x + offset,
		y:	pos.y + icon_offset + font_size
	};
	this.lvl = new Kinetic.Text({
			x: lvl_pos.x,
			y: lvl_pos.y,
			text:	"Lvl: " + "1337",
			fontSize: font_size,
			fontFamily: 'Calibri',
			fill:	'white'
	});
	//pos
	var pos_pos = {
		x:	lvl_pos.x,
		y:	lvl_pos.y + font_size	
	};
	this.pos = new Kinetic.Text({
			x: pos_pos.x,
			y: pos_pos.y,
			text:	"Pos: " + "(X, Y)",
			fontSize: font_size,
			fontFamily: 'Calibri',
			fill:	'white'
	});

	//inventory
	
	//box
	this.left = new Kinetic.Polygon({
        points: [pos.x - offset, pos.y, 
        	pos.x - 4 * offset, pos.y + size.y / 2.0,
        	pos.x - offset, pos.y + size.y],
        fill: 'black',
        opacity: 0.2,
	});
	this.right = new Kinetic.Polygon({
        points: [pos.x + size.x + offset, pos.y, 
        	pos.x + size.x + 4 * offset, pos.y + size.y / 2.0,
        	pos.x + size.x + offset, pos.y + size.y],
        fill: 'black',
        opacity: 0.2,
      });
    var _this = this;
    this.right.on('mousedown', function() {
    	_this.nextPlayer();
	});
	this.left.on('mousedown', function() {
    	_this.prevPlayer();
	});
	this.left.on('mouseover', function() {
	   	_this.left.setOpacity(0.2);
		_this.left.setFill('white');
		_this.shape.draw();
	});
	this.left.on('mouseout', function() {
		_this.left.setOpacity(0.3);
		_this.left.setFill('black');
		_this.shape.draw();				
	});
	this.right.on('mouseover', function() {
	   	_this.right.setOpacity(0.2);
		_this.right.setFill('white');
		_this.shape.draw();
	});
	this.right.on('mouseout', function() {
		_this.right.setOpacity(0.3);
		_this.right.setFill('black');
		_this.shape.draw();				
	});


	this.box = new Kinetic.Rect({
		x:	pos.x,
		y:	pos.y,
		width:	size.x,
		height:	size.y,
		fill:	'black',
		cornerRadius:	10,
		opacity:	0.2,
		shadowColor: 'black',
        shadowBlur: 40,
        shadowOffset: 20,
        shadowOpacity: 1.0
	});
	this.shape = new Kinetic.Layer();
	this.shape.add(this.box);
	this.shape.add(this.left);
	this.shape.add(this.right);
	this.shape.add(this.ico_player);
	this.shape.add(this.team);
	this.shape.add(this.lvl);
	this.shape.add(this.pos);
}

PlayerWindow.prototype.setInfo = function	(lvl, team, pos) {
	this.lvl.setText("Lvl:   " + lvl);
	this.team.setText("Team: " + team);
	this.pos.setText("Pos:   (" + pos.x + "/" + pos.y + ")");
	this.ico_player.setImage(this.images[team]);
	this.shape.draw();
}

PlayerWindow.prototype.nextPlayer = function () {
	if (this.current_player < this.map.players.players.length - 1)
		this.current_player++;
	else
		this.current_player = 0;
	var pl = this.map.players.players[this.current_player];
	this.setInfo(pl.lvl, pl.team, pl.pos);
};

PlayerWindow.prototype.prevPlayer = function () {
	if (this.current_player > 0)
		this.current_player--;
	else
		this.current_player = this.map.players.players.length - 1;
	var pl = this.map.players.players[this.current_player];
	this.setInfo(pl.lvl, pl.team, pl.pos);
};