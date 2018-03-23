#include <vector>

#include "Graph.h"
#include "FileParser.h"
#include "Dijkstra.h"
#include "PrintHelper.h"

#define INF_DISTANCE std::numeric_limits<int>::max()

using namespace std;

/**
 * helper to output usage message
 *
 * @param name
 */
void show_usage(const string& name) {
    cerr << "Usage: " << name << " <option(s)> <mapfile> <homefile>\n"
         << "Options:\n"
         << "\t-h,--help\tShow this help message\n"
         << "\t-d DESTINATION\tSpecify the destination home. (if not specified, default set to Bilbo)\n\n"
         << "\tAlgorithms: A table will be printed for each algrithm passed (if not specified, default set to -sdp)\n"
         << "\t-sdp\tTraverse the graph using Shortest Distance Path (SDP)\n"
         << "\t-shp\tTraverse the graph using Shortest Hop Path (SHP)\n"
         << "\t-stp\tTraverse the graph using Shortest Time Path (STP)\n"
         << "\t-ftp\tTraverse the graph using Fewest Trolls Path (FTP)\n\n"
         << std::endl;
    exit(1);
}

/**
 * Iterates through the arguments and handles options / errors accordingly
 *
 * @param argc - number of args passed
 * @param argv - argument array
 * @param algorithms - list of algorithms to execute
 * @param dest_name - destination's hobit name
 * @param mapfile
 * @param homefile
 */
void parse_args(int argc, const char * argv[], vector<string>& algorithms,
                string& dest_name, string& mapfile, string& homefile){
    if (argc <  3) {
        // must be at least 2 arguments passed, mapfile & homefile
        // print help message and exit program
        show_usage(argv[0]);
    } else {
        // options have been passed in
        for (int i = 1; i < argc; i++) {
            string arg = argv[i];

            // the last two items need to be a .txt files for mapfile & homefile
            if (i >= (argc - 2)){
                if(arg.substr( arg.length() - 4 ) != ".txt"){
                    // at least one arg isn't a txt file
                    // print help and exit program
                    show_usage(argv[0]);
                }


                if (i == (argc - 2)){ // if second last, set mapfile
                    mapfile = arg;
                } else { // else last item is homefile
                    homefile = arg;
                }
                // handle -d arg
            }else if (arg == "-d" ){
                if (!argv[i+1]) { // if arg is destination then name must be passed as well
                    // if next arg doesnt exist exit program
                    show_usage(argv[0]);
                } else {
                    // set destination
                    dest_name = argv[i+1];
                    i ++;
                    if (dest_name.at(0) == '-' || dest_name.substr( dest_name.length() - 4 ) == ".txt"){
                        // check if dest is actually an option or .txt, if so print help and exit
                        show_usage(argv[0]);
                    }
                }
                // if arg is any of the algorithms, add to algorithms list
            } else if (arg == "-sdp" || arg == "-stp" || arg == "-shp" || arg == "-ftp") {
                algorithms.emplace_back(arg);
            } else if (arg == "-h" || arg == "---help") {
                // unknown argument, show help and exit program
                show_usage(argv[0]);
            } else {
                // unknown argument, show help and exit program
                show_usage(argv[0]);
            }
        }
    }
}

/**
 * main function
 * handles options and executes Dijkstra's algorithm according to files parsed and
 * algorithms specified
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char * argv[]){

    // get arguments to set weight, map and homes
    vector<string> algorithms;  // contains algorithm options
    string dest_name;           // name of Dwarf who is the destination target
    string mapfile;             // mapfile name
    string homefile;           // homefile name

    // parse arguments
    parse_args(argc, argv, algorithms, dest_name, mapfile, homefile);

    // if no algorithms are set then use SDP as default
    // change to any algorithm option to change default
    if (algorithms.empty())
        algorithms.emplace_back("-sdp");

    // if destination not set, then use Bilbo as default
    // change to any hobit name to change default
    if (dest_name.empty())
        dest_name = "Bilbo";




    vector<pair<string, Node> > list; // list of Hobit / Homes
    // parse file and place in node list
    FileParser::parse_homes(homefile, list);
    // create graph object for Dijkstra's from mapfile passed
    Graph graph = FileParser::parse_ntw_topology(mapfile);

    // get the dest node from the destination set in arguments
    Node dest;
    for (unsigned int i = 0; i < list.size(); i++) {
        // if the list @ index i is the destination hobit
        // then set the dest node to the node specified in the list
        if (list[i].first == dest_name){
            dest = list[i].second;
        }
    }

    // go through all algorithms passed
    for (unsigned int i = 0; i < algorithms.size(); i++) {
        // print out the table header
        PrintHelper::print_header(algorithms.at(i), dest.to_string(), dest_name);

        // instantiate ints to track averages
        float tot_hops = 0;
        float tot_dist = 0;
        float tot_time = 0;
        float tot_coins = 0;
        float tot_trolls = 0;

        // for each hobit in the list print out the shortest path to the destination
        for (unsigned int j = 0; j < list.size(); j++) {
            // the source node is the second item in the list @ index
            Node src = list[j].second;
            if (dest.get_name() != src.get_name()){
                // path of Edge object is used to store the table data
                vector<Edge> path;
                Dijkstra::dijkstra_distance(graph, src, dest, path, algorithms.at(i));
                // print table rows
                // tuple = (hops,distance,time,coins,trolls)
                tuple<int,int,int,int,int> stats = PrintHelper::print_row(graph, src, dest, path, list[j].first);

                // use returned tuple of stats to increment totals
                tot_hops += get<0>(stats);
                tot_dist += get<1>(stats);
                tot_time += get<2>(stats);
                tot_coins += get<3>(stats);
                tot_trolls += get<4>(stats);
            }
        }

        // get list size - 1 since we dont calculate the destination path
        // calculate averages and send to footer
        int ls = list.size() - 1;
        PrintHelper::print_footer(make_tuple(tot_hops/ls, tot_dist/ls, tot_time/ls, tot_coins/ls, tot_trolls/ls));
    }

    return 0;
}