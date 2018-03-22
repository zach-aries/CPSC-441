//
// Created by Zachary Aries on 2018-03-20.
//

#ifndef ASSIGN_3_FILE_PARSER_H
#define ASSIGN_3_FILE_PARSER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "Graph.h"

using namespace std;

class FileParser {

public:
    static Graph parse_ntw_topology(string file_path);
    static void parse_homes(string file_path, vector<pair<string, Node> > &list);
};


#endif //ASSIGN_3_FILE_PARSER_H
