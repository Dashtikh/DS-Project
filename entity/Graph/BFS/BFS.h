//
// Created by Mohammad on 7/28/2020.
//

#ifndef DSKHADEMIGRAPH_BFS_H
#define DSKHADEMIGRAPH_BFS_H

#endif //DSKHADEMIGRAPH_BFS_H
#include "../graph.h"
#include <vector>
using std::vector;

struct Node {
    bool next;
    Person* node;
};
class BFS {
public:
    BFS(Graph g, int start);
    int nextId(); // return node till return -1;
    Node nextPerson();
    void reset();
private:
    Graph g;
    bool* visited;
    int counter;
    int V;
    vector<int> queue;
    vector<int> BFSOut;
};

