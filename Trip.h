//
// Created by Roy Shefi on 28/11/2016.
//

#ifndef PART_2_TRIP_H
#define PART_2_TRIP_H
#include "GridPoint.h"
using namespace std;

class Trip {
 public:
  int id;
  int distGone;
  GridPoint start;
  GridPoint end;
  int numPass;
  double tariff;
  Passenger[] pass;

  void move();
  int getDisGone();

  Trip(int id, int disGone, GridPoint start, GridPoint end, int numPass, double tariff,
  Passenger[] pass);

};

#endif //PART_2_TRIP_H
