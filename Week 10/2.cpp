#include<bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
    if(p1.first.second == p2.first.second)
        return p1.first.first < p2.first.first;
    return p1.first.second < p2.first.second;
}

void activitySelection(vector<pair<pair<int,int>,int>> arr){
    sort(arr.begin(),arr.end(),comp);
    vector<int> ans;
    ans.push_back(1);
    int time = arr[0].first.first;
    for(int i=1;i<arr.size();i++){
        if(arr[i].first.first + time <= arr[i].first.second){
            ans.push_back(arr[i].second+1);
            time += arr[i].first.first;
        }
    }
    cout<<"No. of non-conflicting Activities :" << ans.size()<<endl;
    cout<<"List of Selected Activities :";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter Total Tasks :";
    cin>>n;
    vector<pair<pair<int,int>,int>> arr(n);
    cout<<"Enter Time Taken :";
    for(int i=0;i<n;i++){
        cin  >> (arr[i].first.first);
    }
    cout<<"Enter Deadline :";
    for(int i=0;i<n;i++){
        cin>>arr[i].first.second;
        arr[i].second = i;
    }
    activitySelection(arr);
}

