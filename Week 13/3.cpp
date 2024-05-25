/*
    Q-03 Given an array of nonnegative integers, Design an algorithm and implement it using a program
to find two pairs (a,b) and (c,d) such that a*b = c*d, where a, b, c and d are distinct elements of
array.
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void findPair(vector<int> arr){
    unordered_map<int, pair<int,int>> map;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(map.find(arr[i]*arr[j]) != map.end()){
                cout<<arr[i]<<" "<<arr[j]<<endl;
                cout<<map[arr[i]*arr[j]].first<<" "<<map[arr[i]*arr[j]].second<<endl;
                return;
            }
            map[arr[i]*arr[j]] = {arr[i],arr[j]};
        }
    }
}

int main(){
    int n;
    cout<<"Enter Size :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array Elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findPair(arr);
}
