#include<bits/stdc++.h>
using namespace std;

/*
                                OBSERVER DESIGN PATTERN
    
    1.Consider that you have two entites named as Observable and the second one as Observer 
    2.When ever there is a change in Observable entity we have to notify the observer pattern
    3.Here what we will try to do is that consider that we have product abstract class which can be observed by a emailAlert , msgAlert
*/



class AlertInterface;

class AlertInterface{
    public:
    virtual void update()=0;
};





class EmailAlert:public AlertInterface{
    string email;
    public:
    EmailAlert(string email):email(email){};
    void update(){
        cout<<endl<<"mail : hurry up product has became instock "<<endl;
        cout<<"mail has sent to : "<<email<<endl;
    }
};

class MsgAlert:public AlertInterface{
    string userName;
    public:
    MsgAlert(string userName):userName(userName){};
    void update(){
        cout<<endl<<"msg : hurry up product has became instock "<<endl;
        cout<<"msg has sent to : "<<userName<<endl;
    }
};

class Product{
    public:
    string name;
    string _id;
    int price;
    int quantity;
    vector<AlertInterface*> listOfObservers;

    Product(string name , string _id,int price , int quantity):name(name),_id(_id),price(price),quantity(quantity){}

    void getDetails(){
        cout<<endl<<"..................."<<name<<"...................."<<endl;
        cout<<"_id : "<<_id<<endl;
        cout<<"price : "<<price<<endl;
        cout<<"quantity : "<<quantity<<endl;
        cout<<"..................................................."<<endl<<endl;
    }

    //we will notify to all the observer through this notify function
    void notify(){
        for(auto observerObj : listOfObservers){
            observerObj->update();
        }
    }
        
    //when ever quantity becomes greater than 0 notify to all the observers
    void setQuantity(int value){
         quantity=value;
        if(quantity==0){
            notify();
        }
    }

    void addObserver(AlertInterface*newObserver){
        listOfObservers.push_back(newObserver);
    }
    ~Product(){
        for(auto&i:listOfObservers){
            delete i;
        }
    }

};


class Iphone:public Product{
    public:
    Iphone(string name , string _id,int price , int quantity):Product(name,_id,price,quantity){}
};





int main(){

    cout<<"Hello "<<endl;
    Iphone iphone("iphone","234123",23000,10);
    
    iphone.addObserver(new EmailAlert("hemanth@gmail.com"));
    iphone.addObserver(new EmailAlert("kumsr@gmail.com"));
    iphone.addObserver(new MsgAlert("bombu"));

    iphone.setQuantity(0);
    iphone.setQuantity(10);
    return 0;
}