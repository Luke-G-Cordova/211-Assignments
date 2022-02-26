#include <iostream>
using namespace std;
#include "dstack.h"

int main()
{
    Dstack stack;
    double value;
    while(cin >> value){
        stack.push(value);
    }
    cout << "There are " << stack.size() << " numbers in the stack." << endl;
    while(stack.pop(value)){
        cout << value << endl;
    }
    cout << "There are " << stack.size() << " numbers in the stack." << endl;
    return 0;
}
