// video.cpp
// Cordova, Luke
#include <iostream>
#include "video.h"
using namespace std;

Video::Video(string title, string URL, string comment, float length, int rating){
    Video::title = title;
    Video::URL = URL;
    Video::comment = comment;
    Video::length = length;
    Video::rating = rating;
}
void Video::print(){
    cout << title << ", " << URL << ", ";
    cout << comment << ", " << length << ", ";
    for(int i = 0;i<rating;i++){
        cout<<"*";
    }
    cout<<endl;
}

bool Video::byRating(Video *other){
    return rating < other->rating;
}
bool Video::byTitle(Video *other){
    return title > other->title;
}
bool Video::byLength(Video *other){
    return length > other->length;
}