/*
    Q-01 Given a graph, Design an algorithm and implement it using a program to implement FloydWarshall all pair shortest path algorithm
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 99999
void printSolution(int **dist, int V);
void floydWarshall(int **dist,int V)
{
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])&& (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist,V);
}
void printSolution(int **dist, int V)
{
    cout << "Shortest Distance Matrix "<<endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout<<"Enter No. of Vertices :";
    cin>>n;
    int **graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
    }
    cout<<"Enter Adjacency Matrix :"<<endl;
    cin.ignore();
    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        for (int j = 0; j < n; j++) {
            string value;
            ss >> value;
            if (value == "INF") {
                graph[i][j] = INF;
            } else {
                graph[i][j] = stoi(value);
            }
        }
    }

    floydWarshall(graph,n);
    return 0;
}

