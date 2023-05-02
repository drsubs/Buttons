#ifndef BUTTONS_H
#define BUTTONS_H

class Button {
public:
  Button(int p) {
    pinMode(p, INPUT_PULLUP);
    pin=p;
    state=1;
  }
  void check() {  
    int s=digitalRead(pin);
    if(state!=s) {
      state=s;
      action();
    }
  }
  void virtual action(){}
  int pin;
  int state;
  Button *next;
};
class Buttons {
public:
  Buttons() {
    first=0;
  }
  void addButton(Button *b) {
    b->next=first;
    first=b;
  }
  inline void run() {
    for(Button *b=first;b!=0;b=b->next) b->check();
  }
private:
  Button *first;
};

#endif
