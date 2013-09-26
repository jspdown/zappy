import 'IModule.dart';
import 'ActionTest.dart';

class ModuleTest implements IModule
{
  num priority;
  ActionTest action;
  
  ModuleTest()
  {
    this.action = new ActionTest();
    this.priority = 200;
  }
  void init(){}
  void delete(){}
  update(var state) => [priority,action];
}
