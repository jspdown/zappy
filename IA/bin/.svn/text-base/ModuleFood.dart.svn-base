import 'IModule.dart';
import 'IAction.dart';
import 'ia.dart';
import 'comunication.dart';
import 'ActionGoTo.dart';
import 'RingBuffer.dart';
import 'dart:core';
import 'ModuleIncantation.dart';

class ActionRessources implements IAction
{
  var  _pos = [];
  int  tour = 0;
  bool _turn = true;
  bool flag = true;
  var  turn;
  bool isFinish = true;
  String _ressource;
  set ressource(String name) => _ressource = name;
  get ressource => _ressource;
  ActionRessources()
  {
  }
  
  String actionString(){}
  
  _doAction(var ia){
    if ((ia.state.map).haveString(ia.state.pos.x, ia.state.pos.y, _ressource) == true && (_ressource == Resources.food && ia.state.map.countInList(ia.state.map.getCase(ia.state.pos.x, ia.state.pos.y), Elem.player) <= 1)) 
    {
      ia.ringBuffer.push(Command.TakeObject(_ressource));
      _pos = [];
      return;
    }
    tour = 0;
    if (_pos.isEmpty == true) {
      var p = ia.state.map.checkMap(ia.state, ia.state.pos.x, ia.state.pos.y, (state, x, y) {
            return (state.map.haveString(x, y, _ressource) && (_ressource == Resources.food || state.map.countInList(state.map.getCase(x, y), Elem.player) <= 1));
        });
      if (p.x >= 0 && p.y >= 0)
          _pos = [p.x, p.y];
        ia.ringBuffer.push(Command.TurnRight());
        ia.ringBuffer.push(Command.Run());
      }
  }
   
  void run(var ia){

    if (_pos.isEmpty == true) {
      _doAction(ia);
    }
    if (_pos.isEmpty == false)
    {
      Position pos = new Position(_pos[0], _pos[1]);
      ActionGoTo go = new ActionGoTo(ia.state.pos, pos);
      if (pos != ia.state.pos) {        
        go.run(ia);
        return ;
      }
      if (pos == ia.state.pos) {
        if (ia.state.map.countInList(ia.state.map.getCase(ia.state.pos.x, ia.state.pos.y), Elem.player) <= 1
            && ia.state.map.haveString(ia.state.pos.x, ia.state.pos.y, _ressource)) {
          ia.ringBuffer.push(Command.TakeObject(_ressource));
          ia.state.map.removeInCase(ia.state.pos.x, ia.state.pos.y, _ressource);
        }
        _pos = [];
        flag = true;
        isFinish = true;
        }
      else
        isFinish == false;
    }
    else
    {
      if (_turn == true)
        ia.ringBuffer.push(Command.TurnRight());
      else {
        if (isIncantation(ia.state, ia.state.pos.movePrevi().x, ia.state.pos.movePrevi().y) == true)
          ia.ringBuffer.push(Command.TurnLeft());
      }
      ia.ringBuffer.push(Command.Run());
      
      flag = true;
      _turn = !_turn;
      return ;
    }
  }
}

class ModuleFood implements IModule
{
  num priority;
  IAction action;
  ActionRessources tmp;
  bool  getFood = false;

  ModuleFood(){
    tmp = new ActionRessources();
    tmp.ressource = Resources.food;
    action = tmp;
  }
  void init(){
}
  
  void delete(){}
  
  update(var state){
    this.priority = (1 / (state.food / 250.0));
    if ((state.food < 10) || getFood) {
      getFood = true;
      this.priority = 60;
    }
    if (state.food >= 20) {
      getFood = false;
    }
    if ((state.map).haveString(state.pos.x, state.pos.y, Resources.food) == true)
      return [this.priority, new ActionTake(Resources.food)];
    return [this.priority, this.action];
  }
}
