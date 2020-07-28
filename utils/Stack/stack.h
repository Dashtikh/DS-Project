//
// Created by moham on 7/26/2020.
//

#ifndef DSKHADEMIGRAPH_STACK_H
#define DSKHADEMIGRAPH_STACK_H

#endif //DSKHADEMIGRAPH_STACK_H
#include <vector>
#include "../../entity/Person/person.h"

class Stack {
public:
    std::vector<Person> nodes;
    void push(Person node);
    Person pop();
    Person DfsSearch(int id);
};
