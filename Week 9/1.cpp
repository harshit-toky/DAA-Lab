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
