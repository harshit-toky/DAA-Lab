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

void dfs(int **graph, int n){
    stack<int> s;
    vector<int> status(n,0);
    int source,dest;
    cout<<"Enter Source and Destination Nodes :";
    cin>>source>>dest;
    source-=1;
    dest-=1;
    s.push(source);
    int poped;
    do{
        poped = s.top();
        status[poped] =1;
        s.pop();
        for(int i=0;i<n;i++){
            if(graph[poped][i] == 1 && status[i] == 0){
                s.push(i);
            }
        }
    }while(poped != dest && !s.empty());
    if(poped == dest)
        cout<<"Yes Path Exists\n";
    else
        cout<<"No Path exists\n";

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
    dfs(graph,n);
}
