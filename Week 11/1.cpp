/*
    Q-01 Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
matrices together. To find the optimal solution, you need to find the order in which these
matrices should be multiplied.
*/
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void matrixChainMultiplication(vector<vector<int>> arr){
    int n = arr.size();
    vector<int> position(n+1);
    vector<vector<int>> result(n , vector<int>(n,0));
    position[0] = arr[0][0];
    for(int i=0;i < n;i++){
        position[i+1] = arr[i][1];
    }
    for(int d=1;d < n;d++){
        for(int i=0;i<n-d;i++){
            int j = i+d;
            int val = INT_MAX;
            for(int k=i;k<j;k++){
                val = min(val, result[i][k]+result[k+1][j]+(position[i]*position[k+1]*position[j+1]));
            }
            result[i][j] = val;
        }
    }
    cout<<"Minimum No. of Operations :"<<result[0][n-1];
}

int main(){
    int n;
    cout<<"Enter No. of Matrix Sequences :";
    cin>>n;
    cout<<"Enter Matrix Sequences :";
    vector<vector<int>> arr(n , vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    matrixChainMultiplication(arr);
    return 0;
}
