#include "dijkstras.h"

int main(int argc, char *argv[]) {
    string filename = get_arg(argc, argv, "src/small.txt");
    Graph G;
    file_to_graph(filename, G);
	int numVertices = G.size();
	
	int source = 0;
	int destination = 3;

	vector<int> previous(numVertices, UNDEFINED);
	vector<int> distances = dijkstra_shortest_path(G, source, previous);
	vector<int> path = extract_shortest_path(distances, previous, destination);
	print_path(path, distances[destination]);
	return 0;
}