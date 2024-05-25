/*
    Q-03 Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findDiff(vector<int> arr,int n,int key){
    int c=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i] == key){
                c++ ;
                break;
            }
        }
    }
    cout<<"Total Pairs :"<<c;
}

int main(){
    int n;
    cout<<"Enter Size :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array :";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int key;
    cout<<"Enter Key :";
    cin >> key;
    findDiff(arr,n,key);
}
