/*
    Q-01 Assume that a project of road construction to connect some cities is given to your friend. Map of
these cities and roads which will connect them (after construction) is provided to him in the form
of a graph. Certain amount of rupees is associated with construction of each road. Your friend
has to calculate the minimum budget required for this project. The budget should be designed in
such a way that the cost of connecting the cities should be minimum and number of roads
required to connect all the cities should be minimum (if there are N cities then only N-1 roads
need to be constructed). He asks you for help. Now, you have to help your friend by designing an
algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)
*/
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
