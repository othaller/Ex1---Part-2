//
// Created by Oded Thaller on 22/11/2016.
//

#ifndef PART_2_GRID_H
#define PART_2_GRID_H

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;


class Grid {

private:
    vector <vector<Point>> map;

public:
    Grid(int x, int y);
    void printMap();
    //void createNeighbors();

};


#endif //PART_2_GRID_H
