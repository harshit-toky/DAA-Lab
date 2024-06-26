/*
    Q-02 Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N.

*/
#include<iostream>
#include<vector>

using namespace std;

void findWays(vector<int> coins,int sum){
    int n = coins.size();
    vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] += dp[i - 1][j];
            if ((j - coins[i - 1]) >= 0) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    cout<<"Total No. of Ways :"<<dp[n][sum];
}

int main(){
    int n;
    cout<<"Enter No. of Coins :";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter Coin Values :";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int sum;
    cout<<"Enter Sum :";
    cin>>sum;
    findWays(coins,sum);
}
