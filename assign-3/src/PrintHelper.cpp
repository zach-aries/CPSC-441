//
// Created by Zachary Aries on 2018-03-21.
//

#include "PrintHelper.h"

void PrintHelper::print_header(string alg_name, string dest) {
    cout << alg_name << endl;
    cout << "Destination is always Bilbo's home at node " << dest << endl << endl;
    cout << setw(10) << left << "Dwarf";
    cout << setw(10) << left << "Home";
    cout << setw(10) << left << "Hops";
    cout << setw(10) << left << "Distance";
    cout << setw(10) << left << "Time";
    cout << setw(10) << left << "Gold";
    cout << setw(10) << left << "Trolls";
    cout << setw(10) << left << "Path" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}

void PrintHelper::print_row(Graph &G, Node &source, Node &destination, vector<Edge> &path,
                            string name) {

    string home = source.to_string();
    int hops = 0;
    int dist = 0;
    int time = 0;
    int coins = 0;
    int trolls = 0;
    string path_s = source.to_string() + " ";

    for(int i = (int)path.size() - 1; i >= 0; i--){
        Edge e = path[i];
        path_s += e.get_to().to_string() + " ";
        hops ++;
        dist += e.get_distance();
        time += e.get_travel_time();
        coins += e.get_coins();
        trolls += e.get_trolls();
    }

    cout << setw(10) << left << name;
    cout << setw(10) << left << home;
    cout << setw(10) << left << hops;
    cout << setw(10) << left << dist;
    cout << setw(10) << left << time;
    cout << setw(10) << left << coins;
    cout << setw(10) << left << trolls;
    cout << setw(10) << left << path_s;
    cout << endl;
}

void PrintHelper::print_footer() {
    cout << "-----------------------------------------------------------------------------------" << endl;
}
