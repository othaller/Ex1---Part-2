//
// Created by Roy Shefi on 23/11/2016.
//
#ifndef PART_2_MAP_H
#define PART_2_MAP_H
#include "GridPoint.h"
#include <iostream>
#include <vector>

using namespace std;

class Map {
 public:
  virtual vector<GridPoint> getNeighbors(GridPoint) =0;
  virtual void printMap() =0;
};
#endif //PART_2_MAP_H
