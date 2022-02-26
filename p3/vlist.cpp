// video.h
// Cordova, Luke

#include <iostream>
#include "video.h"
#include "vlist.h"
using namespace std;

Vlist::Vlist(){
    m_head = NULL;
    m_length = 0;
}
Vlist::~Vlist(){
    while(m_head != NULL){
        delete m_head->m_video;
        Node* delete_me = m_head;
        m_head = m_head->m_next;
        delete delete_me;
    }
}
Vlist::Node::Node(Video* video, Node* next){
    m_video = video;
    m_next = next;
}
bool Vlist::insert(Video* video){
    Node* tmp = m_head;
    Node* prev = tmp;
    while(tmp!=NULL && video->byTitle(tmp->m_video)){
        prev = tmp;
        tmp = tmp->m_next;
    }
    if(tmp != NULL && video->getTitle() == tmp->m_video->getTitle()) return false;
    if(prev == tmp){
        m_head = new Node(video, m_head);
    }else{
        prev->m_next = new Node(video, tmp);
    }
    m_length++;
    return true;
}
void Vlist::print(){
    Node* tmp = m_head;
    while(tmp != NULL){
        tmp->m_video->print();
        tmp = tmp->m_next;
    }
}
int Vlist::getLength(){
    return m_length;
}
Video* Vlist::lookup(string title){
    Node* tmp = m_head;
    while(tmp != NULL && tmp->m_video->getTitle() != title){
        tmp = tmp->m_next;
    }
    return tmp == NULL ? NULL : tmp->m_video;
}
bool Vlist::remove(string title){
    Node* tmp = m_head;
    Node* prev = tmp;
    while(tmp != NULL && tmp->m_video->getTitle() != title){
        prev = tmp;
        tmp = tmp->m_next;
    }
    if(tmp != NULL){
        if(tmp == prev){
            m_head = tmp->m_next;
        }else{
            prev->m_next = tmp->m_next;
        }
        delete tmp->m_video;
        delete tmp;
        m_length--;
        return true;
    }
    return false;
}


