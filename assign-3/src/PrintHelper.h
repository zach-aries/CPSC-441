//
// Created by Zachary Aries on 2018-03-21.
//

#ifndef ASSIGN_3_PRINTHELPER_H
#define ASSIGN_3_PRINTHELPER_H

#include <iostream>
#include <iomanip>

#include "Graph.h"
#include "Dijkstra.h"

using namespace std;

class PrintHelper {
public:
    static void print_header(string alg_name, string dest, string dest_home);
    static tuple<int,int,int,int,int> print_row(Graph& G, Node &source, Node &destination, vector<Edge> &path, string name);
    static void print_footer(tuple<float,float,float,float,float> avg_stats);
};


#endif //ASSIGN_3_PRINTHELPER_H
