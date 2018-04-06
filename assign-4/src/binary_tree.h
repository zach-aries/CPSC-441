//
// Created by Zachary Aries on 2018-04-05.
//

#ifndef ASSIGN_4_BINARY_TREE_H
#define ASSIGN_4_BINARY_TREE_H

#include <iostream>
#include <vector>
#include <cmath>

struct node
{
    int station_number;
    int state;
    int depth;
    node *left;
    node *right;
};

class binary_tree {
private:
    void destroy_tree(node *leaf);
    void create_tree(std::vector<std::pair<int,bool> > stations, node *leaf);

public:
    node *root;

    binary_tree();
    binary_tree(std::vector<std::pair<int,bool> > stations);
    ~binary_tree();

    void search(int key, std::vector<int> &ready_stations);
    void search(int key, std::vector<int> &ready_stations, node *leaf);
    void destroy_tree();
};


#endif //ASSIGN_4_BINARY_TREE_H
