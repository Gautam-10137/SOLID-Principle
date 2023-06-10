#include<iostream>
#include<vector>
using namespace std;
// Liskov-Substitution principle Soln :- add only generic properties in parent class that every child must have .
class vehicle{
     
    public:
     string name="Vehicle";
     int wheels=2;
     int getNumberOfWheels(){
        return wheels;
     };
};
class BiCycle: public vehicle{
     public:
      BiCycle(){
        name="Bicycle";
        wheels=2;
      }
      int getNumberOfWheels(){
        return 4;
      }

};
//  making another generic class for vehicle having engine
class engineVehicle: public vehicle{
    public:
    
     bool hasEngine(){
        return true;
     }  

     
};
class MotorCycle: public engineVehicle{
       
       public:

       MotorCycle(){
           name="MotorCycle";
           wheels=2;
       }

        int getNumberOfWheels(){
               return 2;
        }
        

};
class Car: public engineVehicle{
       
       public:
      
       Car(){
        name="Car";
        wheels=4;
       }
        int getNumberOfWheels(){
               return 4;
        }

  
};

int main(){
    // Accessing generic properties for all vehicles.
      vector<vehicle> v1;
      v1.push_back(MotorCycle());
      v1.push_back(Car());
      v1.push_back(BiCycle());
      for(vehicle it:v1){
        cout<<"Number of wheels in "<<it.name<<" :"<<it.wheels<<endl;
      }

    // Accessing generic properties of vehicles having Engine. 
      vector<engineVehicle> v2;
      v2.push_back(MotorCycle());
      v2.push_back(Car());
      for(engineVehicle vehicle: v2){
        if(vehicle.hasEngine()){
        cout<<vehicle.name <<" has Engine "<<endl;
        }
      }

      return 0;

}
