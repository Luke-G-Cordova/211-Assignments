
#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;

class Video{
    public:
        Video(string title, string URL, string comment, float time, int rating);
        void print();
    private:
        string m_title, m_URL, m_comment;
        float m_time;
        int m_rating;
};

#endif