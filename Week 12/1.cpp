/*
    Q-01 Given two sequences, Design an algorithm and implement it using a program to find the length
of longest subsequence present in both of them. A subsequence is a sequence that appears in the
same relative order, but not necessarily contiguous.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void longestCommonSequence(string str1,string str2){
    vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1));
    vector<vector<char>> s(str1.length()+1, vector<char>(str2.length()+1, '0'));

    for(int i=0;i<str1.length()+1;i++)
        dp[i][0] = 0;
    for(int i=0;i<str2.length()+1;i++)
        dp[0][i] = 0;

    for(int i=1;i<str1.length()+1;i++){
        for(int j=1;j<str2.length()+1;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                s[i][j] = 'D';
            }else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                s[i][j] = 'U';
            }else{
                dp[i][j] = dp[i][j-1];
                s[i][j] = 'L';
            }
        }
    }

    string ans;
    int i=str1.length(),j=str2.length();
    while(s[i][j] != '0'){
        if(s[i][j] == 'D'){
            ans += str1[i-1];
            i--;
            j--;
        }else if(s[i][j] == 'U'){
            i--;
        }else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<"Longest Common Subsequence :"<<ans<<endl<<"Length :"<<ans.length();

}

int main(){
    string str1,str2;
    cout<<"Enter Two Strings :";
    cin>>str1>>str2;
    longestCommonSequence(str1,str2);
}
