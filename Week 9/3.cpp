/*
    Q-03 . Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
program to merge all these files into single file with minimum computation. For given two files
A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
approach)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter Array Size :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter File Size :";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i=1;i<arr.size();i++){
        arr[i] = arr[i]+arr[i-1];
        ans += arr[i];
    }
    cout<<"Minimum Computation is :"<<ans<<endl;
}
