/*
    Q-03 . Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array.
*/
#include<iostream>
#include<vector>
using namespace std;

void calculateMajority(vector<int> arr){
    int count=1,value=arr[0];
    for(int i=1;i<arr.size();i++){
        if(count == 0)
            value = arr[i];
        if(arr[i] == value){
            count++;
        }else{
            count--;
        }
    }
    count=0;
    for(int i=0;i<arr.size();i++){
            if(arr[i] == value) count++;
    }
    if(count > arr.size()/2){
        cout<<"Yes"<<endl;
        cout<<value;
    }else{
        cout<<"No"<<endl;
    }
}

int main(){
    int n;
    cout << "Enter Size :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Elements :";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    calculateMajority(arr);
}
