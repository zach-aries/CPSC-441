//
// Created by Zachary Aries on 2018-03-21.
//

#include "Dijkstra.h"

class Comparator {
public:
    int operator() ( const pair<Node,int>& p1, const pair<Node,int> &p2)
    {
        return p1.second > p2.second;
    }
};

void Dijkstra::dijkstra_distance(Graph& G, Node &source, Node &destination,
                                 vector<Edge> &path, string using_weight) {

    vector<Edge> edge_list;
    // distance list
    vector<int> distance(G.size, INF_DISTANCE);
    // visited list
    vector<bool> visited(G.size, false);
    // prev node list
    vector<Node> prev(G.size, Node());
    // set up minimum priority queue
    priority_queue<pair<Node, int>, vector<pair<Node, int> >, Comparator> Q;

    distance[source.get_index()] = 0;
    Q.push(make_pair(source, distance[source.get_index()]));

    while (!Q.empty()) {
        Node u = Q.top().first;

        // if we are at destination, stop
        if (u.get_name() == destination.get_name())
            break;
        Q.pop();

        unsigned long edge_list_len = G.get_edge_list_at(u.get_index()).size();

        for (unsigned int i = 0; i < edge_list_len; i++) {
            Node v = G.get_edge_list_at(u.get_index())[i].get_to();
            int weight = get_weight(G.get_edge_list_at(u.get_index())[i], using_weight);

            int ui = u.get_index();
            int vi = v.get_index();

            if (distance[ui] + weight < distance[vi]) {
                distance[v.get_index()] = distance[u.get_index()] + weight;
                prev[v.get_index()] = u;
                Q.push(make_pair(v, distance[v.get_index()]));
            }
        }
    }

    // figure out path
    // clear path
    path.clear();

    // set destination
    Node to = destination;

    // find all parents in the new shortest path
    while (to.get_name() != source.get_name()) {
        int from_index = prev[to.get_index()].get_index();

        int edge_list_size = G.get_edge_list_at(from_index).size();
        for (unsigned int i = 0; i < edge_list_size; i++) {
            Edge e = G.get_edge_list_at(from_index)[i];
            if (e.get_to().get_name() == to.get_name()) {
                path.emplace_back(e);
            }
        }

        to = prev[to.get_index()];
    }
}

int Dijkstra::get_weight(Edge e, string using_weight) {
    if (using_weight == "distance")
        return e.get_distance();
    if (using_weight == "time")
        return e.get_travel_time();
    if (using_weight == "hops")
        return 1;
    if (using_weight == "trolls")
        return e.get_trolls();
}