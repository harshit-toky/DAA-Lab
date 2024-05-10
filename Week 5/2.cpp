#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void check(vector<int> arr, int target)
{
    sort(arr.begin(),arr.end());
    int left=0,right=arr.size()-1,sum;
    while(left < right){
        sum =arr[left]+arr[right];
        if(sum == target)
            break;
        else if(sum < target)
            left++;
        else
            right--;
    }
    if(sum == target){
        cout<<arr[left]<<" "<<arr[right];
    }
    else
        cout<<"Does not exist";
}

int main()
{
    int n;
    cout<<"Enter Size :";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter Target :";
    cin>>target;
    check(arr,target);
}
