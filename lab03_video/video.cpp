#include <iostream>
using namespace std;

#include "video.h"

Video::Video(string title, string URL, string comment, float time, int rating){
    m_title = title;
    m_URL = URL;
    m_comment = comment;
    m_time = time;
    m_rating = rating;
}

void Video::print(){
    cout << m_title << ", " << m_URL << ", ";
    cout << m_comment << ", " << m_time << ", ";
    for(int i = 0;i<m_rating;i++){
        cout<<"*";
    }
    cout<<endl;
}