//
// Created by Roy Shefi on 23/11/2016.
//

#include "Bfs.h"
#include <list>

using namespace std;

// Mark all the vertices as not visited
Bfs::Bfs (Map* map) {
  m = map->copy();
  (*m).initializeGridPoints();
}

void Bfs::findShortRoute(GridPoint* s, GridPoint *f,vector<GridPoint> *gp) {
  // Create a queue for BFS
  list<GridPoint*> queue;
  // Will be handy in next assignments.
  vector<GridPoint> routeIfFailed;
  routeIfFailed.push_back(*s);
  // Reference.
  GridPoint *start = s;
  vector<GridPoint> queue2;
  // Flags.
  int a = 0;
  // e - Number of while loops.
  int e = 1;
  int b = 0;


  // Mark the current node as visited and enqueue it
  (*s).changeState();
  queue.push_back(start);
  // Create the route vector and initialize it.
  rouets = new vector<vector<GridPoint*>*>;
  rouets->resize(100000);
  // Add the starting point to the vector.
  (*rouets).at(0) =  new vector<GridPoint*>;
  ((*rouets).at(0))->push_back(s);
  (*((*rouets).at(0))->at(0)).changeState();

  // Flags.
  int t = 0;
  int p = 0;

  // Where all the action happens!
  while(!queue.empty()) {
    // Initialize a new vector for neighbors.
   (*rouets).at(e) =  new vector<GridPoint*>;
    p = 0;
    // Dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop_front();

    // This loop is to find who is whos parent.
    if (e != 1) {
      for ( t = 1; t < rouets->size(); ++t) {
        for (int i = 0; i < (*(rouets->at(e - t))).size(); ++i) {
          if ((*s).isEqual(*(*(rouets->at(e - t))).at(i))) {
            b = i;
            t = e - t;
            p = 1;
            break;
          }
        }
        if (p == 1) { break;}
      }
    }
    else {
      t = 0;
    }
    // Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it

    // Get the neighbors!!
    rouets->at(e)= ((*m).getNeighbors(*s));

    // For each neighbor, mark as visited and add to queue.
    for (int i = 0; i < (*(rouets->at(e))).size(); ++i) {
      // If not visited, visit.
      if (!((*((*(rouets->at(e))).at(i))).getState())) {
        ((*(rouets->at(e))).at(i))->changeState();
        ((*(rouets->at(e))).at(i))->assignFather(((*(rouets->at( t))).at(b)));
        queue.push_back(((*(rouets->at(e))).at(i)));
      }

      // Checking to see if the neighbor is the target.
      if ((*f).isEqual(*((*(rouets->at(e))).at(i)))) {
        *f = *((*(rouets->at(e))).at(i));
        a = 1;
        break;
      }
    }
    ++e;
    if (a == 1) { break;}
  }

// Going back to find to route of ancestry.
  vector<GridPoint*> fat = *new vector<GridPoint*> ;
  fat.push_back(f);
  while ((*f).fa != 0) {
    fat.push_back(f->fa);
    f = (*f).fa;
  }

  // Printing the route if ancestry.
  for (int i = fat.size() - 1;i > 0; --i) {
    fat.at(i)->print();
    if (i != 0){
      cout<<"\n";

    }
  }
  fat.at(0)->print();


  queue2.push_back(*f);
  // Deleting the date structure.
for ( int i = 1; i<e; ++i) {
  for (int j = 0; i < (*(rouets->at(i-1))).size() -1; ++i) {
    if ((rouets->at(i-1))->at(j) != 0) {
      delete ((rouets->at(i - 1))->at(j));
    }
  }
}
  return;

};
