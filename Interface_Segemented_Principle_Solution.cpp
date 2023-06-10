#include<iostream>
using namespace std;
// Interface Segmented Principle Soln :- Interface should be such that client should implement only function they need.
// Segment the interface according to common methods of each type of employee.

// Interface for waiter class
class waiterInterface{
    public:
     virtual void serveCustomers()=0;
     virtual void takeOrders()=0;
};
class waiter: public  waiterInterface{
    public:
     void serveCustomers(){
        cout<<"Serving the customers."<<endl;
     }
     void takeOrders(){
        cout<<"Hello Sir/Mam ,Tell me your  order."<<endl;
     }
};
// Interface for chef class
class chefInterface{
    public:
     virtual void cookFood();
     virtual void decideMenu();
};
class chef: public chefInterface{
    public:
     void cookFood(){
        cout<<"Lets cook Sweet Dishes!"<<endl;
     }
     void decideMenu(){
        cout<<"Lets decide a Menu."<<endl;
     }
};
int main(){
    chef chef;
    waiter waiter; 
    chef.decideMenu();
    waiter.takeOrders();
    chef.cookFood();
    waiter.serveCustomers();

    return 0;
}
