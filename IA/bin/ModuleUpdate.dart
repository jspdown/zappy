import 'IModule.dart';
import 'ActionTest.dart';

import 'ModuleEggs.dart';
import 'IAction.dart';
import 'comunication.dart';
import 'RingBuffer.dart';
import 'ia.dart';

class ActionUpdate implements IAction
{
  ActionUpdate();
  String actionString() { return "ActionUpdate"; }
  void run(IA ia) { 
    ia.ringBuffer.push(Command.Look());
    ia.ringBuffer.push(Command.Inventory());
    if (EggsPos.length > 0)
      ia.ringBuffer.push(Command.UnusedSlot());
    /*if (ia.state.id == 0) {
      ia.ringBuffer.push(Command.BroadCast(ia.state.id.toString() + "|" + "-1" + "|" + "go_to" + "|" + ia.state.pos.x.toString() + ":" + ia.state.pos.y.toString()));
    }*/
  }
}

class ActionConnectNbr implements IAction
{
  ActionConnectNbr();
  String actionString() { return "ActionConnectNbr"; }
  void run(IA ia) {
    ia.ringBuffer.push(Command.UnusedSlot());
  }
}

class ModuleUpdate implements IModule
{
  num priority;
  ActionTest action;
  num cycle = 0;
  
  ModuleUpdate()
  {
    this.action = new ActionTest();
    this.priority = -1;
  }
  void init(){}
  void delete(){}
  update(var state) {
    if (cycle <= 0) {
      cycle = 1;
      return ([250, new ActionUpdate() ]);
    } else {
      cycle--;
      return [-1, new ActionConnectNbr() ];
    }
  }
}
