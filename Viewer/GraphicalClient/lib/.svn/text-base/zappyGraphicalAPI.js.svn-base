
var command_queue = [];
var action_queue = [];
var	refresh_event = 100;

//===========================
// CORE: handle socket 'n update event queue
//===========================


function	Core(socket, images, init) {
	this.socket = socket;
	this.images = images;
	this.init = init;
	this.modules = {
		map:		new MapData(this),
		players:	new PlayersData(this),
		animations:	new AnimationData(this)
	};
	var _this = this;
/*	setInterval(function () {
		while (action_queue.length > 0) {
			_this.socket.emit('rts', action_queue.pop());
		}
	}, refresh_event);*/
}

function	execute(modules, cmd) {
	for (var name in modules) {
		modules[name].applyListeners(cmd);
	}
}

function	startClient(host, images, init) {
	console.log("start client on " + host);
	var socket = io.connect(host);
	var core = new Core(socket, images, init);
	socket.on('commands', function (data) {
		if (data == "BIENVENUE")
			socket.emit('commands', "GRAPHIC\n");
		else {
			execute(core.modules, parseCommand(data))
		}
	});
}

//===========================
// LISTENER
//===========================

function	Listener(name, foo) {
	this.name = name;
	this.foo = foo;
}

Listener.prototype.incorporate = function (obj, cmd) {
	this.foo(obj, cmd);
};

//===========================
// MODULE: base class
//===========================

function	Module(father, name) {
	this.father = father;
	this.name = name;
	this.listeners = [];
}

Module.prototype.applyListeners = function (cmd) {
	for (var i = 0; i < this.listeners.length; i++) {
		if (this.listeners[i].name == cmd.name) {
			this.listeners[i].incorporate(this, cmd);
		}
	}
};

////////////////////////////////////////
//         MAP: module n' listeners
////////////////////////////////////////

function	MapData(father) {
	Module.call(this, father, "map");
	this.size = {x: 0, y: 0};
	this.tile = [];
	
	var _this = this;
	
	this.listeners.push(new Listener("bct", function (obj, cmd) {
		if (cmd.args.length == 9) {
			var x = parseInt(cmd.args[0], 10);
			var y = parseInt(cmd.args[1], 10);
			var content = {
				'food': parseInt(cmd.args[2], 10), 
				'linemate': parseInt(cmd.args[3], 10),
				'deraumere': parseInt(cmd.args[4], 10),
				'sibur': parseInt(cmd.args[5], 10),
				'mendiane': parseInt(cmd.args[6], 10),
				'phiras': parseInt(cmd.args[7], 10),
				'thystame': parseInt(cmd.args[8], 10)
			};
			obj.tile[y * obj.size.x + x] = content;
			if (_this.father.graphical !== undefined)
				_this.father.graphical.map.setTile(x, y, content);
		}
		else {
			throw "MissingCommand";
		}
	}));
	this.listeners.push(new Listener("msz", function (obj, cmd) {
		if (cmd.args.length == 2) {
			obj.size.x = parseInt(cmd.args[0], 10);
			obj.size.y = parseInt(cmd.args[1], 10);
			if (obj.size.x * obj.size.y > 10000) {
				loader.addAlert("<b>Warning:</b> The map is huge (" + obj.size.x + "x" + obj.size.y + ")");
				if (!confirm('Do you really want to show this game?')) {
					loader.addAlert("<b>Info:</b> Drawing cancel.");
					return;
				}
			}
			_this.father.graphical = _this.father.init(_this.father, _this.father.images, obj.size);
		}
		else
			throw "MissingCommand";
	}));
}
MapData.prototype = new Module();
MapData.prototype.constructor = MapData;

//////////////////////////////////////////
//          PLAYERS: module n' listeners
//////////////////////////////////////////

function	PlayersData(father) {
	Module.call(this, father, "players");
	this.teams = [];
	this.players = [];
	
	var _this = this;
	
	this.listeners.push(new Listener("tna", function (obj, cmd) {
		if (cmd.args.length > 0) {
			var name = cmd.args.join(" ");
			for (var i = 0; i < obj.teams.length; i++) {
				if (obj.teams[i] == name)
					return;
			}
			obj.teams.push(name);
			console.log(name);
			_this.father.graphical.map.addTeam(name);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pdi", function (obj, cmd) {
		if (cmd.args.length == 1) {
			var id = getClientId(cmd.args[0]);
			_this.father.graphical.map.removePlayer(id);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pnw", function (obj, cmd) {
		if (cmd.args.length >= 6) {
			var pl = {	
						'id': getClientId(cmd.args[0]), 
						'pos': {x: parseInt(cmd.args[1], 10), y: parseInt(cmd.args[2], 10)}, 
						'direction': parseInt(cmd.args[3], 10), 
						'level': parseInt(cmd.args[4], 10), 
						'team': cmd.args.slice(5).join(" "),
						'inventory': []
					};
			for (var i = 0; i < obj.players.length; i++) {
				if (obj.players[i].id == pl.id) {
					obj.players[i] = pl;
					return;
				}
			}
			obj.players.push(pl);
			_this.father.graphical.map.eclosion(pl.team, pl.id, pl.pos, pl.direction);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pgt", function (obj, cmd) {
		if (cmd.args.length == 2) {
			var id = getClientId(cmd.args[0]);
			var type = parseInt(cmd.args[1], 10);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pdr", function (obj, cmd) {
		if (cmd.args.length == 2) {
			var id = getClientId(cmd.args[0]);
			var type = parseInt(cmd.args[1], 10);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pex", function (obj, cmd) {
		if (cmd.args.length == 1) {
			var id = getClientId(cmd.args[0]);
			_this.father.graphical.map.expulse(id);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("ppo", function (obj, cmd) {
		if (cmd.args.length == 4) {
			var id = getClientId(cmd.args[0]);
			for (var i = 0; i < obj.players.length; i++) {
				if (obj.players[i].id == id) {
					obj.players[i].pos.x = parseInt(cmd.args[1], 10);
					obj.players[i].pos.y = parseInt(cmd.args[2], 10);
					obj.players[i].direction = parseInt(cmd.args[3], 10);
					_this.father.graphical.map.movePlayer(obj.players[i].id, obj.players[i].pos.x, obj.players[i].pos.y, obj.players[i].direction);
					return;
				}
			}
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("plv", function (obj, cmd) {
		if (cmd.args.length == 2) {
			var id = getClientId(cmd.args[0]);
			for (var i = 0; i < obj.players.length; i++) {
				if (obj.players[i].id == id) {
					obj.players[i].level = parseInt(cmd.args[1], 10);
					return;
				}
			}
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pin", function (obj, cmd) {
		if (cmd.args.length == 10) {
			var id = getClientId(cmd.args[0]);
			for (var i = 0; i < obj.players.length; i++) {
				if (obj.players[i].id == id) {
					obj.players[i].inventory = {
						'food': parseInt(cmd.args[3], 10), 
						'linemate': parseInt(cmd.args[4], 10),
						'deraumere': parseInt(cmd.args[5], 10),
						'sibur': parseInt(cmd.args[6], 10),
						'mendiane': parseInt(cmd.args[7], 10),
						'phiras': parseInt(cmd.args[8], 10),
						'thystame': parseInt(cmd.args[9], 10)
					};
					return;
				}
			}
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pbc", function (obj, cmd) {
		if (cmd.args.length >= 2) {
			var id = getClientId(cmd.args[0]);
			_this.father.graphical.map.broadcast(id, cmd.args.slice(1).join(" "));
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("enw", function (obj, cmd) {
		if (cmd.args.length == 4) {
			var id = getClientId(cmd.args[0]);
			var pl_id = parseInt(cmd.args[1], 10);
			var pos = {
				x: parseInt(cmd.args[2], 10),
				y:	parseInt(cmd.args[3], 10)
			};
			_this.father.graphical.map.addEggs(pos, id, pl_id);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("eht", function (obj, cmd) {
		if (cmd.args.length == 1) {
			var id = getClientId(cmd.args[0]);
			//_this.father.graphical.map.eclosion(id);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pie", function (obj, cmd) {
		if (cmd.args.length == 3) {
			var pos = {
				x:	parseInt(cmd.args[0], 10),
				y:	parseInt(cmd.args[1], 10)
			};
			var stat = parseInt(cmd.args[2], 10);
			_this.father.graphical.map.addIncante(pos, stat);
		}
		else
			throw "MissingCommand";
	}));
	this.listeners.push(new Listener("pic", function (obj, cmd) {
		if (cmd.args.length >= 4) {
			var pos = {
				x:	parseInt(cmd.args[0], 10),
				y:	parseInt(cmd.args[1], 10)
			};
			var lvl = parseInt(cmd.args[2], 10);
			_this.father.graphical.map.addIncanteTell(pos, lvl);
		}
		else
			throw "MissingCommand";
	}));

}

PlayersData.prototype = new Module();
PlayersData.prototype.constructor = PlayersData;

//////////////////////////////////////////
//          ANIMATION: module n' listeners
//			each cmd is push in a queue: this 
//			is the actions you should animate
//////////////////////////////////////////

function	AnimationData(father) {
	Module.call(this, father, "animation");
	this.queue = [];
	var actions = ['plv', 'ppo', 'pex', 'pbc', 'pic', 'pie', 'pfk', 'pdr', 'pgt', 'pdi', 'eht', 'enw', 'ebo', 'edi', 'seg'];
	for (var i = 0; i < actions.length; i++) {
		this.listeners.push(new Listener(actions[i], function (obj, cmd) {
			obj.queue.push(cmd);
		}));
	}
}

AnimationData.prototype = new Module();
AnimationData.prototype.constructor = AnimationData;

//////////////////////////////////////////
//          ACTIONS: module n'emitters
//////////////////////////////////////////
/*
function	Actions() {
	call(this, "actions");
}

Actions.prototype = new Module();
Actions.prototype.constructor = Actions;

Actions.prototype.move = function (x, y) {
	action_queue.push({action: 'ppo', args: })
}
*/
//===========================
// UTILS
//===========================

function	parseCommand(data) {
	var elms = data.split(" ");
	return ({name: elms[0], args: elms.slice(1)});
}

function	getClientId(str) {
	if (str.length >= 1) {
		return (parseInt(str, 10));
	}
	else
		throw "NotAClientId";
}
