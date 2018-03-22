#include <vector>


#include "Graph.h"
#include "FileParser.h"
#include "Dijkstra.h"
#include "PrintHelper.h"

#define INF_DISTANCE std::numeric_limits<int>::max()

using namespace std;

int main(){

    string alg_name;
    string using_weight;

    Graph graph = FileParser::parse_ntw_topology("../files/bilbomap.txt");
    vector<pair<string, Node> > list;
    FileParser::parse_homes("../files/bilbohomes.txt", list);

    Node dest;
    for (unsigned int i = 0; i < list.size(); i++) {
        if (list[i].first == "Bilbo"){
            dest = list[i].second;
        }
    }

    alg_name = "Shortest_Distance_Path (SDP)";
    using_weight = "distance";
    PrintHelper::print_header(alg_name, dest.to_string());

    for (unsigned int i = 0; i < list.size(); i++) {
        Node src = list[i].second;
        if (dest.get_name() != src.get_name()){
            vector<Edge> path;
            Dijkstra::dijkstra_distance(graph, src, dest, path, using_weight);
            PrintHelper::print_row(graph, src, dest, path, list[i].first);
        }
    }

    PrintHelper::print_footer();

    return 0;
}