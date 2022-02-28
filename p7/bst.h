// video.cpp
// Cordova, Luke

#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
using namespace std;


class BST{
    public:
        BST(){}
        bool insert(string stg){return insert(stg, m_root);}
        int size();
        void print(vector<string> &values){if(m_root!=NULL)dft(values, m_root);}
        void breadth(queue<string> &values);
        bool find(string stg){return find(stg, m_root);}
        double distance(){return m_length!=0?distance(m_root) / m_length:0;}
        int ballanced(){return ballanced(m_root);}
        void reballance();

    private:
        class Node{
            public:
            Node(string value)
            {m_value = value; m_left = NULL;m_right = NULL;}
            Node(string value, Node *left, Node *right)
            {m_value = value; m_left = left;m_right = right;}
            string m_value;
            Node* m_right;
            Node* m_left;
        };
        Node* m_root = NULL;
        int m_length = 0;
        bool insert(string stg, Node *&cur_root);
        bool find(string stg, Node *cur_root);
        void dft(vector<string> &values, Node *cur_root);
        void breadth(queue<string> &values, Node *cur_root);
        double distance(Node *cur_root, int dist = 0);
        int ballanced(Node *cur_root, int dist = 0);
        void insert_from_vector(vector<string> &elements, int start_index, int end_index);


};


#endif