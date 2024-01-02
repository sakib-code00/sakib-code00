#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        if (distance[i] == INT_MAX) {
            cout << "INF";
        } else {
            cout << distance[i];
        }
        cout << "\n";
    }
}

int main() {
    // Example graph: (0,1,4), (0,2,1), (1,3,1), (2,1,2), (2,3,5), (3,4,3)
    vector<vector<Edge>> graph = {
        {{1, 4}, {2, 1}},
        {{3, 1}},
        {{1, 2}, {3, 5}},
        {{4, 3}},
        {}
    };

    int start = 0;

    dijkstra(graph, start);

    return 0;
}

