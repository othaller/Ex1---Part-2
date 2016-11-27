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
  // Constructor.
  GridPoint (int a, int b);
  GridPoint();
  /**
   * Returns if the Grid point has been visited.
   * @return true if visited.
   */
  bool getState() { return this->visited;}
  /**
   * Compares the point to point a.
   * @param a -  point to compare to.
   * @return true if they are the same.
   */
  bool isEqual (GridPoint a);
  /**
   * Markes that the point has bees visited.
   */
  void changeState(){this->visited=true;}
  /**
   * Initializes the grid poit to false - not visited.
   */
  void initialize  () {this->visited= false;}

  // Not usefull now.
  void getRouteToStart (GridPoint *g, vector<GridPoint>* an);
  /**
   * Assigns a father to the Grid point.
   */

  void assignFather(GridPoint * f) {this->fa = f;}
  /**
   * Printsthe gridponits father.
   */
  void printFather() {cout<<"("<<this->fa->x<<","<<this->fa->y<<")"<<endl;}


};
#endif //PART_2_GRIDPOINT_H
