#include<bits/stdc++.h>
using namespace std;

/*                                   DECORATOR PATTERN
 1.Consider intitially you have a base class with feature f1 and u want to have some another class 
 2.with feature f1+f2 and u may need another class with feature f1+f3 or u may need f1+f2+f3
 3.so for every new combination of features with base class we can create a new class which will lead to
 4.the problem of 'class explosion'
 5.ex : base pizza , base pizza + extra cheese , base pizza + extra onions , base pizza + extra cheese + extra onions classes
 6.So this problem can be solved using decorator pattern which allow you to wrap the base class 
 7. with decorator classes allowing you to choose features you want to add dynamically;
 8.so decorator patter allows you to perform dynamic composition 
*/

/*for this i am going to use friedrice class */
/*base fried rice class having concrete classes as chicken fried rice , egg fried rice , vegfriedrice*/
/*toppings as extra chicken extra egg , extra veggies and extra oil*/


class FriedRice{
    public :
    string ingredients = "The rice , oil , veggies ";
      int cost;
      virtual int getCost(){
        return cost;
      }
      virtual void displayIngredients(){
        cout<<"Ingredients are : "<<ingredients<<endl;
      }
      virtual void displayCost(){
        cout<<"Cost : "<<getCost()<<endl;
        return;
      }
};

class EggFriedRice : public FriedRice{
    public:
    EggFriedRice(){
        ingredients += "Egg ";
        cost = 100;
    }
};

class ChickenFriedRice : public FriedRice{
    public:
    ChickenFriedRice(){
        ingredients += "Chicken ";
        cost = 150;
    }
};

class VegFriedRice : public FriedRice{
    public:
    VegFriedRice(){
        ingredients += "Ghobi ";
        cost = 80;
    }
};


class TopingsDecorator : public FriedRice{
    public :
    FriedRice* friedRice;
    virtual ~TopingsDecorator(){
        delete friedRice;
    }
};

class ExtraChicken : public TopingsDecorator{
    public:
    ExtraChicken(FriedRice* friedRice){
        this->friedRice = friedRice;
        this->ingredients =  friedRice->ingredients+" extraChicken  ";
        this->cost = friedRice->cost + 50;
    }

};
class ExtraEgg : public TopingsDecorator{
    public:
    ExtraEgg(FriedRice* friedRice){
        this->friedRice = friedRice;
        this->ingredients =  friedRice->ingredients+" ExtraEgg ";
        this->cost = friedRice->cost + 30;
    }
};
class ExtraVeggies : public TopingsDecorator{
    public:
    ExtraVeggies(FriedRice* friedRice){
        this->friedRice = friedRice;
        this->ingredients =  friedRice->ingredients+" ExtraVeggies ";
        this->cost = friedRice->cost + 10;
    }
};


int main(){

    FriedRice * fr = new ExtraVeggies( new ExtraChicken(new ChickenFriedRice()));

    fr->displayCost();
    fr->displayIngredients();
    
    delete fr;
}

