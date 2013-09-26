
////////////////////////////////////
//  Assets Sprites: cut charsets
////////////////////////////////////

var sprites = {
	bottom:	[
		{x:0,y:0,width:32,height:48},
		{x:32,y:0,width:32,height:48},
		{x:64,y:0,width:32,height:48},
		{x:96,y:0,width:32,height:48}
	],
	left:	[
		{x:0,y:48,width:32,height:48},
		{x:32,y:48,width:32,height:48},
		{x:64,y:48,width:32,height:48},
		{x:96,y:48,width:32,height:48}
	],
	right:	[
		{x:0,y:96,width:32,height:48},
		{x:32,y:96,width:32,height:48},
		{x:64,y:96,width:32,height:48},
		{x:96,y:96,width:32,height:48}
	],
	top:	[
		{x:0,y:144,width:32,height:48},
		{x:32,y:144,width:32,height:48},
		{x:64,y:144,width:32,height:48},
		{x:96,y:144,width:32,height:48}
	],
	idle_bottom:	[
		{x:0,y:0,width:32,height:48}
	],
	idle_left:	[
		{x:0,y:48,width:32,height:48}
	],
	idle_right:	[
		{x:0,y:96,width:32,height:48}
	],
	idle_top:	[
		{x:0,y:144,width:32,height:48}
	],
	eggs:	[
		{x:0,y:0,width:32,height:48},
		{x:32,y:0,width:32,height:48},
		{x:64,y:0,width:32,height:48},
		{x:96,y:0,width:32,height:48}
	],
	incante:	[
		{x:0,y:0,width:64,height:75},
		{x:64,y:0,width:64,height:75},
		{x:128,y:0,width:64,height:75},
		{x:192,y:0,width:64,height:75}
	]
};

var sprite_rect = [];
sprite_rect[0] = {x: 32, y: 48, offset: 15};

////////////////////////////////////
// PLAYER:
///////////////////////////////////

function	Player(handler, asset, team, id, pos, direction) {
	this.handler = handler;
	this.id = id;
	this.team = team;
	this.lvl = 0;
	this.pos = pos;
	this.direction = direction;
	this.rel_pos = convertCoordToIso(this.pos, tileSize, true, sprite_rect[0]);
	this.sprite = new Kinetic.Sprite({
		x:	this.rel_pos.x,
		y:  this.rel_pos.y,
		width:	32,
		height:	48,
		image:	asset,
		animation: this.getAnim(this.direction, true),
		animations: sprites,
		frameRate: 5,
		index: 0
	});
}

Player.prototype.getAnim = function (dir, idle) {
	if (idle === undefined)
		return (dir == 1 ? 'top' : (dir == 2 ? 'right' : (dir == 3 ? 'bottom' : 'left')));
	else
		return (dir == 1 ? 'idle_top' : (dir == 2 ? 'idle_right' : (dir == 3 ? 'idle_bottom' : 'idle_left')));
};

Player.prototype.getDir = function (pos) {
	if (pos.x == this.pos.x || pos.y == this.pos.y) {
		if (pos.x == this.pos.x && pos.y == this.pos.y)
			return (0);
		var dir;
		if (pos.x == this.pos.x)
			dir = (pos.y < this.pos.y) ? (1) : (3);
		else
			dir = (pos.x < this.pos.x) ? (4) : (2);
		return (dir);
	}
	else
		return (-1);
};

Player.prototype.move = function (pos, dir) {
//	var dir = this.getDir(pos);
//	if (dir != -1) {
//		if (dir == 0)
//			return;
		this.pos = pos;
		var new_pos = convertCoordToIso(this.pos, tileSize, true, sprite_rect[0]);
		var diff_pos = {
			x: new_pos.x - this.rel_pos.x,
			y: new_pos.y - this.rel_pos.y	
		};
		this.sprite.move(diff_pos);
		this.sprite.setAnimation(this.getAnim(dir, true));
		this.rel_pos = new_pos;
		/*	
		var anim = this.getAnim(dir);
		var end_anim = this.getAnim(dir, true);
		var target_pos = convertCoordToIso(pos, tileSize, true, sprite_rect[0]);
		this.handler.addMovement(this, dir, target_pos, anim, end_anim);
		*/
//	}
//	else
//		console.log("[Error]:\tlag server");
};

//////////////////////////////////
//  PlayerHandler: manage players animation and movements.
//	stack all movement and update them on position.
//////////////////////////////////

function	PlayerHandler(assets, updateFrequency) {
	this.assets = assets;
	this.teams = [];
	this.players = [];
	this.moveQueue = [];
	setInterval(update, updateFrequency, this);
}

PlayerHandler.prototype.getPos = function (id) {
	for (var i = 0; i < this.players.length; i++) {
		if (this.players[i].id == id) {
			return (this.players[i].rel_pos);
		}
	}
}

PlayerHandler.prototype.getIdx = function (id) {
	for (var i = 0; i < this.players.length; i++) {
		if (this.players[i].id == id) {
			return (i);
		}
	}
	throw "IdxOutOfRange";
}

PlayerHandler.prototype.addTeam = function	(name) {
	for (var i = 0; i < this.teams.length; i++) {
		if (this.teams[i] == name)
			return;
	}
	this.teams.push(name);
};

PlayerHandler.prototype.addPlayer = function (team, id, pos, dir) {
	for (var i = 0; i < this.teams.length; i++) {
		if (this.teams[i] == team) {
			var pl = new Player(this, this.assets[team], team, id, pos, dir);
			this.players.push(pl);
			return (pl.sprite);
		}
	}
	throw "UnknowTeam";
};

PlayerHandler.prototype.removePlayer = function (id) {
	for (var i = 0; i < this.players.length; i++) {
		if (this.players[i].id == id) {
			this.players.splice(i, 1);
			break;
		}
	}
	for (var m = 0; m < this.moveQueue.length; m++) {
		if (this.moveQueue[m].player.id == id)
			this.moveQueue.splice(m, 1);
	}
};

PlayerHandler.prototype.move = function (id, where, pos) {
	for (var i = 0; i < this.players.length; i++) {
		if (this.players[i].id == id)
			this.players[i].move(where, pos);
	}
};

PlayerHandler.prototype.addMovement = function (player, direction, target_pos, anim, finish_anim) {
	player.sprite.setAnimation(anim);
	this.moveQueue.push({'player': player, 'dir': direction, 'pos': target_pos, 'end_anim': finish_anim});
};

PlayerHandler.prototype.updateMovement = function () {
	var speed = 2;
	for (var i = 0; i < this.moveQueue.length; i++) {
		var pl = this.moveQueue[i];
		if (pl.player.rel_pos.x == pl.pos.x && pl.player.rel_pos.y == pl.pos.y) {
			pl.player.sprite.setAnimation(pl.end_anim);
			this.moveQueue.splice(i, 1);
		}
		else {
			var n_pos = { 
				x:	(pl.dir == 1 || pl.dir == 2) ? (speed) : (-speed),
				y:	(pl.dir == 2 || pl.dir == 3) ? (speed / 2.0) : (-speed / 2.0)
			};
			pl.player.rel_pos.x += n_pos.x;
			pl.player.rel_pos.y += n_pos.y;
			pl.player.sprite.move(n_pos);
		}
	}
};

function	update(instance) {
	instance.updateMovement();
}