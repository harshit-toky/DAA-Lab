/*
    Q-02 Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)
*/
#include<bits/stdc++.h>
using namespace std;

void input(int **graph,int n){
    cout<<"Enter Adjacency Matrix :";
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
}

bool bfs(int **graph,int n)
{
    queue<int> q;
    vector<int> status(n,0);
    q.push(0);
    status[0] =1;
    while(!q.empty()){
        int popped = q.front();
        q.pop();
        if(graph[popped][popped] == 1)
            return false;
        for(int i=0;i<n;i++){
            if(graph[popped][i]==1 && status[i] == 0){
                status[i] = 1 + status[popped];
                q.push(i);
            }
            else if(graph[popped][i] ==1 && status[i] == status[popped])
                return false;
        }
    }
    return true;
}


int main()
{
    int i,n;
    cout<<"Enter No. of Vertices :";
    cin>>n;
    int **graph = new int*[n];
    for(i=0;i<n;i++)
        graph[i] = new int[n];
    input(graph,n);
    bool ans = bfs(graph,n);
    if(ans)
        cout<<"Yes, Bipartite Graph\n";
    else
        cout<<"No";
}
