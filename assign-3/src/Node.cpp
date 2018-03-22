//
// Created by Zachary Aries on 2018-03-21.
//

#include "Node.h"

Node::Node(){
    this->name = '\0';
}

Node::Node(const char name) {
    this->name = name;
}

std::string Node::to_string() {
    std::stringstream ss;
    std::string s;

    ss << get_name();
    ss >> s;

    return s;
}

char Node::get_name() {
    return  this->name;
}

int Node::get_index() {
    if (name)
        return name - 65;
    else
        return - 1;
}

void Node::set_name(const char c) {
    this->name = c;
}