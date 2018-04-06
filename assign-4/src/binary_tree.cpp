//
// Created by Zachary Aries on 2018-04-05.
//

#include "binary_tree.h"

binary_tree::binary_tree() {
    root = nullptr;
}

binary_tree::binary_tree(std::vector<std::pair<int,bool> > stations) {
    root = new node;
    root->state = -1;
    root->depth = 0;
    root->station_number = stations.size() - 1;
    root->left = nullptr;
    root->right = nullptr;

    create_tree(stations, root);
}

binary_tree::~binary_tree() {
    destroy_tree();
}

void binary_tree::create_tree(std::vector<std::pair<int,bool> > stations, node *leaf) {

    if (stations.size() == 1) {
        leaf->state = stations[0].second;
    } else {
        std::vector<std::pair<int,bool> > fh(stations.begin(), stations.begin() + (stations.size() / 2) );
        std::vector<std::pair<int,bool> > sh(stations.begin() + (stations.size() / 2), stations.end() );

        leaf->left = new node;
        leaf->left->state = -1;
        leaf->left->depth = leaf->depth + 1;
        leaf->left->station_number = fh[fh.size() - 1].first;
        leaf->left->left = nullptr;
        leaf->left->right = nullptr;

        leaf->right = new node;
        leaf->right->state = -1;
        leaf->right->depth = leaf->depth + 1;
        leaf->right->station_number = sh[fh.size() - 1].first;
        leaf->right->left = nullptr;
        leaf->right->right = nullptr;

        create_tree(fh, leaf->left);
        create_tree(sh, leaf->right);
    }
}

void binary_tree::search(int key, std::vector<int> &ready_stations) {
    search(key, ready_stations, root);
}

void binary_tree::search(int key, std::vector<int> &ready_stations, node *leaf) {
    if (leaf == nullptr)
        return;
    else {

        if (key == leaf->state) {
            ready_stations.emplace_back(leaf->station_number);
        }

        search(key, ready_stations, leaf->left);
        search(key, ready_stations, leaf->right);
    }
}

void binary_tree::destroy_tree() {
    destroy_tree(root);
}

void binary_tree::destroy_tree(node *leaf) {
    if (leaf != nullptr) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
