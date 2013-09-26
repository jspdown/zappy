import 'IModule.dart';
import 'ActionTest.dart';

import 'ModuleGoto.dart';
import 'IAction.dart';
import 'comunication.dart';
import 'RingBuffer.dart';
import 'ia.dart';

int EggsCounter = 1;
List<List<int>> EggsPos = [];

class ActionEggs implements IAction
{
  ActionEggs();
  String actionString() { return "ActionUpdate"; }
  void run(IA ia) {
    if (ia.ringBuffer.push(Command.Fork()))
      EggsCounter++;
    EggsPos.add([ia.state.pos.x, ia.state.pos.y]);
  }
}

class ModuleEggs implements IModule
{
  num priority;
  ActionEggs action = new ActionEggs();
  
  ModuleEggs()
  {
    this.action = new ActionEggs();
    this.priority = -1;
  }
  void init(){}
  void delete(){}
  update(var state) {
    if (state.id == 0) {
      int nb = 8 + (state.map.height * state.map.width) / 30;
      nb = nb - nb % 2;
      nb = nb > 16 ? 16 : nb;
      return ([EggsCounter < nb ? 31 : 5, new ActionEggs()]);
      /*return ([EggsCounter < 4 ? 35 : 5, this.action]);*/
    }
    else
      return ([-1, new ActionEmpty()]);
  }
}
