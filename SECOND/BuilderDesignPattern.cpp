#include<bits/stdc++.h>
using namespace std;

//this is another way of implementing Builder design pattern so i made this 


class A{
    int a;
    int b;
    int c;
    int d;
    public:
        A(int a , int b , int c , int d){
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
        }
    int method1(){
        cout<<"I have implemented this function just because to make this class look good.";
        return 69;
    }

    int method2(){
        cout<<"I cant keep the first function alone so this is implemented by me.";
        return 13;
    }
    void method3(){
        cout<<"Suddenly i got to know that i need this "<<endl;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    //the builder of this class is implemented with in the same class;
    class BuildA{
        int a,b,c,d;
        public:
        BuildA(){
            this->a = 0;
            this->b = 0;
            this->c = 0;
            this->d = 0;
        }
        BuildA& setA(int a){
            this->a = a;
            return *this;
        }
        BuildA& setB(int b){
            this->b = b;
            return *this;
        }
        BuildA& setC(int c){
            this->c = c;
            return *this;

        }
        BuildA& setD(int d){
            this->d = d;
            return *this;
        }
        A*build(){
            return new A(a,b,c,d);
        }
    };
};


int main(){
     A* Ma = A::BuildA().setA(23).setB(34).build();
        Ma->method3();
    return 0;
}