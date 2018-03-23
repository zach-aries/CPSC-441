//
// Created by Zachary Aries on 2018-03-20.
//

#include "Graph.h"

/**
 * Graph Constructor
 *
 * Create a graph of 26 nodes, one for each letter of the alphabet.
 * The index of each node will be 0 - 25. A being 0, Z being 25
 */
Graph::Graph(){
    vector<Edge> edge_list;
    for (unsigned int i = 0; i < MAXSIZE; i++){
        graph.emplace_back(edge_list);
    }
};

/**
 * Adds adjecency edge to the node in graph
 *
 * @param edge
 */
void Graph::add_edge(Edge edge) {
    graph[edge.get_from().get_index()].emplace_back(edge);
}

/**
 * Gets adjeceny list
 *
 * @param i
 * @return
 */
vector<Edge>& Graph::get_edge_list_at(int i) {
    return graph[i];
}

/**
 * Prints graph (Json format) for debugging
 *
 */
void Graph::print_graph() {
    cout << "Graph { " << endl;
    for (auto& edge_list : graph) {
        if(!edge_list.empty()){
            cout << "\t"<< edge_list[0].get_from().to_string() << ": {";
            for (auto& edge : edge_list) {
                cout << "(" << edge.get_to().to_string() << "," << edge.get_distance() << "),";
            }
            cout << "}" << endl;
        }
    }
    cout << "}" << endl;
}