#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void checkDuplicates(vector<int> arr,int k){
    unordered_map<int,int> frequency;
    int j;
    for(j=0;j<k;j++){
        frequency[arr[j]]++;
        if(frequency[arr[j]] > 1){
            cout << "Duplicates present in window "<<k<<endl;
            return;
        }
    }
    int i=0;
    for(;j<arr.size();j++){
        frequency[arr[i]]--;
        i++;
        frequency[arr[j]]++;
        if(frequency[arr[j]] > 1){
            cout << "Duplicates present in window "<<k<<endl;
            return;
        }
    }
    cout << "Duplicates not present in window "<<k<<endl;
}

int main(){
    int t;
    cout<<"Enter Test-Case :";
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cout<<"Enter Size :";
        cin>>n;
        cout<<"Enter Values :";
        vector<int> arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        cout<<"Enter Window Size :";
        int k;
        cin>>k;
        checkDuplicates(arr,k);
    }
}
