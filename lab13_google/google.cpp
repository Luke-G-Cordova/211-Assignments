#include <iostream>
#include "location.h"
#include <map>
using namespace std;

int main(){
    map<string, Location*> my_map;

    double x, y;
    string name;
    while(cin>>x && x != 0){
        cin>>y;
        cin>>name;
        my_map[name] = new Location(x, y);
    }
    while(cin>>name){
        map<string, Location*>::iterator iter;
        iter = my_map.find(name);
        if(iter == my_map.end()){
            cout<<name<<" not in database"<<endl;
        }else{
            cout<<name<<" is at ";
            iter->second->printURL(cout);
            cout<<endl;
        }
    }

}