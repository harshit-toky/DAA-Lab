#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void printPath(const vector<int>& prev, int src, int dest) {
    stack<int> path;
    for (int at = dest; at != -1; at = prev[at]) {
        path.push(at);
    }
    while (!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }
    cout << endl;
}

void bellmanFord(const vector<Edge>& edges, int n, int src) {
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);

    dist[src - 1] = 0;

    for (int i = 1; i < n; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
                prev[edge.dest] = edge.src;
            }
        }
    }
    for (const Edge& edge : edges) {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Graph contains a negative cycle\n";
            return;
        }
    }

    cout << "Shortest paths from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i + 1 << ": ";
        if (dist[i] == INT_MAX)
            cout << "Not reachable";
        else {
            cout << "Weight: " << dist[i] << ", Path: ";
            printPath(prev, src - 1, i);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<Edge> edges;
    cout << "Enter adjacency matrix (source, destination, weight):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }
    int src;
    cout << "Enter source node: ";
    cin >> src;
    bellmanFord(edges, n, src);
    return 0;
}
