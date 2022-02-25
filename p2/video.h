// video.h
// Cordova, Luke

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;

class Video{
    public:
        Video(string title, string URL, string comment, float length, int rating);
        void print();
        bool byLength(Video *other);
        bool byTitle(Video *other);
        bool byRating(Video *other);
    private:
        string title;
        string URL;
        string comment;
        float length;
        int rating;
};
#endif