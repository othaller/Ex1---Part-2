//
// Created by Roy Shefi on 28/11/2016.
//

#ifndef PART_2_CAB_H
#define PART_2_CAB_H
#include <iostream>
#include "GridPoint.h"
using namespace std;
enum Car {HONDA, SUBARU, TESLA, FIAT};
enum  Colors {RED, BLUE, GREEN, PINK, WHITH};
class Cab {
 public:
  int id;
  int kiloPassed;
  Car Cars;
  Colors color;
  int tariff;
  Trip trip;

  virtual  int getPrice() = 0;
  virtual GridPoint getLocation() = 0;
  virtual void addDriver(Driver d) = 0;
  virtual void move() = 0;




};
#endif //PART_2_CAB_H
