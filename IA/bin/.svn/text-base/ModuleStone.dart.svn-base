import 'IModule.dart';
import 'comunication.dart';
import 'ia.dart';
import 'IAction.dart';
import 'ActionGoTo.dart';
import 'dart:core';
import 'ModuleFood.dart';
import 'Level.dart';
import 'ModuleIncantation.dart';

class ModuleStone implements IModule
{
  num      priority = 1;
  IAction  action;
  var      _max = [1, 0];
  ActionRessources tmp;
  Level evolution = new Level();
  
  ModuleStone()
  {
    tmp = new ActionRessources();
  }
  
  void init(){}
  void delete(){}
  
  checkStone(var state, num level)
  {
    List<int> tmp = evolution.evolution[level];
    for (int i = 0; i < 6; i++)
      { 
          if (tmp[i] != 0 && state.bag.store[evolution.stones[i]] < tmp[i])
          {
              this._max[0] = 20;
              this._max[1] = i;
          }
      }
  }
  
  update(var state)
  {
    List<int> needs = this.evolution.evolution[state.lvl];
    this._max = [1,0];
    evolution.lvl = state.lvl;
    evolution.initLevel(state.lvl);
    checkStone(state, state.lvl);
    tmp.ressource = evolution.stones[this._max[1]];
    this.action = tmp;
    this.priority = this._max[0];
    for (int i = 0; i <this.evolution.stones.length; i++)
    {
      if (state.bag.store[this.evolution.stones[i]] > needs[i])
        return ([15, new ActionPut(this.evolution.stones[i])]);
    }
    return [this.priority, this.action];
  }
}
