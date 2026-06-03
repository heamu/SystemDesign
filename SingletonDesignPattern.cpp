#include<bits/stdc++.h>
using namespace std;


/*
                            SINGLETON DESIGN PATTERN
 1. singleton design pattern is used when we need only one instance of a class
 2. suppose there is a db connection class then some times we need only one connection to the db;
 3. this can be achieved using this pattern
 4. we can implement using two ways one is eager another is lazy or whenever need;
*/

class DBconnection {
    DBconnection() {
        cout << "A connection to the database has been established" << endl;
    }
public:
    DBconnection(const DBconnection&) = delete;
    DBconnection& operator=(const DBconnection&) = delete;

    static DBconnection& getInstance() {
         // see here since it is static it is initialized only once buhahaha
        static DBconnection instance;
        return instance;
    }
};





DBconnection db;//this is eager evaluation;


int main(){
    return 0;
}