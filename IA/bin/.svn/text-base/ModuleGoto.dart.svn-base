import 'IModule.dart';
import 'ActionTest.dart';

import 'ActionGoTo.dart';
import 'IAction.dart';
import 'comunication.dart';
import 'RingBuffer.dart';
import 'ia.dart';

class ActionEmpty implements IAction
{
  ActionEmpty();
  String actionString() { return "nothing"; }
  void run(IA ia){ }// ia.ringBuffer.push(Command.UnusedSlot()); }
}

class ActionMove implements IAction
{
  int dir = 0;

  void run(IA ia) {
    if (this.dir == 8 || this.dir == 2 || this.dir == 1) {
      ia.ringBuffer.push(Command.Run());
    } else if (this.dir == 4 || this.dir == 3 || this.dir == 5) {
      ia.ringBuffer.push(Command.TurnLeft());
    } else if (this.dir == 7 || this.dir == 6) {
      ia.ringBuffer.push(Command.TurnRight());
    }
    this.dir = 0;
  }
}

class ModuleGoto implements IModule
{
  num priority;
  ActionMove action = new ActionMove();
  bool isMoving = false;
  int from = -1;
  int dir = 0;

  ModuleGoto()
  {
    this.priority = -1;
  }
  void init(){}
  void delete(){}
  update(var state) {
    int nbPlayer = state.map.countInList(state.map.getCase(state.pos.x, state.pos.y), Elem.player);
    if ((dir == 0 && from >= 0) || this.isMoving == false) {
      this.isMoving = false;
      return ([-1, new ActionEmpty()]);
    } else {
      this.action.dir = this.dir;
      this.dir = 0;
      return ([this.action.dir == 0 ? -1 : nbPlayer > 1 ? 30 : 38, this.action]);
    }
  }
}
