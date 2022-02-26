
#include <iostream>
#include "course.h"
using namespace std;

Course::Course(string name, int num, int time){
    m_name = name;
    m_num = num;
    m_time = time;
}
void Course::print(){
    cout << m_name << " " << m_num << " at " << m_time << endl;
}