//
// Created by Oded Thaller & Roey Shefi
//

#include <iostream>
#include "Grid.h"
using namespace std;

int main() {


    Grid grid(3,3);

    //grid.printMap();

    vector<Point> vec = grid.getNeighbors(Point(2,2));

    for (int i = 0; i < vec.size(); ++i) {
        vec[i].print();
    }

    return 0;
}