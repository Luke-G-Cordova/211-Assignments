// video.cpp
// Cordova, Luke

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "shape.h"
#include "grid.h"
using namespace std;

class Triangle: public Shape{
    public:
        Triangle(int x, int y):Shape(x, y){}
        void draw(Grid &grid);
    
};

#endif

void Triangle::draw(Grid &grid){
    grid.set(m_x+2, m_y, '+');
    grid.set(m_x+1, m_y+1, '+');
    grid.set(m_x+3, m_y+1, '+');
    for(int i = 0;i<5;i++){
        grid.set(m_x+i, m_y+2, '+');
    }
}