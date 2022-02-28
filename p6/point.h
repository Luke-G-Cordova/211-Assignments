// video.cpp
// Cordova, Luke

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "shape.h"
#include "grid.h"
using namespace std;

class Point: public Shape{
    public:
        Point(int x, int y, char c):Shape(x, y)
        {m_c = c;}
        void draw(Grid &grid);
    private:
        char m_c;
};
#endif

void Point::draw(Grid &grid){
    grid.set(m_x, m_y, m_c);
}