//
// Created by Zachary Aries on 2018-03-21.
//

/**
 * A node is just a character representation of a vertex.
 * For our purpose each node has a predefined index 0-25, A being 0 and Z being 25
 * Nodes can only be A-Z
 */

#ifndef ASSIGN_3_NODE_H
#define ASSIGN_3_NODE_H

#include <string>
#include <sstream>

using namespace std;

class Node {
    char name;

public:
    Node();
    explicit Node(char name);

    std::string to_string();

    char get_name();
    int get_index();

    void set_name(const char c);

    // overloading the < operator enables functions
    // like std::sort to compare Product objects to
    // order them accordingly
    bool operator < (const Node& n) const {
        return name < n.name; // order by name
    }

    bool operator > (const Node& n) const {
        return name > n.name; // order by name
    }
};


#endif //ASSIGN_3_NODE_H
