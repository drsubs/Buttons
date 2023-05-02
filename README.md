## Buttons

This library is an adapation of the SoftwareSerial library, with the receiving code omitted.

It is intended for situations where you need to do software sending (not use the hardware serial) but don't need to receive anything. This lets you avoid tying up the pin-change interrupts for the receiving code.

Example of use:

```c++
#include <Buttons.h>
#define BTN1 10 // Pin number.

/*

  Custom function for the button. In action metode so you can do your stuff there.

*/

class CustomButton : public Button {
public:
  CustomButton() : Button(BTN1) {}
  void virtual action() {
    // Do your stuff.
    mySerial.print(state);
    mySerial.println(" custom button 2");
  }
};

// Create Buttons object and assign callBack function.
Buttons buttons;

void setup() {
  // Add Button(s) object to buttons.   
  buttons.addButton(new CustomButton());
}
void loop() {
  // Run the Buttons loop.
  buttons.run();
}
```

---

## How to install

Download .zip file from this repository, choose sketch, in "include library" choose add .zip library, choose the .zip just downloaded.

## Learn
Try the example. It is also a tutorial on class'es.




