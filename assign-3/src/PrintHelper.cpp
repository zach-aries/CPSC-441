//
// Created by Zachary Aries on 2018-03-21.
//

#include "PrintHelper.h"

/**
 * prints the table header includes: algorithm used, destination hobit's name, destination node
 *
 * @param alg_name
 * @param dest
 * @param dest_home
 */
void PrintHelper::print_header(const string alg_name, const string dest, const string dest_home) {

    // print the algorithm according to the option passed
    cout << endl;
    if (alg_name == "-sdp")
        cout << "Shortest Distance Path (SDP):" << endl;
    else if (alg_name == "-shp")
        cout << "Shortest Hop Path (SHP):" << endl;
    else if (alg_name == "-stp")
        cout << "Shortest Time Path (STP):" << endl;
    else if (alg_name == "-ftp")
        cout << "Fewest Trolls Path (FTP):" << endl;

    // simple table printing
    cout << "Destination is " << dest_home << "'s home at node " << dest << endl << endl;
    cout << setw(10) << left << "Dwarf"; cout << " | ";
    cout << setw(4) << left << "Home"; cout << " | ";
    cout << setw(4) << left << "Hops"; cout << " | ";
    cout << setw(8) << left << "Distance"; cout << " | ";
    cout << setw(6) << left << "Time"; cout << " | ";
    cout << setw(5) << left << "Gold"; cout << " | ";
    cout << setw(6) << left << "Trolls"; cout << " | ";
    cout << setw(10) << left << "Path" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}

/**
 * calculates and prints path of hobit stats
 *
 * @param G
 * @param source
 * @param destination
 * @param path
 * @param name
 * @return sum of stats as edge
 */
tuple<int,int,int,int,int> PrintHelper::print_row(Graph &G, Node &source, Node &destination, vector<Edge> &path,
                            string name) {

    // set all variables needed for stats
    string home = source.to_string();
    int hops = 0;
    int dist = 0;
    int time = 0;
    int coins = 0;
    int trolls = 0;
    // set start of path as the source node
    string path_s = source.to_string() + " ";

    // for each edge in list, print the stats in reverse order.
    // this will get us the path taken
    // ** set in reverse because of the way the shortest path was created in the Dijkstra function **
    for(int i = (int)path.size() - 1; i >= 0; i--){
        // increment all stats according to the edge
        Edge e = path[i];
        path_s += e.get_to().to_string() + " ";
        hops ++;
        dist += e.get_distance();
        time += e.get_travel_time();
        coins += e.get_coins();
        trolls += e.get_trolls();
    }

    // standard table printing
    cout << setw(10) << left << name; cout << " | ";
    cout << setw(4) << left << home; cout << " | ";
    cout << setw(4) << left << hops; cout << " | ";
    cout << setw(8) << right << dist; cout << " | ";
    cout << setw(6) << right << time; cout << " | ";
    cout << setw(5) << right << coins; cout << " | ";
    cout << setw(6) << right << trolls; cout << " | ";
    cout << setw(21) << left << path_s;
    cout << endl;

    return make_tuple(hops,dist, time, coins, trolls);
}

/**
 * prints out average stats
 *
 * @param avg_stats (hops, distance, time, gold, trolls)
 */
void PrintHelper::print_footer(tuple<float,float,float,float,float> avg_stats) {
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "AVERAGE"; cout << " | ";
    cout << setw(4) << ""; cout << " | ";
    cout << setw(4) << left << setprecision(2) << fixed << get<0>(avg_stats); cout << " | ";  // hops
    cout << setw(8) << right << setprecision(2) << fixed << get<1>(avg_stats); cout << " | "; // distance
    cout << setw(6) << right << setprecision(2) << fixed << get<2>(avg_stats); cout << " | "; // time
    cout << setw(5) << right << setprecision(2) << fixed << get<3>(avg_stats); cout << " | "; // gold
    cout << setw(6) << right << setprecision(2) << fixed << get<4>(avg_stats); cout << " | "; // trolls
    cout << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}
