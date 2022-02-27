// video.cpp
// Cordova, Luke
#include <iostream>
#include "dstack.h"
#include <stdlib.h>
#include <math.h>
using namespace std;

bool ERROR(){
    cerr << "Error: Invalid expression." << endl;
    return 1;
}

int main(){
    Dstack stack;
    
    char next;
    double num;
    char op;
    string ec;
    double n1, n2;
    while((next = cin.peek()) != -1){
        if(isspace(next)){
            cin.ignore();
        }else if(isdigit(next) || next == '.'){
            cin>>num;
            stack.push(num);
            if(
                (
                    !isspace(cin.peek()) && 
                    !ispunct(cin.peek()) && 
                    !isalpha(cin.peek())
                ) || 
                cin.peek() == '.'
            ){
                return ERROR();
            }
        }else if(ispunct(next)){
            cin>>op;
            if(!stack.pop(n1) || !stack.pop(n2)){
                return ERROR();
            }
            switch(op){
                case '+':
                    stack.push(n2+n1);
                    break;
                case '-':
                    stack.push(n2-n1);
                    break;
                case '*':
                    stack.push(n2*n1);
                    break;
                case '/':
                    if(n1 == 0){
                        return ERROR();
                    }
                    stack.push(n2/n1);
                    break;
                case '^':
                    stack.push(pow(n2, n1));
                    break;
                default:
                    return ERROR();
                    break;
            }
        }else if(isalpha(next)){
            cin>>ec;
            if(!stack.pop(n1)){
                return ERROR();
            }
            if(ec == "sqrt"){
                stack.push(sqrt(n1));
            }else if(ec == "cos"){
                n1 *= M_PI/180;
                stack.push(cos(n1));
            }else if(ec == "sin"){
                n1 *= M_PI/180;
                stack.push(sin(n1));
            }else if(ec == "ave"){
                double avg = n1;
                int count = 1;
                while(stack.pop(n1)){
                    avg += n1;
                    count++;
                }
                stack.push(avg/count);
            }else{
                return ERROR();
            }
        }else{
            return ERROR();
        }
    }
    if(stack.size()==1){
        stack.pop(n1);
        cout<<n1<<endl;
    }else{
        return ERROR();
    }
    
    return 0;
}


