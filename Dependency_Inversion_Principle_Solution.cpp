#include<iostream>
using namespace std;
// Dependency Inversion Principle Soln:- class should depend on Interfaces .

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
     Mouse* mouse ;
     Keyboard* keyboard;
    public:
     MacBook(){}
     MacBook(wireLessKeyboard keyboard,wireLessMouse mouse){
        this->mouse=&mouse;
        this->keyboard=&keyboard;
     }
     MacBook(wireLessKeyboard keyboard,wiredMouse mouse){
        this->mouse=&mouse;
        this->keyboard=&keyboard;
     }
     MacBook(wiredKeyboard keyboard,wireLessMouse mouse){
        this->mouse=&mouse;
        this->keyboard=&keyboard;
     }
      MacBook(wiredKeyboard keyboard,wiredMouse mouse){
        this->mouse=&mouse;
        this->keyboard=&keyboard;
     }
     void devices(){
        mouse->mouseType();
        keyboard->KeyboardType();
     }
  //Problem: we will always get wiredMouse & wiredKeyboard when we buy.here there is No choice to select for wireless. 
};

int main(){

    MacBook *pc1=new MacBook(wireLessKeyboard(),wireLessMouse());
    cout<<"Devices in pc1 :"<<endl;
    pc1->devices();

    MacBook *pc2=new MacBook(wiredKeyboard(),wireLessMouse());
    cout<<"Devices in pc2 :"<<endl;
    pc2->devices();

 return 0;
}
