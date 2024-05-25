/*
    Q-02 Given a directed graph, write an algorithm and a program to find mother vertex in a graph. A
mother vertex is a vertex v such that there exists a path from v to all other vertices of the graph.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int i = 0; i < V; ++i) {
            if (adj[v][i] && !visited[i])
                DFSUtil(i, visited);
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1;
    }

    int findMotherVertex() {
        vector<bool> visited(V, false);
        int last_v = 0;

        // Step 1: Perform DFS traversal from each vertex to find the last visited vertex
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFSUtil(i, visited);
                last_v = i;
            }
        }

        // Step 2: Check if last visited vertex can reach all other vertices
        fill(visited.begin(), visited.end(), false);
        DFSUtil(last_v, visited);

        if (all_of(visited.begin(), visited.end(), [](bool val) { return val; }))
            return last_v;
        else
            return -1;
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    // Input adjacency matrix
    cout << "Enter the adjacency matrix:" << endl;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j])
                g.addEdge(i, j);
        }
    }

    cout << "Mother vertex is: " << g.findMotherVertex() << endl;

    return 0;
}

