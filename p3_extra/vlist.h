// video.h
// Cordova, Luke

#ifndef VLIST_H
#define VLIST_H
#include <iostream>
#include "video.h"
using namespace std;

class Vlist{
    public:
        Vlist();
        ~Vlist();
        bool insert(Video* video);
        void print();
        void print_by_length();
        void print_by_rating();
        int getLength();
        Video* lookup(string title);
        bool remove(string title);
    private:
        class Node{
            public:
                Node(Video* video, Node* next);
                Video* m_video;
                Node* m_next;
        };
        Node* m_head;
        int m_length;
};
#endif