//
// Created by Zachary Aries on 2018-03-21.
//

#ifndef ASSIGN_3_DIJKSTRA_H
#define ASSIGN_3_DIJKSTRA_H

#include <queue>
#include "Graph.h"

#define INF_DISTANCE std::numeric_limits<int>::max()

using namespace std;

class Dijkstra {
    static int get_weight(Edge e, string using_weight);

public:
    static void dijkstra_distance(Graph& G, Node &source, Node &destination,
                                  vector<Edge> &path, string using_weight);
};


#endif //ASSIGN_3_DIJKSTRA_H
