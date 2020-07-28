//
// Created by Mohammad on 7/28/2020.
//

#include "BFS.h"

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
