#include<bits/stdc++.h>
using namespace std;

int findParent(vector<int> disjoint, int u){
    while(disjoint[u] > 0){
        u = disjoint[u];
    }

    return u;
}

bool checkLoop(vector<int> &disjoint, int u,int v){
    int w = findParent(disjoint, u);
    int x = findParent(disjoint, v);
    if(w == x)
        return true;

    if(disjoint[w] < disjoint[x]){
        disjoint[w] += disjoint[x];
        disjoint[x] = w;
    }else{
        disjoint[x] += disjoint[w];
        disjoint[w] = x;
    }
    return false;
}

int kruskal(vector<vector<int>> graph, int n){
    set<pair<int, pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j] != 0){
                edges.insert({graph[i][j], {min(i,j),max(i,j)}});
            }
        }
    }

    int minimumWeight =0;
    vector<int> disjoint(n, -1);

    for(auto it : edges){
        bool loop = checkLoop(disjoint, it.second.first, it.second.second);
        if(!loop)
            minimumWeight += it.first;
    }
    return minimumWeight;
}

int main(){
    int n;
    cout<<"Enter Size :";
    cin>>n;
    cout<<"Enter Adjacency Matrix :";
    vector<vector<int>> graph(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    int minimumWeight = kruskal(graph,n);
    cout<<"Minimum Spanning Weight :"<<minimumWeight;
}
