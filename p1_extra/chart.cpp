// chart.cpp
// Cordova, Luke

#include <iostream>
using namespace std;

// finds the largest value in values
int find_largest(int values[], int size);

// prints the output in the desired orientation
// 0 = 0 degrees 1 = 90 degrees 2 = 180 degrees 3 = 270 degrees
void print(int values[], int size, int direction);

int main(){
    const int MAX = 100;
    int values[MAX];
    int size = 0;
    while(cin >> values[size] && values[size] != 0 && (size++) != MAX );

    print(values, size, 0);
    cout<<endl;
    print(values, size, 2);
    cout<<endl;
    print(values, size, 1);
    cout<<endl;
    print(values, size, 3);
    
    return 0;
}

int find_largest(int values[], int size){
    int largest = 0;
    for(int i = 0;i<size;++i){
        if(values[i] > largest) largest = values[i];
    }
    return largest;
}

void print(int values[], int size, int direction){
    int largest = find_largest(values, size);
    if(direction == 0){
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
    }else if(direction == 1){
        for(int height = 0;height<size;height++){
            for(int width = 0;width<values[height];width++){
                cout<<"*";
            }
            cout<<endl;
        }
    }else if(direction == 2){
        for(int height = 1;height<=largest;height++){
            for(int width = 0;width<size;width++){
                if(height<=values[width]){
                    cout << "*";
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }else if(direction == 3){
        for(int height = 0;height<size;height++){
            for(int width = largest;width>0;width--){
                if(width<=values[height]){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
    
}