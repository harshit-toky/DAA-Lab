#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMinimum(vector<int> values, vector<bool> status){
    int value =INT_MAX,index;
    for(int i=0;i<values.size();i++){
        if(!status[i] && values[i] < value){
            value = values[i];
            index = i;
        }
    }
    return index;
}

int prims(vector<vector<int>> graph,int n){
    vector<bool> status(n, false);
    int minimumWeight = 0;
    vector<int> values(n, INT_MAX);
    values[0] = 0;

    for(int i=0;i<n;i++){
        int index = findMinimum(values, status);
        status[index] = true;
        minimumWeight += values[index];
        for(int j=0;j<n;j++){
            if(status[j] == false && graph[index][j] != 0 &&values[j] > graph[index][j])
                values[j] = graph[index][j];
        }
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
    int minimumWeight = prims(graph,n);
    cout<<"Minimum Spanning Weight :"<<minimumWeight;
}
