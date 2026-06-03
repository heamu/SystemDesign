#include<bits/stdc++.h>
using namespace std;

/*                          PROXY DESIGN PATTERN

1. we use proxy design pattern when ever there is a client requestiong for data 
2. instead of directly passing request to the class driectly we will place a proxy class in between 
3. this proxy class will perform necessary checks needed and then pass the request to the orginal class
4. Each proxy class "has-a"original class object along with it as we can see from the code
*/


class DBInterface{
    public:
    virtual void get(string role , int _id)=0;
    virtual void create(string role , string name) =0;
    virtual void deleteData(string role ,int _id)=0;
};

class MongoDB : public DBInterface{
    public:
    void get(string role  , int _id){
        cout<<"Employe with id  "<<_id<<" has been retrieved";
    }
    void create(string role  , string name){
        cout<<"Employe  "<<name<<" has been retrieved";
    }
    void deleteData(string role  , int _id){
        cout<<"Employe with id  "<<_id<<" has been deleted";
    }
};

class MongoDBProxy : public DBInterface{
    MongoDB db;
    public:
    
    void get(string role  , int _id){
         if(role=="USER"||role=="Admin")
         db.get(role,_id);
         else cout<<"You are not authorized"<<endl;
    }
    void create(string role  , string name){
        
        if(role=="Admin")db.create(role,name);
        else cout<<"You are not authorized"<<endl;
    }
    void deleteData(string role  , int _id){
        if(role=="Admin")db.deleteData(role,_id);
        else cout<<"You are not authorized"<<endl;
    }
};




int main(){

    MongoDBProxy px;
    px.create("USER","hemanth");
    px.create("Admin","hemanth");
    px.get("USER",1);

}