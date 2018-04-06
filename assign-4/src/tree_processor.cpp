//
// Created by Zachary Aries on 2018-04-05.
//

#include "tree_processor.h"

void tree_processor::process_tree(binary_tree &btree, int depth, node *leaf) {

    if(leaf->depth == depth){
        process_tree(btree, leaf);
    } else {
        process_tree(btree, depth, leaf->left);
        process_tree(btree, depth, leaf->right);
    }
}

void tree_processor::process_tree(binary_tree &btree, node *leaf) {
    probe_count ++;

    std::vector<int> ready_stations;
    btree.search(1, ready_stations, leaf);

    if (ready_stations.size() > 1) {
        process_tree(btree, leaf->left);
        process_tree(btree, leaf->right);
        collision_count ++;
    } else if (ready_stations.size() == 1){
        successful_count ++;
    } else {
        idle_count ++;
    }
}
