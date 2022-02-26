#include <iostream>
using namespace std;
#include "list.h"

int main()
{
    List list;
    int num;
    while(cin >> num){
        list.insert_at_end(num);
    }
    list.print();
    cout << "sum = "<<list.sum()<< endl;
    return 0;
}
