//
// Created by moham on 7/26/2020.
//

#include "person.h"
#include <string>

void Person::addRelation(std::string to, RelationType type) {
    Relation relation(id, to, type);
    relations.push_back(relation);
}