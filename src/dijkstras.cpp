#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
	int numVertices = G.size();
	vector<int> distances(numVertices, INF);
	vector<bool> visited(numVertices, false);
	distances[source] = 0;
	previous[source] = UNDEFINED;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // pair <weight, vertex> 
	minHeap.push({0, source});

	while (!minHeap.empty()) {
		int u = minHeap.top().second;
		minHeap.pop();

		if (visited[u]) continue;
		visited[u] = true;

		for (Edge edge : G[u]) {
			int v = edge.dst;
			int wgt = edge.weight;
			if (!visited[v] && distances[u] + wgt < distances[v]) {
				distances[v] = distances[u] + wgt;
				previous[v] = u;
				minHeap.push({distances[v], v});
			}
		}
	}
	return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
	stack<int> path_stk;
	
	for (int dst = destination; dst != UNDEFINED; dst = previous[dst]) {
		path_stk.push(dst);
	}

	vector<int> shortest_path;
	
	while (!path_stk.empty()) {
		int next_vertex = path_stk.top();
		path_stk.pop();
		shortest_path.push_back(next_vertex);
	}
	return shortest_path;
}

void print_path(const vector<int>& v, int total){
	for (int vertex : v) {
		cout << vertex << " ";
	}
	cout << endl << "Total cost is " << total << endl;
}