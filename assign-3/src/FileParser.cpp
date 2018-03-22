//
// Created by Zachary Aries on 2018-03-20.
//

#include "FileParser.h"
#include "Edge.h"

Graph FileParser::parse_ntw_topology(string file_path) {
    string line;
    ifstream input_file(file_path);
    Graph graph;

    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            string word;
            string word_arr[6];

            int i = 0;
            stringstream ssin(line);
            while (ssin.good() && i < 6){
                ssin >> word_arr[i];
                ++i;
            }

            int distance, time, coins, trolls;

            Node from(word_arr[0][0]);
            Node to(word_arr[1][0]);
            distance = stoi(word_arr[2]);
            time = stoi(word_arr[3]);
            coins = stoi(word_arr[4]);
            trolls = stoi(word_arr[5]);

            Edge e1(from, to, distance, time, coins, trolls);
            Edge e2(to, from, distance, time, coins, trolls);
            graph.add_edge(e1);
            graph.add_edge(e2);
        }

        input_file.close();
    } else {
        cout << "Unable to open file.";
    }

    return graph;
}

void FileParser::parse_homes(string file_path, vector<pair<string, Node> > &list) {
    string line;
    ifstream input_file(file_path);

    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            string word;
            string word_arr[2];

            int i = 0;
            stringstream ssin(line);
            while (ssin.good() && i < 2){
                ssin >> word_arr[i];
                ++i;
            }

            string name = word_arr[0];
            Node n(word_arr[1][0]);

            list.emplace_back(make_pair(name, n));
        }

        input_file.close();
    } else {
        cout << "Unable to open file.";
    }
}