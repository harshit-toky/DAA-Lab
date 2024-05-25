/*
    Q-01 Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.

*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
    return p1.first.second < p2.first.second;
}

void activitySelection(vector<pair<pair<int,int>,int>> arr){
    sort(arr.begin(),arr.end(),comp);
    vector<int> ans;
    ans.push_back(1);
    int finish = arr[0].first.second;
    for(int i=1;i<arr.size();i++){
        if(arr[i].first.first >= finish){
            ans.push_back(i+1);
            finish = arr[i].first.second;
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
    cout<<"Enter Total Values :";
    cin>>n;
    vector<pair<pair<int,int>,int>> arr(n);
    cout<<"Enter Starting Time :";
    for(int i=0;i<n;i++){
        cin  >> (arr[i].first.first);
    }
    cout<<"Enter Finishing Time :";
    for(int i=0;i<n;i++){
        cin>>arr[i].first.second;
        arr[i].second = i;
    }
    activitySelection(arr);
}
