//
// Created by moham on 7/26/2020.
//

#include "graph.h"
#include <vector>

void Graph::addNode(Person *node) {
    nodes.push_back(node);
}

void Graph::addPerson(std::string fName, std::string lName, int id, bool sex, int pId) {
    Person* newPerson = new Person(fName, lName, id, sex, pId);
    nodes.push_back(newPerson);
}

void Graph::addEdge(int from, int to, RelationType type) {
    Relation relation(to, type);
    edges[from].push_back(relation);
}

int Graph::getFatherId(int myId) {
    vector<Relation> edges = this->edges[myId];
    vector<Relation>::iterator i;
    for (i = edges.begin(); i != edges.end(); ++i) {
        if (i->type == ChildFather) {
            return i->to;
        }
    }
    return -1;
}

int Graph::getMotherId(int myId) {
    vector<Relation> edges = this->edges[myId];
    vector<Relation>::iterator i;
    for (i = edges.begin(); i != edges.end(); ++i) {
        if (i->type == ChildMother) {
            return i->to;
        }
    }
    return -1;
}



void Graph::getMySiblings(int MyId, vector<int> &siblings) {
    int fatherId;
}

vector<int> * Graph::childrenMap() {
    vector<int>* children = new vector<int>[nodes.size()];
    class BFS bfs(*this, 0);
    int id = bfs.nextId();
    while(id >= 0) {
        Person* node = nodes[id];
        vector<Relation>::iterator i;
        for (i = edges[id].begin(); i != edges[id].end(); ++i) {
            if (i->type == Father || i->type == Mother) {
                children[id].push_back(i->to);
            }
        }
        id = bfs.nextId();
    }
    return children;
}


int Graph::numOfMyChildren(int id, vector<int> *children) {
    int numOfChildren = children[id].size();
    for (int i = 0; i < children[id].size(); ++i) {
        numOfChildren += numOfMyChildren(children[id][i], children);
    }
    return numOfChildren;
}

vector<int>* Graph::findTheRoots() {
    vector<int> roots;
    class BFS bfs(*this, 0);
    int id = bfs.nextId();
    while(id >= 0) {
        vector<Relation>::iterator i;
        bool flag = true;
        for (i = edges[id].begin(); i != edges[id].end(); ++i) {
            if (i->type == ChildMother || i->type == ChildFather) {
                flag = false;
                break;
            }
        }
        if (flag) {
            roots.push_back(id);
        }
        id = bfs.nextId();
    }
    return &roots;
}

BFS::BFS(Graph g, int start) {
    this->g = g;

    counter = 0;

    V = g.nodes.size();

    visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    visited[start] = true;
    queue.push_back(start);

    vector<Relation>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        start = queue.front();
        BFSOut.push_back(start);
        queue.erase(queue.begin()+start);

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = g.edges[start].begin(); i != g.edges[start].end(); ++i)
        {
            if (!visited[i->to])
            {
                visited[i->to] = true;
                queue.push_back(i->to);
            }
        }
    }
}

int BFS::nextId() {
    if (counter < V) {
        return BFSOut[counter++];
    } else {
        return -1;
    }
}

Node BFS::nextPerson() {
    Node node;
    if (counter < V - 1) {
        node.node = g.nodes[BFSOut[counter]];
        node.next = true;
    }
    else if ( counter == V - 1) {
        node.node = g.nodes[BFSOut[counter]];
        node.next = false;
    }
    else {
        node.next = false;
    }
    return node;
}

void BFS::reset() {
    counter = 0;
}
