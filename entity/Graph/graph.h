//
// Created by moham on 7/26/2020.
//

#ifndef DSKHADEMIGRAPH_GRAPH_H
#define DSKHADEMIGRAPH_GRAPH_H

#endif //DSKHADEMIGRAPH_GRAPH_H
#include "../Person/person.h"
#include <vector>
#include <string>

using std::vector;
class BFS;

class Graph {
public:
    // nodes of graph
    // includes nodes and relations
    vector<Person*> nodes;
    vector<Relation> *edges;

    void addNode(Person* node);
    void addEdge(int from, int to, RelationType type);

    int getFatherId(int myId);
    int getMotherId(int myId);
    void getMySiblings(int MyId, vector<int> &siblings);
    vector<int>* childrenMap();
    vector<int>* findTheRoots();
    int numOfMyChildren(int id, vector<int>* children);

    void addPerson(
            std::string fName,
            std::string lName,
            int id,
            bool sex,
            int pId);
};

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
