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
    Father, // from: Hesam is father of to: Parastu
    Mother, // from: Sevda is mother of to: Hesam
    ChildFather, // from: Mohammad is child of to: Amir
    ChildMother, // from: Khosro is child of to: Mina
};

class Person {
public:
    Person(
            std::string fName,
            std::string lName,
            int nId,
            bool s,
            int pId):
            firstName(fName),
            lastName(lName),
            id(nId),
            sex(s),
            partnerId(pId)
            {};
    std::string firstName, lastName;
    // id is equal to the own index in the nodes vector and started with 0
    int id;
    bool sex;
    int bDate, dDate;
    int partnerId;
};

class Relation {
public:
    int to;
    Relation(int t, RelationType rT):
             to(t), type(rT) {};
    RelationType type;
};