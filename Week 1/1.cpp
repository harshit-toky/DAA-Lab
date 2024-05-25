/*Q-01 Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/
#include<iostream>
#include<vector>
using namespace std;

void linearSearch(vector<int> arr,int n, int key){
    int i;
    for(i=0;i<n;i++){
        if(arr[i] == key)
            break;
    }
    if(i != n){
        cout << "Present "<<i+1<<endl;
    }else{
        cout<<"Not Present"<<endl;
    }
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
    linearSearch(arr,n,key);
}
