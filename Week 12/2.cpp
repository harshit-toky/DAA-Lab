#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void knapsack(int n,vector<int>& weights,vector<int>& values, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    int w = capacity;
    vector<pair<int, int>> selected_items;

    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            selected_items.push_back({weights[i-1], values[i-1]});
            w -= weights[i-1];
        }
    }
    reverse(selected_items.begin(), selected_items.end());
    int max_value = dp[n][capacity];

    cout << "Value = "<<max_value<<endl;
    cout<<"Weights Selected : ";
    for(int i=0;i<selected_items.size();i++){
        cout<<selected_items[i].first << " ";
    }
    cout<<endl;
    cout<<"Values of Weights Selected : ";
    for(int i=0;i<selected_items.size();i++){
        cout<<selected_items[i].second << " ";
    }
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter Size :";
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    cout<<"Enter Weights :";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    cout<<"Enter Values :";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    int capacity;
    cout<<"Enter Capacity :";
    cin >> capacity;
    knapsack(n, weights, values, capacity);
    return 0;
}

