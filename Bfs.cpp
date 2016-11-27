//
// Created by Roy Shefi on 23/11/2016.
//

#include "Bfs.h"
#include <list>
#include<iostream>
#include <vector>


using namespace std;
// Mark all the vertices as not visited
Bfs::Bfs (Map* map) {
  m = map->copy();
  (*m).initializeGridPoints();
}

void Bfs::findShortRoute(GridPoint* s, GridPoint *f,vector<GridPoint> *gp) {
  // Create a queue for BFS
  list<GridPoint*> queue;
  vector<GridPoint> route;
  vector<GridPoint> routeIfFaild;
  routeIfFaild.push_back(*s);
  GridPoint *start = s;
  //GridPoint t = s
  vector<GridPoint> queue2;
  list<GridPoint*> queue3;
  int a =0;
int e =1;
  int b =0;
  int kk =0;


  // Mark the current node as visited and enqueue it
  (*s).changeState();
  int x =(*start).x;
  queue.push_back(start);

temp = new vector<vector<GridPoint*>*>;
    temp->resize(100000);

  (*temp).at(0) =  new vector<GridPoint*>;
  ((*temp).at(0))->push_back(s);
  (*((*temp).at(0))->at(0)).changeState();
int t =0;
int p =0;
  while(!queue.empty()) {
   (*temp).at(e) =  new vector<GridPoint*>;
    p =0;
    // Dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop_front();
    if (e != 1) {
      for ( t = 1; t < temp->size(); ++t) {
        for (int i = 0; i < (*(temp->at(e -  t))).size(); ++i) {
          if ((*s).isEqual(*(*(temp->at(e - t))).at(i))) {
            b = i;
            t = e -t;
            p =1;
            break;
          }
        }
        if (p ==1) { break;}
      }
    }
    else {
      t = 0;
    }


    // Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it

    temp->at(e)= ((*m).getNeighbors(*s));

    for (int i = 0; i < (*(temp->at(e))).size(); ++i) {

      if (!((*((*(temp->at(e))).at(i))).getState())) {
        ((*(temp->at(e))).at(i))->changeState();
        ((*(temp->at(e))).at(i))->assignFather(((*(temp->at( t))).at(b)));
        queue.push_back(((*(temp->at(e))).at(i)));
      }

      // Problen is in here.
      if ((*f).isEqual(*((*(temp->at(e))).at(i)))) {
        *f = *((*(temp->at(e))).at(i));
        a =1;
        break;
      }
    }
    ++e;
    if (a == 1) { break;}
  }


vector<GridPoint*> fat = *new vector<GridPoint*> ;
  fat.push_back(f);
  while ((*f).fa != 0) {
    fat.push_back(f->fa);
    f = (*f).fa;
  }
  for (int i = 0; i< fat.size(); ++i) {
    fat.at(i)->print();
    if (i+1 != fat.size()){
      cout<<"\n";

    }
  }

  queue2.push_back(*f);

  return;

};
