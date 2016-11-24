//
// Created by Roy Shefi on 23/11/2016.
//

#ifndef PART_2_GRIDPOINT_H
#define PART_2_GRIDPOINT_H
#include <iostream>
#include "vector"
#include "Point.h"

using namespace std;
class GridPoint : public Point {
 private:bool visited;
 public:GridPoint *fa;
 public:
  GridPoint (int a, int b);
  GridPoint();
  bool getState() { return this->visited;}
  bool isEqual (GridPoint a);
  void changeState(){this->visited=true;}
  void initialize  () {this->visited= false;}
  void getRouteToStart (GridPoint *g, vector<GridPoint>* an);
  void assignFather(GridPoint * f) {this->fa = f;}
  void printFather() {cout<<"("<<this->fa->x<<","<<this->fa->y<<")"<<endl;}
  GridPoint copy();


};
#endif //PART_2_GRIDPOINT_H
