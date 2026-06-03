#include<bits/stdc++.h>
using namespace std;


/*
 1. Strategy Design pattern came to solve the issue of inheritance
 2. Composition is better than inheritance
 3. Inheritance is 'is-a' relationship Composition is 'has-a' relationship
 4. Insted of directly implementing the functionalities we will have strategy classes for them to implemnt
 5. suppose a vehicle will have a drive() fuinctionality instead of directly implementing it
 6. we will make that vehicle will have driveStrategy()
 7 similiarly we will make that vehicle will have a transmission() strategy instead of transmission class 
 8. directly implemented with in the classes
*/


//we will implement DriveStrategy class 

class DriveStrategyInterface{
    public :
    virtual void drive()=0;
};
class NormalDrive : public DriveStrategyInterface{
    public:
    void drive(){
        cout<<"This is a normal drive functionality.."<<endl;
    }
};
class SpecialDrive : public DriveStrategyInterface{
    public:
    void drive(){
        cout<<"This is a special drive functionality.."<<endl;
    }
};

class Vehicle{
    public:
    int seats;
    string color;
    DriveStrategyInterface* driveStrategy;
    Vehicle(int seats , string color ,DriveStrategyInterface* driveStrategy){
        this->seats = seats;
        this->color = color;
        this->driveStrategy = driveStrategy;
    }
    ~Vehicle(){
        cout<<"We are in Vehicle destructor"<<endl;
        delete driveStrategy;
    }
};

class NormalCar :public Vehicle{
    public:
    NormalCar(int seats,string color):Vehicle(seats,color,new NormalDrive()){

    }
    ~NormalCar(){
        cout<<"we are in Normal car destructor"<<endl;
    }
};

class SportsCar :public Vehicle{
    public:
    SportsCar(int seats,string color):Vehicle(seats,color,new SpecialDrive()){

    }
    ~SportsCar(){
        cout<<"we are in SportsCar destructor"<<endl;
        
    }
};

class OffRoadCar :public Vehicle{
    public:
    OffRoadCar(int seats,string color):Vehicle(seats,color,new SpecialDrive()){

    }
    ~OffRoadCar(){
        cout<<"we are in OffRoadCar destructor"<<endl;
        delete driveStrategy;
    }
};

int main(){
    NormalCar swift(4,"red");
    SportsCar F1(1,"Blue");
    OffRoadCar mahindra(4,"Black");

    //see the drive function is called accordingly;
    swift.driveStrategy->drive();
    F1.driveStrategy->drive();
    mahindra.driveStrategy->drive();
}