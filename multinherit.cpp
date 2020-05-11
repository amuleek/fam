# include<iostream>
using namespace std;
class Bike{
public:
int engine_cost;
void set_engine_cost(int x){
engine_cost=x;
}
};
class Car{
protected:
int Model_no;
public:
void set_Model_no(int p)
{
Model_no=p;
}
};
class Vehical: public Car, public Bike
{
int no_of_wheels;
public:
Vehical(int w)
{
no_of_wheels=w;
cout<<"no of wheels - "<<no_of_wheels<<"\n";
}
void display_Vehical_info( ){
cout<<"engine cost of bike - "<< engine_cost<<"\n"; // If the engine_cost could have declared as private, it would not be accessed by Bike and vehicle directly.
cout<<"Model no of car is - "<< Model_no<<"\n"; // legal because Model_no is private to Car but accessible by vehicle.
}
};
int main()
{
Vehical V(4);
V.set_engine_cost(12000);
V.set_Model_no(1021);
V.display_Vehical_info( );
}
