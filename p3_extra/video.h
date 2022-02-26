// video.h
// Cordova, Luke

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;

class Video{
    public:
        Video();
        Video(string title, string URL, string comment, float length, int rating);
        void print();
        bool byLength(Video *other);
        bool byTitle(Video *other);
        bool byRating(Video *other);
        string getTitle();
        float getLength();
        int getRating();
    private:
        string m_title;
        string m_URL;
        string m_comment;
        float m_length;
        int m_rating;
};
#endif