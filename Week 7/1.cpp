#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <stack>

using namespace std;

int getMin(const vector<pair<int, int>>& dist, const vector<bool>& status) {
    int minVal = INT_MAX, minIndex;
    for (int i = 0; i < dist.size(); i++) {
        if (!status[i] && minVal >= dist[i].first) {
            minVal = dist[i].first;
            minIndex = i;
        }
    }
    return minIndex;
}

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

void dijkstra(const vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<pair<int, int>> dist(n, {INT_MAX, -1});
    vector<bool> status(n, false);
    vector<int> prev(n, -1);

    dist[src - 1] = {0, -1};

    for (int i = 0; i < n - 1; i++) {
        int index = getMin(dist, status);
        status[index] = true;

        for (int j = 0; j < n; j++) {
            if (!status[j] && graph[index][j] && dist[index].first != INT_MAX &&
                dist[index].first + graph[index][j] < dist[j].first) {

                dist[j].first = dist[index].first + graph[index][j];
                dist[j].second = index;
                prev[j] = index;
            }
        }
    }

    cout << "Shortest paths from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i + 1 << ": ";
        if (dist[i].first == INT_MAX)
            cout << "Not reachable";
        else {
            cout << "Weight: " << dist[i].first << ", Path: ";
            printPath(prev, src - 1, i);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    if (src < 1 || src > n) {
        cout << "Invalid source node!";
        return 1;
    }

    dijkstra(graph, src);

    return 0;
}
