//
// Created by Zachary Aries on 2018-03-20.
//

#ifndef ASSIGN_3_PATH_H
#define ASSIGN_3_PATH_H

#include <string>
#include "Node.h"

class Edge {
    Node from = Node();
    Node to = Node();
    int distance;
    int travel_time;
    int coins;
    int trolls;

public:
    Edge(Node from, Node to, int distance, int travel_time, int coins, int trolls);

    std::string to_string();

    Node get_from();
    Node get_to();
    int get_distance();
    int get_travel_time();
    int get_coins();
    int get_trolls();
};


#endif //ASSIGN_3_PATH_H
