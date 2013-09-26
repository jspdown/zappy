import 'dart:collection';

import 'IModule.dart';
import 'ActionTest.dart';

import 'ModuleGoto.dart';
import 'ActionGoTo.dart';
import 'ModuleEggs.dart';
import 'IAction.dart';
import 'comunication.dart';
import 'RingBuffer.dart';
import 'ia.dart';

typedef void  Execfunc(IA ia, int from, int dir, String msg);

bool haveSyncDir = false;

void  DirectionRequest(IA ia, int from, int dir, String msg) {
  if (EggsPos.length == 0)
    EggsPos.add([ia.state.pos.x, ia.state.pos.y]);
  int res = ((ia.state.pos.dir * 2) + dir);
  res = (res % 9).toInt() + (res / 9).toInt();
  ia.ringBuffer.push(Command.BroadCast(ia.state.id.toString() + "|" + from.toString() + "|" + "dir_recv" + "|" + (res).toString() + ":" 
      + EggsPos[0][0].toString() + ":" + EggsPos[0][1].toString()));
  if (EggsPos.length > 1)
    EggsPos.removeAt(0);
}

void  DirectionRespond(IA ia, int from, int dir, String msg) {
  List<List<int>> l = new List.generate(9, (int idx) => new List.generate(9, (int index) => 0));
  for (int i = 1; i < l.length; i++) {
    l[i][i] = 2;
    l[i][(i+2) % l.length + ((i+2) / l.length).toInt()] = 1;
    l[i][(i+4) % l.length + ((i+4) / l.length).toInt()] = 0;
    l[i][(i+6) % l.length + ((i+6) / l.length).toInt()] = 3;
  }
  if (dir == 0)
    return ;
  print("");
  ia.state.pos.dir = l[int.parse(msg.split(":")[0])][dir];
  ia.state.pos.x = int.parse(msg.split(":")[1]);
  ia.state.pos.y = int.parse(msg.split(":")[2]);
  haveSyncDir = true;  
}

void  CmdGoTo(IA ia, int from, int dir, String msg) {
  if (int.parse(msg.split(":")[2]) != ia.state.lvl)
    return ;
  for (IModule m in ia.module) {
    if (m is ModuleGoto && m.isMoving == true && m.from == from) {
      if (dir == 0) {
        m.from = -1;
      }
      m.dir = dir;
    } else if (m is ModuleGoto && m.isMoving == false) {
      m.dir = dir;
      m.from = from;
      m.isMoving = true;
    }
  }
}

class ActionCmd implements IAction
{
  HashMap<String, Execfunc>  func = new HashMap();
  int def = 0;
  
  ActionCmd() {
    func["dir_req"] = DirectionRequest;
    func["dir_recv"] = DirectionRespond;
    func["go_to"] = CmdGoTo;
  }
  String actionString() { return "ActionCmd"; }
  void run(IA ia) {
    if (ia.state.id > 0 && haveSyncDir == false) {
      ia.ringBuffer.push(Command.BroadCast(ia.state.id.toString() + "|" + ia.state.parent_id.toString() + "|" + "dir_req" + "|" + "m"));
      def++;
      if (def > 30)
        haveSyncDir = true;
    }
    for (List<String> l in ia.state.broadCastMsg) {
      try {
        if (l[1].split("|").length >= 4 && func.containsKey(l[1].split("|")[2]) == true && (int.parse(l[1].split("|")[1]) == ia.state.id || int.parse(l[1].split("|")[1]) < 0)) {
            this.func[l[1].split("|")[2]](ia, int.parse(l[1].split("|")[0]), int.parse(l[0]), l[1].split("|")[3]);
          break;
        }
      } catch (_) {
        ia.state.broadCastMsg.clear();
        return ;
      }
    }
    ia.state.broadCastMsg.clear();
  }
}

class ModuleCmd implements IModule
{
  num priority;
  ActionCmd action;
  
  ModuleCmd()
  {
    this.action = new ActionCmd();
    this.priority = -1;
    
    
  }
  void init(){}
  void delete(){}
  update(var state) {
//    if (state.id > 0 && haveSyncDir == false) {
//      return ([200, this.action]);
//    }
    return ([-1, this.action]);
  }
}
