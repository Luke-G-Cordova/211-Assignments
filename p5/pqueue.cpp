// video.cpp
// Cordova, Luke
#include <iostream>
#include "pqueue.h"
#include "cust.h"
using namespace std;

int Pqueue::length(){
    return m_length;
}
int Pqueue::first_priority(){
    if(m_head == NULL)return -1;
    return m_head->m_priority;
}
void Pqueue::enqueue(Cust* cust, int priority){
    m_head = new Node(cust, priority, m_head);
    m_length++;
}
Cust* Pqueue::dequeue(){
    if(m_head == NULL)return NULL;
    m_length--;
    Node* tmp = m_head;
    Node* prev = tmp;
    Node* smallest = m_head;
    while(tmp != NULL){
        if(tmp->m_next != NULL && smallest->m_priority >= tmp->m_next->m_priority){
            smallest = tmp->m_next;
            prev = tmp;
        }
        tmp = tmp->m_next;
    }
    if(smallest == m_head){
        m_head = m_head->m_next;
    }else if(prev == smallest){
        m_head = NULL;
    }else{
        prev->m_next = smallest->m_next;
    }

    Cust* cust = smallest->m_cust;
    delete smallest;
    return cust;
}
bool Pqueue::empty(){
    return m_head == NULL;
}