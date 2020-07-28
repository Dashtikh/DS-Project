//
// Created by moham on 7/26/2020.
//

#include "stack.h"

void Stack::push(Person node) {
    nodes.push_back(node);
}

Person Stack::pop() {
    Person temp = nodes[nodes.size()-1];
    nodes.pop_back();
}

Person Stack::DfsSearch(int id) {

}