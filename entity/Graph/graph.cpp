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

Person * Graph::BFS(int id) {
    int V = nodes.size();
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    std::vector<int> queue;

    // Mark the current node as visited and enqueue it
    visited[id] = true;
    queue.push_back(id);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    std::vector<Relation>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        id = queue.front();
        queue.erase(queue.begin()+id);

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = edges[id].begin(); i != edges[id].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}