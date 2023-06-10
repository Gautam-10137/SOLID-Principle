#include<iostream>
using namespace std;
// Single Responsibility Principle :- Every class shoud have only one reason to change.
class Marker{
   public:
    string name;
    string color;
    int year;
    int price;
     
     Marker(){}
     Marker(string name,string color,int year,int price){
        this->name=name;
        this->color=color;
        this->year=year;
        this->price=price;
     }
};

class Invoice{
    private:
      Marker marker;
    public:
      int price;
      int quantity;
      Invoice(){}
      Invoice(Marker marker,int quantity){
        this->marker=marker;
        this->quantity=quantity;
        this->price=marker.price;
      }
      int calculateTotal(){
        price=(price)*quantity;
        return price;
      }
};

class InvoiceDAO{
    Invoice invoice;
    public:
      InvoiceDAO(){}
      InvoiceDAO(Invoice invoice){
        this->invoice=invoice;
      }
      void saveToDB(){
       // save Invoice in database 
      }
    
};

class printInvoice{
      Invoice invoice;
      public:
       printInvoice(Invoice invoice){
        this->invoice=invoice;
       }   

       void printIn(){
        cout<<"You purchased a totol of "<<invoice.quantity<<" markers"<<endl;
        cout<<"Each of price "<<invoice.price<<endl;
        cout<<"Total amount : "<<invoice.calculateTotal()<<endl;
       }
};

int main(){
  Marker marker;
  int quantity;
  cout<<"Enter name of marker ";
  cin>> marker.name;
  // cout<<endl;
  cout<<"Enter color of marker ";
  cin>>marker.color;
  // cout<<endl;
  cout<<"Enter price of marker ";
  cin>>marker.price;
  // cout<<endl;
  cout<<"Enter year of mfg ";
  cin>>marker.year;
  cout<<endl;

  cout<<"Enter quantity of marker ";
  cin>>quantity;

  Invoice invoice(marker,quantity);
  InvoiceDAO invoiceDAO(invoice);
  printInvoice PrintIn(invoice);
  PrintIn.printIn();
  return 0; 
}
