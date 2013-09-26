import 'IAction.dart';
import 'comunication.dart';
import 'RingBuffer.dart';
import 'ia.dart';

class ActionTest implements IAction
{
  ActionTest();
  String actionString() { return ""; }
  void run(IA ia){ ia.ringBuffer.push(Command.Run()); ia.ringBuffer.push(Command.TurnLeft()); }
}