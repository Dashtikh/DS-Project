//
// Created by moham on 7/26/2020.
//

#ifndef DSKHADEMIGRAPH_GRAPH_H
#define DSKHADEMIGRAPH_GRAPH_H

#endif //DSKHADEMIGRAPH_GRAPH_H
#include "../Person/person.h"
#include <vector>
#include <string>

class Graph {
public:
    // nodes of graph
    // includes nodes and relations
    std::vector<Person*> nodes;
    std::vector<Relation> *edges;

    void addNode(Person* node);
    void addEdge(int from, int to, RelationType type);

    Person* BFS(int id);

    void addPerson(
            std::string fName,
            std::string lName,
            int id,
            bool sex,
            int pId);
};

