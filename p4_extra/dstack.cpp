// video.cpp
// Cordova, Luke
#include <iostream>
#include "dstack.h"
using namespace std;

Dstack::~Dstack(){
    Node* delete_me = m_head;
    while(m_head!=NULL){
        m_head = m_head->m_next;
        delete delete_me;
        delete_me = m_head;
    }
}

void Dstack::push(double value){
    m_head = new Node(value, m_head);
    m_length++;
}

bool Dstack::pop(double &value){
    if(m_head == NULL)return false;
    value = m_head->m_value;
    Node* delete_me = m_head;
    m_head = m_head->m_next;
    delete delete_me;
    m_length--;
    return true;
}

int Dstack::size(){
    return m_length;
}
bool Dstack::empty(){
    return m_head == NULL;
}
