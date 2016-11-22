//
// Created by Oded Thaller on 22/11/2016.
//

#include "Grid.h"

using namespace std;


Grid::Grid(int x, int y) {

    map.resize(x);
    for (int i = 0; i < x; ++i) {
        map[i].resize(y);
    }

    for (int i = 0; i < x; ++i) {

        for (int j = 0; j < y; ++j) {

            map[j][i] = Point(j, x - 1 - i);
        }
    }
}

void Grid::printMap() {

    for (int i = 0; i < map.size(); ++i) {

        for (int j = 0; j < map[i].size(); ++j) {

            map[j][i].print();
        }

        cout << "\n";
    }
}

/*void Grid::createNeighbors() {

}*/
