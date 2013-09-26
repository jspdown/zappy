import 'IModule.dart';
import 'IAction.dart';
import 'Level.dart';
import 'ia.dart';
import 'ActionGoTo.dart';
import 'ModuleUpdate.dart';
import 'ModuleIncantation.dart';

class ActionIncantationGoTo implements IAction
{
  var _pos = [];
  
  set pos (var tmp) => _pos = tmp;
  String actionString(){}
  void run(var ia){
    Position position = new Position(_pos[0], _pos[1]);
    ActionGoTo go = new ActionGoTo(ia.state.pos, position);
    if (position != ia.state.pos) {        
      go.run(ia);
    }
  }
}

class ModuleIncantationGoTo implements IModule
{
  num priority;
  var _pos = [];
  int  tour = 0;
  ActionIncantationGoTo action = new ActionIncantationGoTo();
  Level evolution = new Level();
  
  void init(){}
  void delete(){}
 
  checkLevel(var state, int x, int y)
  {
    List<int> yourCase = state.map.elemCase(state, x, y);
    List<int> needs = this.evolution.evolution[state.lvl];
    int nbPlayer = state.map.countInList(state.map.getCase(x, y), Elem.player);
    int nbPlayerNeed = this.evolution.player[state.lvl];

    if (compareList(yourCase, needs) == true) {
      if (x == state.pos.x && state.pos.y == y && nbPlayer == nbPlayerNeed)
        return false;
      else if (x == state.pos.x && state.pos.y == y)
        return false;
      if ((nbPlayer - nbPlayerNeed) < 0 && nbPlayer > 0)
        return true;
      return false;
    }
    return false;
  } 

  update(var state){
    ModuleIncantation tmp = new ModuleIncantation(); 
   
    if (state.food < 6)
      return [1, action];
    if (_pos.isEmpty == false && state.pos.x == _pos[0] && state.pos.y == _pos[1])
    {
      _pos = [];
      return [10, new ActionUpdate()];
    }
    if ((tmp.update(state))[0] == 32)
      return [1, action];
    if (_pos.isEmpty == true) {
      Position ret;
      ret = state.map.checkMap(state, state.pos.x, state.pos.y, checkLevel);
      if (ret.x >= 0 && ret.y >= 0)
        _pos = [ret.x, ret.y];
    }
    action.pos = _pos;
    if (_pos.isEmpty == false)
      return [32, action];
    return [1, action];
  }
}
