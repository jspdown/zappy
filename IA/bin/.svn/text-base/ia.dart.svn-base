import 'IaException.dart';
import 'IModule.dart';
import 'ModuleTest.dart';
import 'ModuleStone.dart';
import 'ModuleFood.dart';
import 'ModuleUpdate.dart';
import 'ModuleEggs.dart';
import 'ModuleIncantation.dart';
import 'ModuleIncantationGoTo.dart';
import 'ModuleCmd.dart';
import 'ModuleGoto.dart';
import 'RingBuffer.dart';
import 'dart:core';
import 'dart:collection';
import 'dart:io';
import 'dart:isolate';
import 'package:args/args.dart';
import 'comunication.dart';
import 'Level.dart';

class Resources {
  static const String food = "nourriture";
  static const String linemate = "linemate";
  static const String deraumere = "deraumere";
  static const String sibur = "sibur";
  static const String mendiane = "mendiane";
  static const String phiras = "phiras";
  static const String thystame = "thystame";
}

class Elem extends Resources {
  static const String player = "joueur";
}

bool  compareList(var a, var b) {
  int i;
  for (i = 0; i < a.length && i < b.length; i++) {
    if (a[i] != b[i])
      return false;
  }
  return (i == a.length && i == b.length);
}

class Map {
  num _height;
  num _width;
  Level evolution = new Level();

  List< List< List<String> > > map;

  Map(this._height, this._width) {
    this.map = new List(this._height);
    for (int i = 0; i < this._height; i++) {
      this.map[i] = new List(this._width);
      for (int j = 0; j < this._width; j++) {
        this.map[i][j] = new List();
      }
    }
  }

  num get height            => _height;
  num get width             => _width;

  elemCase(var state, int x, int y)
  {
    var elem = state.map.getCase(x, y);
    var elem_case = [];
    
    for(int i = 0; i != evolution.stones.length; i++)
      elem_case.add(state.map.countInList(elem, evolution.stones[i]));
    return elem_case;
  }
  
  List<String> getCase(num x, num y) {
    try {
      x = x % this.width;
      y = y % this.height;
    } catch (_) {
      return [];
    }
    if (x < 0)
      x = this.width - x;
    if (y < 0)
      y = this.height - y;
    if (y < this.map.length) {
      if (x < this.map[y].length)
        return (this.map[y][x]);
      else
        throw new OutOfRangeException("map index y", y);
    } else {
      throw new OutOfRangeException("map index x", x);
    }
  } 

  Position  updateCoord(Position pos) {
      pos.x = pos.x % this._width;
      pos.y = pos.y % this._height;
      pos.y = (pos.y < 0 ? this._height - pos.y : pos.y);
      pos.x = (pos.x < 0 ? this._width - pos.x : pos.x);
      return pos;
  }

  Position  checkMap(state, int x, int y, checkFunc, [maxIter = 4])
  {      
    Map map = state.map;
    Position result = new Position(-1, -1);
    int decal = 0;

    while (decal < map.height) {
      for (int i = 0; i < (decal * 2 + 1); i++) {
        if (checkFunc(state, x + decal, y - decal + i) == true) {
          result.x = x + decal;
          result.y = (y - decal + i);
          return updateCoord(result);
        } else if (checkFunc(state, x - decal, y - decal + i ) == true) {
          result.x = x - decal;
          result.y = (y - decal + i);
          return updateCoord(result);
        } else if (checkFunc(state, x - decal + i, y + decal) == true) {
          result.x = x - decal + i;
          result.y = (y + decal);
          return updateCoord(result);
        } else if (checkFunc(state, x - decal + i, y - decal) == true) {
          result.x = x - decal + i;
          result.y = (y - decal);
          return updateCoord(result);
        }
      }
      decal++;
    }
    return result;
  }


  int     countInList(List<String> l, String elem) {
    int nb = 0;

    if (l.length == 0)
      return 0;
    l.forEach((i) => nb += (i == elem ? 1 : 0));
    return nb;
  }

  String  toString([player_x = -1, player_y = -1]) {
    int x = 0;
    int y = 0;
    String s = "";

    for (List< List <String> > l in this.map) {
      for ( List<String> c in l) {
        int i = this.countInList(c, Resources.food).toString().length;
        stdout.write("[" + (player_x == x && player_y == y ? "*" : " ") + " j: " + this.countInList(c, Elem.player).toString() + ", n: " 
            + this.countInList(c, Resources.food).toString() + ", l: " + this.countInList(c, Resources.linemate).toString() + ", d: " + this.countInList(c, Resources.deraumere).toString());
        while (i < 4) {
          stdout.write(' ');
          i++;
        }
        stdout.write("]");
        x++;
      }
      x = 0;
      y++;
      print("");
    }
    return s;
  }

  bool        haveString(num x, num y, String e) {
    return (this.countInList((this.getCase(x, y)), e) > 0);
  }

  void      putInCase(num x, num y, String e) {
    (this.getCase(x, y)).add(e);
  }

  void    putListInCase(num x, num y, List<String> l) {
    (this.getCase(x, y))
      ..clear()
      ..addAll(l);
  }

  void      removeInCase(num x, num y, String elem) {
    bool haveRemove = false;
    (this.getCase(x, y)).removeWhere((e) {
        if (e == elem && haveRemove == false) {
        haveRemove = true;
        return true;
        }
        return false;
        });
  }

  void      removeAllInCase(num x, num y) {
    if ((this.getCase(x, y)).length > 0)
      (this.getCase(x, y)).clear();
  }

  void    clean() {
    this.map.forEach((e) => e.forEach((k) => k.clear()));
  }
}

class Stock extends Object {
  // Stock;
  HashMap<String, int> store = new HashMap<String, int>();

  Stock() {
    store[Resources.deraumere] = 0;
    store[Resources.linemate] = 0;
    store[Resources.mendiane] = 0;
    store[Resources.phiras] = 0;
    store[Resources.sibur] = 0;
    store[Resources.thystame] = 0;
  }

  String  toString() {
    String s = "$store";    
    return s;
  }
}

class Position {
  static String Nord = "nord";
  static String South = "south";
  static String East = "east";
  static String West = "west";

  List<String>  _dirTab = [Nord, West, South, East];

  int _mapHeight;
  int _mapWidth;

  int dir = 0;
  // Position en X
  int x;
  // Position en Y
  int y;
  // Direction
  String get direction => (this._dirTab[this.dir]);

  int get mapHeight => this._mapHeight;
      set mapHeight(int height) => this._mapHeight = height;
  
  int get mapWidth => this._mapWidth;
      set mapWidth(int width) => this._mapWidth = width;
      
  Position(this.x, this.y, [this._mapHeight = 0, this._mapWidth = 0]);

  void  turnLeft() {
    this.dir = ((this.dir + 1) % this._dirTab.length);
  }

  void  turnRight() {
    if (this.dir <= 0)
      this.dir = (this._dirTab.length - 1);
    else
      this.dir--;
  }

  void  move() {
    if (this._dirTab[this.dir] == Nord)
      this.y--;
    else if (this._dirTab[this.dir] == South)
      this.y++;
    else if (this._dirTab[this.dir] == West)
      this.x--;
    else
      this.x++;
    if (this._mapWidth != 0 && this._mapHeight != 0) {
      this.x = this.x % this._mapWidth;
      this.y = this.y % this._mapHeight;
      this.y = (this.y < 0 ? this._mapHeight - this.y : this.y);
      this.x = (this.x < 0 ? this._mapWidth - this.x : this.x);
    }
  }

   Position movePrevi() {
     Position test = new Position(this.x, this.y);
    if (this._dirTab[this.dir] == Nord)
      test.y--;
    else if (this._dirTab[this.dir] == South)
      test.y++;
    else if (this._dirTab[this.dir] == West)
      test.x--;
    else
      test.x++;
     return test;
    }
   
  bool  operator==(Position pos) {
    return (this.x == pos.x && pos.y == this.y);
  }

  String  toString() {
    return ("x : " + x.toString() + ", y : " + y.toString() + ", dir : " + this._dirTab[this.dir]);
  }
}

class State {
  List<List<String>> broadCastMsg = [];
  // Port
  String ip = "";
  num port;
  // Id de l'ia
  int id = 0;
  // parent Id
  int parent_id = -1;
  // nb son
  int nb = 1;
  // Niveau de l'ia
  int lvl = 0;
  // Nourriture de l'IA
  num food = 1;
  // Sac de l'IA
  Stock bag = new Stock();
  // Position de l'IA
  Position pos = new Position(-1, -1);
  // Nom de son equipe
  String equip;
  // Map de l'IA
  Map map;

  void  update(String msg, [Trame action]) {
    if (msg.length == 0)
      return ;
    if (msg.contains(new RegExp(r'^[0-9]+$'))) {
      if (int.parse(msg) > 0 && this.id == 0)  {
        int x = (EggsPos.length > 0 ? EggsPos[0][0] : this.pos.x);
        int y = (EggsPos.length > 0 ? EggsPos[0][1] : this.pos.y);
        Process.run("./bin/dart", ["./bin/ia.dart","-n",this.equip,"-p",port.toString(),"-h",this.ip,"-i",(this.id*10 + nb).toString(),"-t",this.id.toString()]).then((process) {
//          process.stdout.transform(new StringDecoder())
//          .transform(new LineTransformer())
//          .listen((String line) => print(line));
//          process.stderr.listen((data) { });
//          process.exitCode.then((exitCode) {
//            print('exit code: $exitCode');
//          });
        });
        nb++;
      }
    } else if (msg.contains(new RegExp(r'^mort$'))) {
      exit(0);
    } else if (msg.contains((new RegExp(r'^niveau actuel : [0-9]$')))) {
      this.lvl = int.parse(((msg.split(':'))[1])) - 1;
    } else if (msg.contains(new RegExp(r"^[0-9]+ [0-9]+$"))) {
      List<String> l = msg.split(' ');
      this.map = new Map(int.parse(l[1]), int.parse(l[0]));
      this.pos.mapHeight = int.parse(l[1]);
      this.pos.mapWidth = int.parse(l[0]);
      if (this.pos.x < 0 && this.pos.y < 0) {
        this.pos.y = (int.parse(l[1]) / 2).toInt();
        this.pos.x = (int.parse(l[0]) / 2).toInt();
      }
    } else if (msg.contains(new RegExp(r'^message ([0-9]),(.*)$'))) {
      this.broadCastMsg.add([msg.split(" ")[1].split(",")[0], msg.split(",")[1]]);
    } else if (msg.contains(new RegExp(r'^deplacement: [0-9]$'))) {
      return ;
    } else if (msg.contains(new RegExp(r'^{([a-zA-Z]+ [0-9]+[,]*)*}$'))) {
      (new RegExp(r'[a-zA-Z]+ [0-9]+')).allMatches(msg).forEach((elem) {
          if (elem.group(0).split(" ")[0] == Resources.food) {
            this.food = int.parse(elem.group(0).split(" ")[1]);
          } else {
            this.bag.store[elem.group(0).split(" ")[0]] = int.parse(elem.group(0).split(" ")[1]);
          }
        });
    } else if (msg.contains(new RegExp(r'^{(([a-zA-Z]+)* *,*)*}$'))) {
      int i = 0;
      int addX = 0;
      int j;
      j = 0;
      msg.split(",").forEach((e) {
          e = e.replaceAll("{", "").replaceAll("}", "");
          List<String> li = (e == null ? [] : e.split(" "));
          if (li.length > 0) {
            li.removeWhere((e) => e.length == 0 ? true : false);
          }
          if ((this.pos.dir) == 0) {
            this.map.putListInCase(this.pos.x - ((i-1)/2).toInt() + j, this.pos.y - addX, li);
          } else if (this.pos.dir == 1) {
            this.map.putListInCase(this.pos.x - addX, this.pos.y + ((i-1)/2).toInt() - j, li);
          } else if (this.pos.dir == 2) {
            this.map.putListInCase(this.pos.x + ((i-1)/2).toInt() - j, this.pos.y + addX, li);
          } else {
            this.map.putListInCase(this.pos.x + addX, this.pos.y - ((i-1)/2).toInt() + j, li);
          }
          j++;
          if (j >= i) {
            i = j + 2;
            j = 0;
            addX++;
          }
      });
    } else if (msg.contains(new RegExp(r'^ok$'))) {
      if (action.toString() == ((Command.Run()).toString())) {
        this.pos.move();
      }
      else if (action.toString() == ((Command.TurnLeft()).toString())) {
        this.pos.turnLeft();
      }
      else if (action.toString() == (Command.TurnRight()).toString()) {
        this.pos.turnRight();
      }
    }
  }
}

class IA {
  State state;
  List<String>  msgRecv;
  List<IModule> _module;
  var _action;
  RingBuffer ringBuffer;
  int t = 10;

  IA(String team, num port, [String addr = "localhost"])
  {
    this._module = [];
    this._action = [];
    this.state = new State();
    this.state.equip = team;
    this.state.port = port;
    IModule tmp = new ModuleStone();
    this._module.add(tmp);
    tmp = new ModuleFood();
    this._module.add(tmp);
    this._module.add(new ModuleEggs());
    this._module.add(new ModuleIncantation());
    this._module.add(new ModuleIncantationGoTo());
    this._module.add(new ModuleUpdate());
    this._module.add(new ModuleCmd());
    this._module.add(new ModuleGoto());
    this.ringBuffer = new RingBuffer(this, port, addr);
    this.state.ip = addr;
  }

  List<IModule> get module => this._module;
  
  int   _compAction(var a, var b) {
    if (a[0] == b[0])
      return 0;
    if (a[0] > b[0])
      return 1;
    return -1;
  }

  void  _getAction() {
    var it = this._module.iterator;
    var tmp;
    num i;

    while (it.moveNext())
    {
      tmp = (it.current).update(this.state);
      this._action.add(tmp);
    }
  }

  void  _resolve() {
    this._action.sort(this._compAction);
    // affichage de test
  }
  /*
   * Init le state de l'Ia
   * et initie la connection serveur
   */
  void init() {

  }

  /*
   * Appelez a chaque tour de boucle, cette methode doit 1/ update le state 2/ choisir son action 3/ si un action est choisi l'executer
   */
  void update() {
    this._getAction();
    this._resolve();
    try {
    this.execute();
    } catch (e) {
      print("Module error : " + e.toString());
    }
  }
  /*
   * Execute l'action choisie (Execute les actions de priorite -1 + la )
   */
  void execute() {
    int i = 0;

    while (i < this._action.length && this._action[i][0] < 0) {
      this._action[i][1].run(this);
      i++;
    }
    if (i < this._action.length && this._action[i][0] == 0) {
      this._action[i][1].run(this);
    } else if (this._action.length >= i) {
      this._action.last[1].run(this);
    }
    this._action.clear();
  }

  void  run() {
  }
}

class InfoGame {
  num port;
  String ip;
}

/*
 * Main de TEST
 */

bool isIncantation(State state, int x, int y)
{
  List<String> elem = state.map.getCase(x, y);
  var elem_case = state.map.elemCase(state, x, y);
  bool check;
  Level evolution = new Level();
  if (elem.isEmpty == true)
    return false;
  for (int j = 0; j != evolution.evolution.length; j++)
  {
    check = true;
    for (int i = 0; i != 6; i++)
      {
        if (elem_case[i] != evolution.evolution[j][i]) {
          check = false;
          break;
        }
     }
   if (check == true)
    if (state.map.countInList(elem, Elem.player) == evolution.player[j])
      return true;
  }
  return false;
}

void  runIa() {
  port.receive((var ia, SendPort reply) {
      ia.update();
  });
}

void  launchProgram(var ia) {
}

void main() {
  if ((new Options().arguments).length < 2) {
    print("Not enougth arguments.");
    print("ia -n team -p port [-h addr]");
    exit(1);
  }
  Map map = new Map(20, 20);
  var parser = new ArgParser();
  parser.addOption('team', abbr : 'n');
  parser.addOption('port', abbr : 'p');
  parser.addOption('host', abbr : 'h', defaultsTo : "127.0.0.1");
  parser.addOption('son', abbr : 's', defaultsTo : 'false');
  parser.addOption('height', abbr : 'y', defaultsTo : '-1');
  parser.addOption('width', abbr : 'x', defaultsTo : '-1');
  parser.addOption("id", abbr : 'i', defaultsTo : "-1");
  parser.addOption("parent_id", abbr : 't', defaultsTo : "-1");
  var result = parser.parse(new Options ().arguments);
  int port = 4242;
  try {
    port = int.parse(result['port']);
  } catch (_) {
    print("Invalid argument");
    exit(0);
  }
  IA ia = new IA(result['team'], port, result['host']);
  if (int.parse(result['height']) > 0 && int.parse(result['width']) > 0) {
    ia.state.pos.y = int.parse(result["height"]);
    ia.state.pos.x = int.parse(result["width"]);
  }
  if (int.parse(result["id"]) > 0) {
    ia.state.id = int.parse(result["id"]);
  }
  ia.state.parent_id = int.parse(result["parent_id"]);
}
