## Buttons

This library is to poll input pins for changes, buttons pushed. It also gives a tutorial on class'es, on virtual and static methodes.
You create an object that inherrits the virtual class Button and re-define the action method. That catches the pin change(push) and you 
fill in the code to handle the button push. On static methodes look in example project, the class OneBtn shows how a static method is used.

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
    Serial.print(state);
    Serial.println(" custom button 1");
  }
};

// Create Buttons object and assign callBack function.
Buttons buttons;

void setup() {
Serial.begin(9600);
  // Add Button(s) object to buttons.   
  buttons.addButton(new CustomButton());
}
void loop() {
  // Run the Buttons loop.
  buttons.run();
}
```


## How to install

Download .zip file from this repository, choose sketch, in "include library" choose add .zip library, choose the .zip just downloaded.
## or
Move to arduino/libraries
open terminal in directory and write
```
git clone https://github.com/drsubs/Buttons.git
```


restart arduino ide

done

## Learn
Try the example. It is also a tutorial on class'es.

## Example

This is the example setup, useing an Arduino UNO


##

<picture>
  <img src="https://github.com/drsubs/Buttons/blob/main/examples/Buttons/Buttons.png">
</picture>



