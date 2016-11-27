//
// Created by Roy Shefi on 23/11/2016.
//
#ifndef PART_2_MAP_H
#define PART_2_MAP_H
#include "GridPoint.h"
#include <iostream>
#include <vector>

using namespace std;
//interface
class Map {

 public:
  virtual vector<GridPoint*> *getNeighbors(GridPoint) =0;
  virtual void printMap() =0;
  virtual void initializeGridPoints() =0;
  virtual Map* copy() =0;
  virtual ~Map() {};
};
#endif //PART_2_MAP_H
