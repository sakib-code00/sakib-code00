#include <bits/stdc++.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int V, int E, int source) {
    // Initialize distances to all vertices as infinity
    vector<int> distance(V, INT_MAX);

    // Distance from the source to itself is 0
    distance[source] = 0;

    // Relax edges repeatedly to find the shortest paths
    for (int i = 1; i <= V - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            // Relax the edge
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To vertex " << i << ": ";
        if (distance[i] == INT_MAX) {
            cout << "INF";
        } else {
            cout << distance[i];
        }
        cout << "\n";
    }
}

int main() {

    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int V = 5; // Number of vertices
    int E = edges.size(); // Number of edges
    int source = 0; // Source vertex

    bellmanFord(edges, V, E, source);

    return 0;
}
