#include <iostream>
using namespace std;


bool equal_string(const char str1[], const char str2[], int start = 0){
    if(str1[start] == '\0'&&str2[start] == '\0')return true;
    if(str1[start] == str2[start]){
        return equal_string(str1, str2, start+1);
    }
    return false;
}





int main(){
    char str1[1000], str2[1000];

    // initialize str1 and str2 to empty
    str1[0] = 0;
    str2[0] = 0;

    cout << "enter first string: ";
    cin >> str1;
    cout << "enter second string: ";
    cin >> str2;

    if (equal_string(str1, str2))
    cout << "<" << str1 << "> is equal to <" << str2 << ">\n";
    else cout << "<" << str1 << "> is NOT equal to <" << str2 << ">\n";
}
