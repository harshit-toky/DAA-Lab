#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void getPermutation(string str, int curr, int size,vector<string> &ans){
    if(curr == size){
        ans.push_back(str);
        return;
    }

    for(int i=curr;i<=size;i++){
        swap(str[curr], str[i]);

        getPermutation(str, curr+1, size, ans);

        swap(str[curr], str[i]);
    }
}

int main(){
    string str;
    cout<<"Enter String :";
    cin>>str;
    vector<string> ans;
    getPermutation(str, 0, str.length()-1,ans);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
