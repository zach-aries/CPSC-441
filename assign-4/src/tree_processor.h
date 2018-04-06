//
// Created by Zachary Aries on 2018-04-05.
//

#ifndef ASSIGN_4_TREE_PROCESSOR_H
#define ASSIGN_4_TREE_PROCESSOR_H

#include <binary_tree.h>


class tree_processor {
    static void process_tree(binary_tree &btree, node* leaf);
public:
    static int probe_count;
    static int successful_count;
    static int idle_count;
    static int collision_count;

    static void process_tree(binary_tree &btree, int depth, node *leaf);

};


#endif //ASSIGN_4_TREE_PROCESSOR_H
