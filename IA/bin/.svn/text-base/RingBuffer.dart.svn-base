import 'comunication.dart';
import 'package:args/args.dart';
import 'dart:io';
import 'dart:isolate';
import 'ia.dart';
import 'dart:async';

class RingBuffer {
  int         _maxLength = 10;
  int         _current = 0;
  List<Trame> _toSend;
  int         port;
  String      addr = "localhost";
  bool        isConnect = false;
  Socket      _sock;
  int         rep = 0;
  bool        launchTimeOut = false;
  
  RingBuffer(var ia, this.port, this.addr) {
    this._toSend = [];
    Socket.connect(this.addr, this.port).then((Socket sock) {
        this._sock = sock;
        this._sock.done.then((_) {
          exit(0);
        });
        this.isConnect = true;
        sock.handleError((e) => print("ERROR"));
        try {
          sock.takeWhile((_) => true).listen((s) {
              String msg = new String.fromCharCodes(s);
              RegExp welcome = new RegExp("^[b|B][ienvenue|IENVENUE]");
              if (welcome.hasMatch(msg)) {
                sock.write(ia.state.equip + "\n");
                this._toSend.add(new Trame(ia.state.equip, 0));
              } else {
                List<String> recvList = msg.split("\n");
                recvList.reversed;
                recvList.forEach((e) {
                  if (this._toSend.length > 0 && e.length > 0) {
                    this.rep--;
                    if (this._toSend[0].trame == ia.state.equip) {
                      if (e == "ko")
                        exit(0);
                      this._toSend.removeAt(0);
                    } else {
                      ia.state.update(e, this._toSend[0]);
                      int test = (new DateTime.now().millisecondsSinceEpoch - this._toSend.last.time);

                      ia.t = ((test + ia.t) / 2).toInt();
                      if ((new RegExp(r'message')).hasMatch(e) == false && (new RegExp(r'elevation')).hasMatch(e) == false
                          && (new RegExp(r'deplacement')).hasMatch(e) == false) {
                        this._toSend.removeAt(0);
                        this._current--;
                      }
                    }
                  } else {
                    ia.state.update(e);
                  }
                });
                if (ia.state.map != null && this._toSend.length == 0) {
                  ia.update();
                }
              }
          })..onDone( () => exit(0) )
          ..onError((_) { print("Connection close."); exit(0); });
        } catch(e) {
          exit(0);
        }
    }).catchError((e) { print("[CONNECT]" + e.toString()); exit(0); });
  }
  
  bool push(Trame t, [bool force = false, bool waitRespond = false]) {
      if (this.isConnect != false && this._toSend.length < this._maxLength) {
        this._current++;
        t.time = new DateTime.now().millisecondsSinceEpoch;
        this._toSend.add(t);
        try {
          this.rep++;
          this._sock.write(t.toString() + "\n");
        } catch(e) {
           exit(0);
        }
        return true;
      }
    return false;
  }
  
  Trame pop() {
    Trame t = this._toSend.first;
    this._toSend.removeAt(0);
    return t;
  }

  int   nbMsg() {
    return this._toSend.length;
  }
}
