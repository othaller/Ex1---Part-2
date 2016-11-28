//
// Created by Roy Shefi on 28/11/2016.
//

#ifndef PART_2_PASSENGER_H
#define PART_2_PASSENGER_H
#include "GridPoint.h"
using namespace std;
class Passenger {
 public:
  GridPoint start;
  GridPoint end;
  int score;

  GridPoint getStart ();
  GridPoint getEnd();
  int getScore();

  Passenger(GridPoint start, GridPoint end);


};

#endif //PART_2_PASSENGER_H
