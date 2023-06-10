#include<iostream>
using namespace std;
// Interface Segmented Principle :- Interface should be such that client should not implement unnecessary function they do not need.
class restaurantEmployee{
    public:
     virtual void washDishes()=0;
     virtual void serveCustomers()=0;
     virtual void cookFood()=0;
};
// Problem: Here waiter class has to implement unnecessary methods because of interface.
class waiter: public restaurantEmployee{
    public:
     void washDishes(){
     // This is not a work of waiter. 
     }
     void serveCustomers(){
        cout<<"Serving the Customer"<<endl;
     }
     void cookFood(){
       // This is not a work of waiter. 
     }
};

int main(){
    waiter wt;
    wt.serveCustomers();

    return 0;
}
