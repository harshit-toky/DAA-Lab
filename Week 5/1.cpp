/*
    Q-01 Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/
#include<iostream>
using namespace std;
int main(){
    int i,a[26]={0};
    string str;
    cout << "Enter String :";
    cin >> str;
    for(i=0;i<str.length();i++){
        a[str[i]-97]++;
    }
    int max=0,pos=0;
    for(i=0;i<26;i++){
        if(max < a[i]){
            max = a[i];
            pos =i;
        }
    }
    cout<<char('a'+pos)<<" - "<<max<<endl;
}
