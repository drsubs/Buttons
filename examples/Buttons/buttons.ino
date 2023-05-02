#include "buttons.h"
#include "arduino.h"
#ifdef __AVR_ATtinyX4__
#include <SendOnlySoftwareSerial.h>
SendOnlySoftwareSerial mySerial(PA1);
#define Serial mySerial
#endif

/*
 *  Buttons example code.
 *  I define 4 diferrent ways of useing the Buttons object.
 */

//define the pins for the buttons.
#define BTN1 10
#define BTN2 9
#define BTN3 8
#define BTN4 7

/*

  Timed hold, so you can distinguish between short and long hold down.
  
*/
class TimedHold : public Button {
public:
  TimedHold() : Button(BTN1) {}
  void virtual action() {
    if(!state) {
      downtime=millis();
      Serial.println("Button 1 down");
    }
    if(state) {
      unsigned long hold=millis()-downtime;
      Serial.print("Button 1 hold time:");
      Serial.println(hold);
    }
  }
  unsigned long downtime;
};
/*

  Custom function for the button. In action metode so you can do your stuff there.

*/
class CustomButton : public Button {
public:
  CustomButton() : Button(BTN2) {}
  void virtual action() {
    // Do your stuff.
    Serial.print(state);
    Serial.println(" custom button 2");
  }
};
/*

  Custom function that dispath a function for down and one for up.

*/
class BtnUpDown : public Button {
public:
  BtnUpDown() : Button(BTN3) {}
  void virtual action() {
    if(state) actionUp(); else actionDown();
  }
  void actionDown() {
    Serial.println("Button 3 Down");

  }
  void actionUp() {
    Serial.println("Button 3 Up");
  }
};
/*

  One Button to all the Buttons.
  It has a pin valur and an id so each button can be id'ed in action metode.'
*/
class OneBtn : public Button {
public:
  OneBtn(int p,int i) : Button(p),id(i) {}
  OneBtn *add(int p,int i) {
    id=i;
    pin=p;
    return this;
  }
  void action() {
    // Call to static methode.
    OneBtn::myAction(state,id);
  }
  // We only got one myAction(static methode) to dispath the button push.
  static void myAction(int state,int id) {
    switch(id) {
      // Add one case for each id.
      case 4:
        Serial.print("OneBtn ");
        Serial.print(state);
        Serial.println(id);
        break;
      default : // unknown button. You forgot to write a case.
        Serial.println("Unknown button.");
      break;
    }
  }
private:
  int id;
};

// Create Buttons object and assign callBack function.
Buttons buttons;

void setup() {
  // Begin serial
  Serial.begin(9600);
  // Add Button(s) object to buttons.   
  buttons.addButton(new TimedHold());
  buttons.addButton(new CustomButton());
  buttons.addButton(new BtnUpDown());
  buttons.addButton(new OneBtn(BTN4,4));
}
void loop() {
  // Run the Buttons loop.
  buttons.run();
}
