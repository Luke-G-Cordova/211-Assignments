// chart.cpp
// Cordova, Luke

#include <iostream>
using namespace std;

int find_largest(int values[], int size);

int main(){
    const int MAX = 100;
    int values[MAX];
    int size = 0;
    while(cin >> values[size] && values[size] != 0 && (size++) != MAX );
    int largest = find_largest(values, size);
    for(int height = largest;height>0;height--){
        for(int width = 0;width<size;width++){
            if(height<=values[width]){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

int find_largest(int values[], int size){
    int largest = 0;
    for(int i = 0;i<size;++i){
        if(values[i] > largest) largest = values[i];
    }
    return largest;
}