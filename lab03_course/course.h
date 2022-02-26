
#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;


class Course{
    public:
        Course(string name, int num, int time);
        void print();
    private:
        string m_name;
        int m_num;
        int m_time;

};

#endif