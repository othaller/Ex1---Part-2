//
// Created by Roy Shefi on 23/11/2016.
//

#ifndef PART_2_GRIDPOINT_H
#define PART_2_GRIDPOINT_H
#include <iostream>
#include <vector>
#include "Point.h"

class GridPoint : public Point {
 private:bool visited;
 public:
  GridPoint (int a, int b);
  GridPoint();
  bool getState() { return this->visited;}
  void changeState(){this->visited=true;}
  void initialize  () {this->visited= false;}

};
#endif //PART_2_GRIDPOINT_H
