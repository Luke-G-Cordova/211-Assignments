#include <iostream>
#include <ctype.h>
#include <assert.h>
using namespace std;

const char nums[11] = "0123456789";

bool isDigit(char let, int start = 0){
    if(nums[start]=='\0') return false;
    if(let == nums[start]) return true;
    return isDigit(let, start+1);
}
bool is_int(char str[], int start = 0){
    if(str[start] == '\0')return true;
    if(isDigit(str[start])){
        return is_int(str, start+1);
    }
    return false;
}

int main(){
    char buf[1000];
    cout << "Enter a string: ";
    cin >> buf;

    if (is_int(buf))
    cout << "<" << buf << "> is an integer.\n";
    else cout << "<" << buf << "> is NOT an integer.\n";
}
