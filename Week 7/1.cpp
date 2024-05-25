/*
    Q-01 After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results. Can you also implement the same algorithm and verify the correctness of Akshay’s
results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
*/
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
