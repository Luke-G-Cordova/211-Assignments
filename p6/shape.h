// video.cpp
// Cordova, Luke

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "grid.h"
using namespace std;

class Shape{
    public:
        Shape(int x, int y)
        {m_x = x;m_y = y;}
        virtual void draw(Grid &grid) = 0;
    protected:
        int m_x, m_y;
};

#endif