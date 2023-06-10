#include<iostream>
using namespace std;
// Liskov-Substitution principle:- Subclass should extend the capability of parent class,not narrow it down.
// e.g. If class B is subclass of class A,then we should be able to replace object of A with B without breaking the behaviour of program.
class bike{
    public:
     virtual void turnOnEngine();
     virtual void accelerate();
};
class MotorCycle: public bike{
       bool isEngineOn;
       int speed;
       public:
       MotorCycle(){
        speed=0;
       }
       void startRun(){
        speed=10;
       }
        void turnOnEngine(){
            isEngineOn=true;
        }
        void accelerate(){
            speed+=10;
        }
};
class BiCycle: public bike{
    int speed;
     public:
      void startRun(){
        speed=5;
      }
      void turnOnEngine(){
        throw "There is no engine";   // here it changed the behaviour of bike class.
      }
      void accelerate(){
        speed+=2;
      }
};
int main(){

}
