import 'dart:core';

class OutOfRangeException implements Exception {
  String message;
  int    value;

  OutOfRangeException([this.message = "", this.value = 0]);

  String    toString() {
    return ("[OutOfRange] $message with value $value");
  }
}