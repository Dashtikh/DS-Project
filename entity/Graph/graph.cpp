//
// Created by moham on 7/26/2020.
//

#include "graph.h"

Person* Graph::searchById(std::string id) {
    for (int i = 0; i < nodes.size() ; ++i) {
        if(nodes[i]->id == id) {
            return nodes[i];
        }
    }
}

void Graph::addPerson(std::string fName, std::string lName, std::string id, bool sex, std::string pId) {
    Person* newPerson = new Person(fName, lName, id, sex, pId);
    nodes.push_back(newPerson);
}