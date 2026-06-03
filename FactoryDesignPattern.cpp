#include<bits/stdc++.h>
using namespace std;

/*
                                FACTORY DESIGN PATTERN
 1. so every time we want to instantiate class we will write that as new className() 
 2. suppose that you want to create a class only if certain condition are met
 3. then every where you are instantiating a class you are going to  write the conditional logic;
 4. instead you can create factory which maintains that conditional logic 
 5. so you dont need repeat the conditions

*/

class Shape{
    public:
        virtual double caliculateArea()=0;
        virtual void displayArea()=0;
        virtual ~Shape(){};
};
class Circle:public Shape{
    const double pi;
    int r;
    Circle(int r):r(r),pi(3.14){};
    virtual double caliculateArea(){
        return pi*r*r;
    }
    virtual void displayArea(){
        cout<<"The area of the circle is : "<<caliculateArea()<<endl;
    }
    ~Circle(){};
};

class Square:public Shape{
    int side;
    Square(int side):side(side){};
    virtual double caliculateArea(){
        return side*side;
    }
    virtual void displayArea(){
        cout<<"The area of the Square is : "<<caliculateArea()<<endl;
    }
    ~Square(){};
};


class ShapeFactory{
    public:
    Square* getShapeInstance(){
        
    }
};

int main(){
    
}