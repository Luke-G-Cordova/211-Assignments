#include <iostream>
#include <assert.h>
using namespace std;

bool is_array_sorted(int values[], int size, int start = 0){
    assert(size > 0);
    if(start+1 == size)return true;
    if(values[start] <= values[start+1])
        return is_array_sorted(values, size, start+1);
    return false;
}

int main(){
    int values[1000];
    int size;
    cout << "Enter integers.  Type control-D when done\n";
    for (size = 0; cin >> values[size]; size++)
        ;
    if (is_array_sorted(values, size))
        cout << "The values you entered ARE sorted\n";
    else
        cout << "The values you entered ARE NOT sorted\n";
}
