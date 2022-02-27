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
        bool byLengthE(Video *other);
        bool byTitle(Video *other);
        bool byTitleE(Video *other);
        bool byRating(Video *other);
        bool byRatingE(Video *other);
        bool byRatingEE(Video *other);
        string getTitle();
    private:
        string m_title;
        string m_URL;
        string m_comment;
        float m_length;
        int m_rating;
};
#endif