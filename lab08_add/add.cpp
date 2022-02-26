#include <iostream>
#include <stdlib.h>
using namespace std;


bool legal_int(char* str);


int main(int argc, char *argv[]){
    int sum = 0;
    for(int i = 1;i<argc;i++){
        if(legal_int(argv[i])){
            sum += atoi(argv[i]);
        }else{
            cerr << "Error: illegal integer." << endl;
            return 1;
        }
    }
    cout << sum << endl;
    return 0;
}

bool legal_int(char* str){
    int size = 0;
    while(*(str + size) != 0){
        if(!isdigit(*(str+size))){
            return false;
        }
        size++;
    }
    return true;
}
