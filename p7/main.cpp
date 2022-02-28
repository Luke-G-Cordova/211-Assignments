// video.cpp
// Cordova, Luke
#include <iostream>
#include <vector>
#include <queue>
#include "bst.h"
using namespace std;

string *parse_commands(string command);
int main(){
    BST bst;
    string command;
    while(getline(cin, command)){
        string *args;
        args = parse_commands(command);
        if(args[0] == "echo"){
            cout<<args[1]<<endl;
        }else if(args[0] == "insert"){
            if(!bst.insert(args[1])){
                cerr<<"insert <"<<args[1]<<"> failed. String already in tree."<<endl;
            }
        }else if(args[0] == "size"){
            cout<<bst.size()<<endl;
        }else if(args[0] == "find"){
                cout<<"<"<<args[1]<<"> is"<<(bst.find(args[1])?" ":" not ")<<"in tree."<<endl;
        }else if(args[0] == "print"){
            vector<string> values;
            bst.print(values);
            vector<string>::iterator value;
            cout<<"{";
            for(value = values.begin();value!=values.end();value++){
                cout<<(*value);
                if(value+1 != values.end()){
                    cout<<", ";
                }
            }
            cout<<"}"<<endl;
        }else if(args[0] == "breadth"){
            queue<string> values;
            bst.breadth(values);
            cout<<"{";
            while(values.size()!=0){
                cout<<values.front();
                values.pop();
                if(values.size()!=0)cout<<", ";
            }
            cout<<"}"<<endl;
        }else if(args[0] == "distance"){
            cout<<"Average distance of nodes to root = "<<bst.distance()<<endl;
        }else if(args[0] == "balanced"){
            cout<<"Tree is"<<(bst.ballanced()==-1?" not ":" ")<<"balanced."<<endl;
        }else if(args[0] == "rebalance"){
            bst.reballance();
        }else{
            cerr<<"Illegal command <"<<args[0]<<">."<<endl;
        }
    }
    return 0;
}
string *parse_commands(string command){
    string current = "";
    bool skip = false;
    string *args = new string[2];
    for(int i = 0;command[i] != '\0';i++){
        if(isspace(command[i]) && !skip){
            skip = true;
            args[0] = current;
            current = "";
        }else{
            current += command[i];
        }
    }
    args[skip] = current;
    return args;
}