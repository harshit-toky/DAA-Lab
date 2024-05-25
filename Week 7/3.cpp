/*
    Q-03 Given a directed graph with two vertices ( source and destination). Design an algorithm and
implement it using a program to find the weight of the shortest path from source to destination
with exactly k edges on the path.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int shortestPath(int **graph, int u, int v, int k,int n)
{
   if (k == 0 && u == v)             return 0;
   if (k == 1 && graph[u][v] != INF) return graph[u][v];
   if (k <= 0)                       return INF;
   int res = INF;
   for (int i = 0; i < n; i++)
   {
       if (graph[u][i] != INF && u != i && v != i)
       {
           int rec_res = shortestPath(graph, i, v, k-1, n);
           if (rec_res != INF)
              res = min(res, graph[u][i] + rec_res);
       }
   }
   return res;
}
int main()
{
    cout<<"Enter Size ";
    int n;
    cin >> n;
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
    cout<<"Enter Source and Destination :";
    int u,v,k;
    cin >> u >> v;
    u--;
    v--;
    cout<<"Enter k edges :";
    cin>>k;
    cout << "Weight of the shortest from source to destination is " <<shortestPath(graph, u, v, k, n);
    return 0;
}
