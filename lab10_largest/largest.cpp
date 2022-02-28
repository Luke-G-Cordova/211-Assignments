#include <iostream>
#include <assert.h>
using namespace std;

int largest_in_array(int values[], int size, int start = 0, int biggest = 0){
    assert(size > 0);
    if(start == size)return biggest;
    if(start == 0)return largest_in_array(values, size, start+1, values[start]);
    if(biggest < values[start])return largest_in_array(values, size, start+1, values[start]);
    return biggest;
}

int main(){
    int values[1000];
    int size;
    cout << "Enter integers.  Type control-D when done\n";
    for (size = 0; cin >> values[size]; size++)
        ;
    cout << "The largest value is " << largest_in_array(values, size) << endl;
}
