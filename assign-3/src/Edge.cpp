//
// Created by Zachary Aries on 2018-03-20.
//

#include "Edge.h"

Edge::Edge(Node from, Node to, int distance, int travel_time, int coins, int trolls) {
    this->from = from;
    this->to = to;
    this->distance = distance;
    this->travel_time = travel_time;
    this->coins = coins;
    this->trolls = trolls;
}

std::string Edge::to_string() {
    std::string s =   "Edge {\n  from: " + from.to_string()
                    + "\n  to: " + to.to_string()
                    + "\n  distance: " + std::to_string(distance)
                    + "\n  travel time: " + std::to_string(travel_time)
                    + "\n  coins: " + std::to_string(coins)
                    + "\n  trolls: " + std::to_string(trolls)
                    + "\n}";

    return s;
}

Node Edge::get_from() {
    return this->from;
}

Node Edge::get_to() {
    return this->to;
}

int Edge::get_distance() {
    return this->distance;
}

int Edge::get_travel_time() {
    return this->travel_time;
}

int Edge::get_coins() {
    return this->coins;
}

int Edge::get_trolls() {
    return this->trolls;
}