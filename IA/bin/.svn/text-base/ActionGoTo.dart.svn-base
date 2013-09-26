import 'IAction.dart';
import 'ia.dart';
import 'comunication.dart';

num   abs(num a) {
  return (a < 0 ? -a : a);
}

class ActionGoTo implements IAction
{
  Position  _a;
  Position  _b;
  
  ActionGoTo(this._a, this._b);
  String actionString(){}
  void run(var ia){
    goTo(ia, _a, _b);
  }
  
  static void goTo(var ia, Position start, Position end) {
    String goal = ia.state.pos.direction;
    if (end.x > start.x)
      goal = Position.East;
    else if (end.x < start.x)
      goal = Position.West;
    if (start.x != end.x && ia.state.pos.direction != goal) {
      ia.ringBuffer.push(Command.TurnLeft());
      return ;
    }
    if (start.x != end.x) {
      if (isIncantation(ia.state, (ia.state.pos.movePrevi()).x, (ia.state.pos.movePrevi()).y) == true)
        ia.ringBuffer.push(Command.TurnRight());
      ia.state.map.removeInCase(ia.state.pos.x, ia.state.pos.y, Elem.player);
      ia.ringBuffer.push(Command.Run());
      return ;
    }
    if (end.y < start.y)
      goal = Position.Nord;
    else if (end.y > start.y)
      goal = Position.South;
    if (end.y != start.y && ia.state.pos.direction != goal) {
      ia.ringBuffer.push(Command.TurnLeft());
      return ;
    }
    if (start.y != end.y) {
      if (isIncantation(ia.state, (ia.state.pos.movePrevi()).x, (ia.state.pos.movePrevi()).y) == true)
        ia.ringBuffer.push(Command.TurnRight());
      ia.state.map.removeInCase(ia.state.pos.x, ia.state.pos.y, Elem.player);
      ia.ringBuffer.push(Command.Run());
      return ;
    }
  }
  
}
