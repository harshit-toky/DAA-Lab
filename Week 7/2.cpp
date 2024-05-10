#include<bits/stdc++.h>
using namespace std;

void bellmanFord(int **graph,int source,int n){
    int *dist =new int[n];
    int i;
    for(i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[source]=0;
}


int main(){
    cout<<"Enter No. of Vertices :";
    int n;
    cin>>n;
    int **graph =new int*[n];
    for(int i=0;i<n;i++){
        graph[i] =new graph[n];
    }
    cout<<"Enter Adjacency Matrix :";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    int source;
    cout<<"Enter Source Node :";
    cin>>source;
    bellmanFord(graph,source,n);
}
