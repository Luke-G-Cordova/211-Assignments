// video.cpp
// Cordova, Luke

#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "shape.h"
#include "grid.h"
using namespace std;

class Circle: public Shape{
    public:
        Circle(int x, int y):Shape(x, y){}
        void draw(Grid &grid);
};

#endif

void Circle::draw(Grid &grid){
    grid.set(m_x+1, m_y, 'o');
    grid.set(m_x+2, m_y, 'o');
    grid.set(m_x+1, m_y+3, 'o');
    grid.set(m_x+2, m_y+3, 'o');
    
    grid.set(m_x, m_y+1, 'o');
    grid.set(m_x, m_y+2, 'o');
    grid.set(m_x+3, m_y+1, 'o');
    grid.set(m_x+3, m_y+2, 'o');
}