//
// Created by Zachary Aries on 2018-03-20.
//

#ifndef ASSIGN_3_GRAPH_H
#define ASSIGN_3_GRAPH_H

#include <vector>
#include <iostream>

#include "Edge.h"
#include "Node.h"


#define MAXSIZE 26

using namespace std;

class Graph {
private:
    vector<vector<Edge> > graph;


public:
    const unsigned long size = MAXSIZE;

    Graph();

    void add_edge(Edge edge);

    void print_graph();

    vector<Edge>& get_edge_list_at(int i);

};


#endif //ASSIGN_3_GRAPH_H
