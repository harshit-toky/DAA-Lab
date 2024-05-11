#include<iostream>
#include<vector>

using namespace std;

//The given problem is solved using memoization approach

int checkSubset(vector<int> arr,int index,int n,int sum,vector<vector<int>> &dp){
    if(sum == 0)
        return 1;
    if(index == n-1 && sum !=0)
        return 0;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    return dp[n][sum] = checkSubset(arr,index+1,n,sum,dp) || checkSubset(arr,index+1,n,sum-arr[index],dp);
}

void findHalf(vector<int> arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        cout<<"NO"<<endl;
        return;
    }
    vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
    if(checkSubset(arr,0,n,sum/2,dp))
        cout <<"YES";
    else
        cout<<"NO";
}

int main(){
    int n;
    cout<<"Enter Size :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Element :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findHalf(arr,n);
}
