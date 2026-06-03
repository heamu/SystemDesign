#include<bits/stdc++.h>
using namespace std;


/*
                                BUILDER DESIGN PATTERN
 1. Builder design pattern is a creational design pattern 
 2. consider classess with too many optional properties or variables with in it 
 3. suppose class Student has one important field that is roll number but it can have many OPTIONAL methods
 4. so the constructor becomes viry larger if we want to include all of them 
 5  another propblem is  since many of them are optional we are supposed to create many Constructors with
 6. different combinations of fields as parameters 
 7. examples of Constructors -> Student(roll) , Student(roll,name) , Student(roll,age),Student(roll,name,age)...
 8. another main issue is suppose consider a constructor
 9. Student(int roll , string name , string father_name)
 10 Student(int roll,string mother_name,string father_name)
 11.since bith constructors have same function signature it raises to error 
 12 . Student(int,string,string) so this is also another problem(compile time error)
*/

/*
so we will try to implement a car cals along with its builder calss known as CarBuilder
*/

class Car{
    string engine="";
    int milage=0;
    int totalKmDriven=0;
    string model="";
    string seats_count="";
    string fuel_type="";
    int max_speed=0;
    public:

    void onEngine(){
        cout<<"engine "<<engine<<" has been turned on"<<endl;
    }
    void drive(){
        cout<<"Auto drive is on"<<endl;
    }
    
    void displayCar() {
        cout << "\n------ Car Details ------\n";
        cout << "Engine       : " << engine << endl;
        cout << "Mileage      : " << milage << " km/l" << endl;
        cout << "Total Driven : " << totalKmDriven << " km" << endl;
        cout << "Model        : " << model << endl;
        cout << "Seats        : " << seats_count << endl;
        cout << "Fuel Type    : " << fuel_type << endl;
        cout << "Max Speed    : " << max_speed << " km/h" << endl;
        cout << "--------------------------\n";
    }

    friend class CarBuilder;
    //some other functionalities

};

class CarBuilder{
    Car*car;//since we can develop car interface enabling sports car normal car offroad car and all
    public:
    CarBuilder(){
        car = new Car();
    }
    CarBuilder setEngine(string engine){
        car->engine = engine;
        return *this;//so we are trutning the same obj;
    }
    CarBuilder setMilage(int milage){
        car->milage = milage;
        return *this;//so we are trutning the same obj;
    }
    CarBuilder setTotalKM(int km){
        car->totalKmDriven = km;
        return *this;//so we are trutning the same obj;
    }
    CarBuilder setMode(string model){
        car->model = model;
        return *this;//so we are trutning the same obj;
    }
    CarBuilder setseatsCount(int ct){
        car->seats_count = ct;
        return *this;//so we are trutning the same obj;
    }

    CarBuilder setMaxspeed(int cmx){
        car->max_speed = cmx;
        return *this;//so we are trutning the same obj;
    }
    CarBuilder setFuelType(string fuel){
        car->fuel_type = fuel;
        return *this;//so we are trutning the same obj;
    }
    
    //this is the important function builder which returns the object;
    Car* builder(){
        return car;
    }

};



int main(){
    // now we can make use of carBuilder class enabling us not to create multiple ocnstructors
    Car*myCar = CarBuilder().setEngine("V8 engine").setFuelType("diesel").setMaxspeed(250).builder();
    myCar->displayCar();
    return 0;
}