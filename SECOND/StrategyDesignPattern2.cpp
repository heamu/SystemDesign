#include<bits/stdc++.h>
using namespace std;

//  i want to implement strategy design pattern by the way here 

//this one with no strategy design pattern 

class Vehicle{
    int seats;
    int lights;
    int wheels;
    public:
    Vehicle(){
        seats = 5;
        lights = 4;
        wheels = 4;
    }

    void drive(){
        cout<<" we are using normal drive function here "<<endl;
    }

    void fuel(){
        cout<<"We are using normal fueling strategy here"<<endl;
    }

};


class SportsCar: public Vehicle{
    public:
    void drive(){
        cout<<"Here we are using special driving functionality"<<endl;
    }
};

class  NormalCar : public Vehicle{
    public:
};

class OffRoadCar : public Vehicle{
     public:
    void drive(){
        cout<<"Here we are using special driving functionality"<<endl;
    }
};

//see upto here we are forced to write the same drive function for OffroadCar  and SPorts car
//if try to write a common class like special car and make the offroadCar and Sports car inherit from
// the special car then at some point this leads to class explosion



class Svehicle{
    int seats,lights,wheels;
    public:
    DrivingInterface *drivefunction;
    FuelingInterface *fuelfunction;
    Svehicle(DrivingInterface *drivefunction,FuelingInterface *fuelfunction){
        this->drivefunction = drivefunction;
        this->fuelfunction = fuelfunction;
    }
};

class SSportsCar:public Svehicle{
public:
SSportsCar(): Svehicle(new SpecialDrive(),new NormalFuel()){

}
};

class SNormalCar:public Svehicle{
    public:
    SNormalCar():Svehicle(new NormalCar(),new NormalFuel()){

    }
};

class F1Car:public Svehicle{
    F1Car():Svehicle(new SpecialDrive(),new SpecialFuel()){

    }
};


class DrivingInterface{
    public:
    virtual void drive() = 0;
};

class SpecialDrive : public DrivingInterface{
    public:
    void drive()override{
        cout<<"This is special driving functionality"<<endl;
    }
};

class NormalDrive: public DrivingInterface{
    public:
    void drive()override{
        cout<<"This is a normal driving functionality"<<endl;
    }
};


class FuelingInterface{
    public:
    virtual void fuel() = 0;
};

class SpecialFuel : public FuelingInterface{
    public:
    void fuel()override{
        cout<<"This is special fueling functionality"<<endl;
    }
};

class NormalFuel: public FuelingInterface{
    public:
    void fuel()override{
        cout<<"This is a normal fueling functionality"<<endl;
    }
};







int main(){
  
    return 0;
}


