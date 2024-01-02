#include <bits/stdc++.h>

using namespace std;

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    // Create a 2D array to store the shortest distances
    vector<vector<int>> distance(V, vector<int>(V, INT_MAX));

    // Initialize the diagonal with 0, and distances from edges
    for (int i = 0; i < V; ++i) {
        distance[i][i] = 0;
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] != 0) {
                distance[i][j] = graph[i][j];
            }
        }
    }

    // Update the distance matrix using all vertices as intermediates
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest distances between all pairs of vertices
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (distance[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << distance[i][j] << "\t";
            }
        }
        cout << "\n";
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, 6, INT_MAX},
        {3, 0, 2, INT_MAX},
        {6, 2, 0, 1},
        {INT_MAX, INT_MAX, 1, 0}
    };

    int V = graph.size(); // Number of vertices

    floydWarshall(graph, V);

    return 0;
}
