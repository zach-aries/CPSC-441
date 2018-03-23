//
// Created by Zachary Aries on 2018-03-21.
//

#include "Dijkstra.h"

/**
 * Helper class used to compare the smallest weight in a <Node,weight> pair
 * This will create a priority_queue with the smallest weight on top
 * MinHeap Data Structure
 */
class Comparator {
public:
    int operator() ( const pair<Node,int>& p1, const pair<Node,int> &p2)
    {
        return p1.second > p2.second;
    }
};

/**
 * Impliments Dijkstra's algorithm
 * returns the shortest path from destination to src as a list of edges
 *
 * @param G - graph to traverse
 * @param source - source Node
 * @param destination - destination Node
 * @param path - list of edges as reference (will be returned in reverse order for traversal)
 * @param using_weight - algroithm option (sets weight for comparison)
 */
void Dijkstra::dijkstra_distance(Graph& G, Node &source, Node &destination,
                                 vector<Edge> &path, const string using_weight) {

    // distance list
    // originally all distances are infinity
    vector<int> distance(G.size, INF_DISTANCE);
    // prev node list
    vector<Node> prev(G.size, Node());
    // set up minimum priority queue
    priority_queue<pair<Node, int>, vector<pair<Node, int> >, Comparator> Q;

    // set the source distance to 0 (there is no weight accumulated to get to source)
    distance[source.get_index()] = 0;
    // add the source Node and it's current weight traveled to the distance array
    Q.push(make_pair(source, distance[source.get_index()]));

    while (!Q.empty()) {
        // use the top node on the stack (will be the one with the smallest weight)
        Node u = Q.top().first;

        // if we are at destination, stop
        if (u.get_name() == destination.get_name())
            break;
        // pop node/weight off queue so we don't use it again
        Q.pop();

        // get the amount of adjacent nodes of u
        unsigned long edge_list_len = G.get_edge_list_at(u.get_index()).size();

        // iterate through all adjacent nodes of u
        for (unsigned int i = 0; i < edge_list_len; i++) {
            // get the adjacent node from u
            Node v = G.get_edge_list_at(u.get_index())[i].get_to();
            // get the weight of the edge u->v
            int weight = get_weight(G.get_edge_list_at(u.get_index())[i], using_weight);

            // get the index of u & v
            int ui = u.get_index();
            int vi = v.get_index();

            // check if the distance of u + the weight of u->v is less than the distance of v
            // will always be true of the src comparison sense we set that to 0
            if (distance[ui] + weight < distance[vi]) {
                // if true set the new distance at v
                distance[vi] = distance[ui] + weight;
                prev[vi] = u;
                Q.push(make_pair(v, distance[vi]));
            }
        }
    }

    // figure out path
    // clear path
    path.clear();

    // set destination
    Node to = destination;

    // traverse the list of prev nodes backwards in order to get the shortest path traveled
    // while the node we are currently inspecting is not our source destination keep checking
    while (to.get_name() != source.get_name()) {
        // get "from" by selecting the prev[] @ "to's" index
        // we are traveling backwards
        int from_index = prev[to.get_index()].get_index();

        // get the amount of adjacent edges of from
        int edge_list_size = G.get_edge_list_at(from_index).size();
        // iterate through all adjacent edges
        for (unsigned int i = 0; i < edge_list_size; i++) {
            // get the edge list at from's index and select the one at i
            Edge e = G.get_edge_list_at(from_index)[i];
            // if that edge is = to to then place it in our path
            if (e.get_to().get_name() == to.get_name()) {
                path.emplace_back(e);
            }
        }

        to = prev[to.get_index()];
    }
}

/**
 * get the weight of edge for each algorithm
 *
 * @param e
 * @param using_weight
 * @return
 */
int Dijkstra::get_weight(Edge e, string using_weight) {
    if (using_weight == "-sdp")
        return e.get_distance();
    if (using_weight == "-stp")
        return e.get_travel_time();
    if (using_weight == "-shp")
        return 1;
    if (using_weight == "-ftp")
        return e.get_trolls();

    return e.get_distance();
}