// main.cpp
// Cordova, Luke

#include <iostream>
#include "video.h"
using namespace std;

int main(){
    const int MAX = 100;
    Video* videos[MAX] = {NULL};
    string sort;
    int size = 0;
    getline(cin, sort);
    if(sort!="rating"&&sort!="length"&&sort!="title"){
        cerr << sort << " is not a legal sorting method, giving up." << endl;
        return 1;
    }
    
    string title, URL, comment;
    float length;
    int rating;
    while(getline(cin, title)){
        getline(cin, URL);
        getline(cin, comment);
        cin >> length;
        cin >> rating;
        cin.ignore();
        videos[size] = new Video(title, URL, comment, length, rating);
        size++;
        if(size==MAX){
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
    }
    for(int last = size-1;last > 0;last--){
        for(int cur = 0;cur<last;cur++){
            if(sort == "length" && videos[cur]->byLength(videos[cur+1])){
                swap(videos[cur], videos[cur+1]);
            }else if(sort == "rating" && videos[cur]->byRating(videos[cur+1])){
                swap(videos[cur], videos[cur+1]);
            }else if(sort == "title" && videos[cur]->byTitle(videos[cur+1])){
                swap(videos[cur], videos[cur+1]);
            }
        }
    }
    for(int i = 0;i<size;i++){
        videos[i]->print();
    }
    return 0;
}