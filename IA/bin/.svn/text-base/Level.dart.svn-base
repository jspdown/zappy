import 'ia.dart';

class Level
{
  var      evolution;
  var      stones;
  var      level;
  var      player;
  int      lvl;
  
  Level(){
    evolution = [];
    evolution.add([1,0,0,0,0,0]);
    evolution.add([1,1,1,0,0,0]);
    evolution.add([2,0,1,0,2,0]);
    evolution.add([1,1,2,0,1,0]);
    evolution.add([1,2,1,3,0,0]);
    evolution.add([1,2,3,0,1,0]);
    evolution.add([2,2,2,2,2,1]);
    
    stones = [];
    stones.add(Resources.linemate);
    stones.add(Resources.deraumere);
    stones.add(Resources.sibur);
    stones.add(Resources.mendiane);
    stones.add(Resources.phiras);
    stones.add(Resources.thystame);
    
    level = [];
    level.add(9);
    level.add(8);
    level.add(10);
    level.add(5);
    level.add(6);
    level.add(1);
    
    player = [];
    player.add(1);
    player.add(2);
    player.add(2);
    player.add(4);
    player.add(4);
    player.add(6);
    player.add(6);
  }
  initLevel(int lvl)
  {
    if (lvl == this.lvl)
      return;
      for(int i = 0;  i != 6; i++)
      level[i] = 0;
    for(int i = lvl; i != 6; i++)
      for (int j = 0; j != 6; j++)
        level[i] += evolution[i][j];
  }
}