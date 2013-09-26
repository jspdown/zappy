class Trame extends Object {
  String  trame;
  num     cycle;
  int     time;
  
  Trame(this.trame, this.cycle);
  String  toString() {
    return (trame);
  }
}

class Command {
  static Trame  Run() {
    return new Trame("avance", 7);
  }
  
  static Trame  TurnRight() {
    return new Trame("droite", 7);
  }
  
  static Trame  TurnLeft() {
    return new Trame("gauche", 7);
  }
  
  static Trame  Look() {
    return new Trame("voir", 7);
  }
  
  static Trame  Inventory() {
    return new Trame("inventaire", 1);
  }
  
  static Trame  TakeObject(String object) {
    return new Trame("prend " + object, 7);
  }
  
  static Trame  PutObject(String object) {
    return new Trame("pose " + object, 7);
  }
  
  static Trame  Expulse() {
    return new Trame("expulse", 7);
  }
  
  static Trame  BroadCast(String text) {
    return new Trame("broadcast " + text, 7);
  }
  
  static Trame  Incantation() {
    return new Trame("incantation", 300);
  }
  
  static Trame   Fork() {
    return new Trame("fork", 42);
  }
  
  static Trame   UnusedSlot() {
    return new Trame("connect_nbr", 0);
  }
}
