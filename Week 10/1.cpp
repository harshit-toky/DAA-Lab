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
