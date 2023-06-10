#include<iostream>
using namespace std;
// Dependency Inversion Principle :- class should depend on Interfaces rather than Concrete classes.
// so that it is easy to update when needed , unlike hardCode in concrete classes.

// Interface for Mouse
class Mouse{
  public:
   virtual void mouseType()=0;
};
class wiredMouse:public Mouse{
    public:
     void mouseType(){
        cout<<"It has a Wired Mouse"<<endl;
     }
};
class wireLessMouse:public Mouse{
    public:
     void mouseType(){
        cout<<"It has a Bluetooth Mouse"<<endl;
     }
};
// Interface for Keyboard
class Keyboard{
  public:
   virtual void KeyboardType()=0;
};
class wiredKeyboard:public Keyboard{
    public:
     void KeyboardType(){
        cout<<"It has  Wired Keyboard"<<endl;
     }
};
class wireLessKeyboard:public Keyboard{
    public:
     void KeyboardType(){
        cout<<"It has Bluetooth Keyboard"<<endl;
     }
};
// Class for selecting MacBook
class MacBook{
     wiredMouse  mouse ;
     wiredKeyboard keyboard;
    public:
     MacBook(){
        mouse=wiredMouse();
        keyboard=wiredKeyboard();
     }
     void devices(){
        mouse.mouseType();
        keyboard.KeyboardType();
     }
  //Problem: we will always get wiredMouse & wiredKeyboard when we buy.here there is No choice to select for wireless. 
};

int main(){
    MacBook pc;
    cout<<"Devices:"<<endl;
    pc.devices();

 return 0;
}
