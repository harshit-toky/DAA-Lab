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

bool checkCycle(int **graph, int n){
    stack<int> s;
    vector<int> status(n,0);

    for (int i = 0; i < n; ++i) {
        if (status[i] == 0) {
            s.push(i);
            while (!s.empty()) {
                int popped = s.top();
                s.pop();
                if (status[popped] == 0) {
                    status[popped] = 1;
                    for (int j = 0; j < n; ++j) {
                        if (graph[popped][j] == 1) {
                            if (status[j] == 1)
                                return true;  // Cycle detected
                            s.push(j);
                        }
                    }
                }
                status[popped] = 2; // Node is completely processed
            }
        }
    }
    return false;

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
    bool ans =checkCycle(graph,n);
    if(ans)
        cout<<"Cycle Exists";
    else
        cout<<"No Cycle Exists";
}
