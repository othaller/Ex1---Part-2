//
// Created by Oded Thaller & Roey Shefi
//

#ifndef PART_2_POINT_H
#define PART_2_POINT_H

#include <iostream>

class Point{

    public:
        int getX();
        int getY();
        void setX(int a);
        void setY(int b);
        void print();
        Point(int a, int b);
        Point();
  int x;
  int y;
};

#endif //PART_2_POINT_H
