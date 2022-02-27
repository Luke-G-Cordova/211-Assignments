// video.h
// Cordova, Luke

#include <iostream>
#include "video.h"
#include "vlist.h"
#include <regex.h>
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
void Vlist::print_by_length(){
    Node* tmp = m_head;
    Node* last_smallest = m_head;
    Node* last_biggest = m_head;
    while(tmp != NULL){
        if(last_smallest->m_video->byLength(tmp->m_video)){
            last_smallest = tmp;
        }
        if(tmp->m_video->byLength(last_biggest->m_video)){
            last_biggest = tmp;
        }
        tmp = tmp->m_next;
    }
    Node* cur_smallest = last_biggest;
    tmp = m_head;
    for(int i = 0;i<getLength();i++){
        cur_smallest = last_biggest;
        tmp = m_head;
        while(tmp != NULL){
            // this works with a list that has no repeats 
            // It will absolutly break if it has to order
            // by title due to repeats
            if(last_smallest->m_video->byLengthE(tmp->m_video)){
                tmp = tmp->m_next;
            }else{
                if(cur_smallest->m_video->byLength(tmp->m_video)){
                    cur_smallest = tmp;
                }
                tmp = tmp->m_next;
            }
        }
        last_smallest->m_video->print();
        last_smallest = cur_smallest;
    }
}
void Vlist::print_by_rating(){
    Node* tmp = m_head;
    Node* last_smallest = m_head;
    Node* last_biggest = m_head;
    while(tmp != NULL){
        if(last_smallest->m_video->byRatingE(tmp->m_video)){
            last_smallest = tmp;
        }
        if(tmp->m_video->byRating(last_biggest->m_video)){
            last_biggest = tmp;
        }
        tmp = tmp->m_next;
    }
    Node* cur_biggest = last_smallest;
    tmp = m_head;
    for(int i = 0;i<getLength();i++){
        cur_biggest = last_smallest;
        tmp = m_head;
        while(tmp != NULL){
            if(
                tmp->m_video->byRating(last_biggest->m_video) || 
                (
                    tmp->m_video->byRatingEE(last_biggest->m_video)&&
                    last_biggest->m_video->byTitleE(tmp->m_video)
                )
            ){
                tmp = tmp->m_next;
            }else{
                if(
                    tmp->m_video->byRating(cur_biggest->m_video)||
                    (
                        tmp->m_video->byRatingEE(cur_biggest->m_video)&&
                        cur_biggest->m_video->byTitle(tmp->m_video)
                    )
                ){
                    cur_biggest = tmp;
                }
                tmp = tmp->m_next;
            }
        }
        last_biggest->m_video->print();
        last_biggest = cur_biggest;
    }
}
bool Vlist::lookup_expression(string &regexp){
    regex_t reg_expression;
    string str;
    int result = regcomp(&reg_expression, regexp.c_str(), REG_EXTENDED);
    if(result)return 1;
    Node* tmp = m_head;
    int count = 0;
    while(tmp != NULL){
        str = tmp->m_video->getTitle();
        if(!regexec(&reg_expression, str.c_str(), 0, 0, 0)){
            tmp->m_video->print();
            count++;
        }
        tmp = tmp->m_next;
    }
    return !count;
}

