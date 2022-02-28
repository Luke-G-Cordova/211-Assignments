
#include <iostream>
#include "location.h"
#include <vector>
using namespace std;

int main(){
    vector<Location*> locals;
    double x, y;
    while(cin>>x){
        cin>>y;
        Location *loc = new Location(x, y);
        locals.push_back(loc);
    }
    vector<Location*>::iterator coord;
    for(coord = locals.begin();coord!=locals.end();coord++){
        (*coord)->print(cout);
        cout<<endl;
    }
}