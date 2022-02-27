// video.cpp
// Cordova, Luke
#include <iostream>
#include "video.h"
using namespace std;


Video::Video(string title, string URL, string comment, float length, int rating){
    m_title = title;
    m_URL = URL;
    m_comment = comment;
    m_length = length;
    m_rating = rating;
}
void Video::print(){
    cout << m_title << ", " << m_URL << ", ";
    cout << m_comment << ", " << m_length << ", ";
    for(int i = 0;i<m_rating;i++){
        cout<<"*";
    }
    cout<<endl;
}

bool Video::byRating(Video *other){
    return m_rating > other->m_rating;
}
bool Video::byTitle(Video *other){
    return m_title > other->m_title;
}
bool Video::byLength(Video *other){
    return m_length > other->m_length;
}
string Video::getTitle(){
    return m_title;
}