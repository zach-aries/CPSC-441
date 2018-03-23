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

/**
 * Iteraties through home file and places names/homes in a list of <string,Node> pairs
 *
 * @param file_path
 * @param list - passed as reference so can be used from calling function
 */
void FileParser::parse_homes(string file_path, vector<pair<string, Node> > &list) {
    string line; // container for each line of file
    ifstream input_file(file_path); // file reader

    if (input_file.is_open()) {
        while (getline(input_file, line)) { // while next line exists
            string word; // word container
            string word_arr[2]; // array of size 2 to hold name and destination

            int i = 0; // counter for array index access
            stringstream ssin(line); // stream input for iterating through line
            while (ssin.good() && i < 2){ // while stream is gtg and index isn't out of bound for array
                ssin >> word_arr[i]; // transfer from stream to array
                ++i; // increment index
            }

            string name = word_arr[0]; // get name of Hobit
            Node n(word_arr[1][0]); // get hobit home

            list.emplace_back(make_pair(name, n)); // push to list
        }

        input_file.close(); // close file
    } else {
        cout << "Unable to open file.";
    }
}