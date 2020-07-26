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
    std::vector<Person*> nodes;
    Person* searchById(std::string id);
    void addPerson(
            std::string fName,
            std::string lName,
            std::string id,
            bool sex,
            std::string pId);
};