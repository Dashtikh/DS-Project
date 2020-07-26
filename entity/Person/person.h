//
// Created by moham on 7/26/2020.
//

#ifndef DSKHADEMIGRAPH_PERSON_H
#define DSKHADEMIGRAPH_PERSON_H

#endif //DSKHADEMIGRAPH_PERSON_H
#include <string>
#include <vector>
#include "../Relation/relation.h"
class Relation;

enum RelationType {
    Father,
    Wife,
};

class Person {
public:
    Person(
            std::string fName,
            std::string lName,
            std::string nId,
            bool s,
            std::string pId):
            firstName(fName),
            lastName(lName),
            id(nId),
            sex(s),
            partnerId(pId)
            {};
    std::string firstName, lastName;
    std::string id;
    bool sex;
//    int bDate, dDate;
    std::string partnerId;
    std::vector<Relation> relations;
    void addRelation(std::string to, RelationType type);
    void findMyChildren(std::string id, std::vector<Person>);
};

class Relation {
public:
    Person* from;
    Person* to;
    Relation(Person* f, Person* t, RelationType rT):
            from(f), to(t), type(rT) {};
    RelationType type;
};