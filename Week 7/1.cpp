#include<bits/stdc++.h>
using namespace std;

int getMin(vector<pair<int,int>> dist,vector<bool> status){
    int minVal=INT_MAX,minIndex;
    for(int i=0;i<dist.size();i++){
        if(status[i] == false && minVal >= dist[i].first){
            minVal = dist[i].first;
            minIndex = i;
        }
    }
    return minIndex;
}

void dijk(int **graph,int n, int src){
    src--;
    vector<pair<int,int>> dist(n);
    vector<bool> status(n);
    for(int i=0;i<n;i++){
        dist[i].first = INT_MAX;
        status[i] = false;
    }
    dist[src].first = 0;
    dist[src].second = -1;
    for(int i=0;i<n-1;i++){
        int index = getMin(dist,status);
        status[index] = true;

        for(int j=0;j <n;j++){
            if(!status[j] && graph[index][j] && dist[index].first != INT_MAX && dist[index].first + graph[index][j] < dist[j].first){
                dist[j].first = dist[index].first + graph[index][j];
                dist[j].second = index;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i].first<<" "<<dist[i].second;
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter No. of Vertices :";
    cin >> n;
    cout << "Enter Adjacency Matrix :";
    int **graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    int src;
    cout<<endl;
    cout<< "Enter Source Node :";
    cin >> src;
    dijk(graph,n,src);
}
