// video.cpp
// Cordova, Luke

#include <iostream>
#include <vector>
#include <queue>
#include "bst.h"
using namespace std;

bool BST::insert(string stg, Node *&cur_root){
    if(cur_root == NULL) {
        cur_root = new Node(stg);
        m_length++;
        return true;
    }
    if(stg < cur_root->m_value)return insert(stg, cur_root->m_left);
    if(stg > cur_root->m_value)return insert(stg, cur_root->m_right);
    return false;
}

void BST::dft(vector<string> &values, Node *cur_root){
    if(cur_root->m_left != NULL) dft(values, cur_root->m_left);
    values.push_back(cur_root->m_value);
    if(cur_root->m_right != NULL) dft(values, cur_root->m_right);
}
void BST::breadth(queue<string> &values){
    if(m_root!=NULL){
        values.push(m_root->m_value);
        breadth(values, m_root);
    }
}
void BST::breadth(queue<string> &values, Node *cur_root){
    
    if(cur_root->m_left!=NULL)values.push(cur_root->m_left->m_value);
    if(cur_root->m_right!=NULL)values.push(cur_root->m_right->m_value);

    if(cur_root->m_left!=NULL)breadth(values, cur_root->m_left);
    if(cur_root->m_right!=NULL)breadth(values, cur_root->m_right);
}

int BST::size(){
    return m_length;
}
bool BST::find(string stg, Node *cur_root){
    if(stg == cur_root->m_value)return true;
    bool right = false, left = false;
    if(cur_root->m_left != NULL)left = find(stg, cur_root->m_left);
    if(cur_root->m_right != NULL)right = find(stg, cur_root->m_right);
    return right || left;
}

double BST::distance(Node *cur_root, int dist){
    double ldist = 0, rdist = 0;
    if(cur_root->m_left!=NULL)ldist = distance(cur_root->m_left, dist+1);
    if(cur_root->m_right!=NULL)rdist = distance(cur_root->m_right, dist+1);
    return dist + ldist + rdist;
}
int BST::ballanced(Node *cur_root, int dist){
    int left = 0, right = 0;
    if(cur_root == NULL){
        return 0;
    }
    left = ballanced(cur_root->m_left, dist);
    if(left==-1)return -1;
    right = ballanced(cur_root->m_right, dist);
    if(right==-1)return -1;
    left++;
    right++;
    if(abs(right-left)>1)return -1;
    return (right > left ? right:left);
}

void BST::reballance(){
    vector<string> values;
    dft(values, m_root);
    m_root = NULL;
    insert_from_vector(values, 0, m_length-1);
}
void BST::insert_from_vector(vector<string> &elements, int start_index, int end_index){
    int range = end_index - start_index;
    if(range == 0){
        insert(elements[start_index]);
    }else if(range == 1){
        insert(elements[start_index]);
        insert(elements[start_index+1]);
    }else if(range>0){
        int middle_index = (range/2) + start_index;
        insert(elements[middle_index]);
        insert_from_vector(elements, 0, middle_index-1);
        insert_from_vector(elements, middle_index+1, range + start_index);
    }
}

