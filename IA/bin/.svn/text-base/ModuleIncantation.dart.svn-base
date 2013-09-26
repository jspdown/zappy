import 'IModule.dart';
import 'Level.dart';
import 'IAction.dart';
import 'ia.dart';
import 'comunication.dart';

class ActionTake implements IAction
{
  String toTake;

  String actionString(){}
  ActionTake(this.toTake);
  void run(IA ia) {
    if (ia.state.map.countInList(ia.state.map.getCase(ia.state.pos.x, ia.state.pos.y), Elem.player) == 1 || toTake ==
        Resources.food) {
      ia.ringBuffer.push(Command.TakeObject(this.toTake));
    }
  }
}

class ActionPut implements IAction
{
  String toTake;

  String actionString(){}
  ActionPut(this.toTake);
  void run(IA ia) {
    ia.ringBuffer.push(Command.PutObject(this.toTake));
  }
}

class ActionIncantation implements IAction
{
  Level evolution = new Level();
  int _people = 0;
  
  set people(var p) => _people = p;
  ActionIncantation();
  String actionString(){}
 
void run(var ia)
  {
    if (_people == 1) {
      ia.ringBuffer.push(Command.Run());
      return ;
    }
     if (_people == -1) {
       ia.ringBuffer.push(Command.BroadCast(ia.state.id.toString() + "|" + "-1" + "|" + "go_to" + "|" + ia.state.pos.x.toString() + ":" + ia.state.pos.y.toString() + ":" + ia.state.lvl.toString()));
      return ;
     }
     ia.ringBuffer.push(Command.Incantation());
  }
}

List<int> howManyStoneINeed(List<int> mapCase, List<int> needs) {
  List<int> howManyNeed = new List();

  for (int i = 0; i < mapCase.length; i++) {
    howManyNeed.add(mapCase[i] - needs[i]);  
  }
  return howManyNeed;
}

class ModuleIncantation implements IModule
{
  num priority;
  ActionIncantation action = new ActionIncantation();
  Level evolution = new Level();
  
  ModuleIncantation();
  void init(){}
  void delete(){}


  update(var state)
  {
    List<int> yourCase = state.map.elemCase(state, state.pos.x, state.pos.y);
    Stock inventory = state.bag;
    int x = state.pos.x;
    int y = state.pos.y;
    List<int> needs = this.evolution.evolution[state.lvl];
    int nbPlayer = state.map.countInList(state.map.getCase(x, y), Elem.player);
    int nbPlayerNeed = this.evolution.player[state.lvl];
    List<int> howManyNeed = howManyStoneINeed(yourCase, needs);

    if (state.food < 5)
      return [1, action];
    if (nbPlayer < nbPlayerNeed) {
      this.action.people = -1;
    } else if (nbPlayer > nbPlayerNeed) {
      this.action.people = 1;
    } else {
      this.action.people = 0;
    }
    if (compareList(needs, yourCase) && nbPlayer <= nbPlayerNeed && nbPlayer > 0) {
      return ([35, this.action]);
    } else if (compareList(needs, yourCase)) {
      return ([29, this.action]);
    } else {
      for (int i = 0; i < howManyNeed.length; i++) {
        if (howManyNeed[i] < 0 && (inventory.store[this.evolution.stones[i]] + howManyNeed[i]) < 0)
        {
          return ([1, this.action]);
        } else if (howManyNeed[i] > 0 && state.map.countInList(state.map.getCase(x, y), Elem.player) <= 1) {
          return ([29, new ActionTake(this.evolution.stones[i])]);
        } else if (howManyNeed[i] < 0) {
          return ([29, new ActionPut(this.evolution.stones[i])]);
        }
      }
    }
    return ([1, this.action]);
  }
}
