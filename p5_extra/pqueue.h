// video.cpp
// Cordova, Luke
#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include "cust.h"
using namespace std;

class Pqueue{
    public:
        int first_priority();
        int lowest_priority();
        Cust* dequeue();
        Cust* dequeue(int &priority);
        void enqueue(Cust* cust, int priority);
        bool empty();
        int length();
    private: 
        class Node{
            public:
                Node(Cust* cust, int priority, Node* next)
                {m_cust = cust;m_priority = priority;m_next = next;}
                Cust* m_cust;
                int m_priority;
                Node* m_next;
        };
        Node* m_head = NULL;
        int m_length = 0;
};

#endif