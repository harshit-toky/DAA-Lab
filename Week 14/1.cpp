#include<iostream>
#include<vector>
using namespace std;

int nthUglyNumber(int n) {
    if(n == 1) return n;
    int t2 = 0, t3 = 0, t5 = 0;
    vector<int> k(n);
    k[0] = 1;
    for(int i= 1;i< n ; i++){
        k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
        if(k[i] == k[t2]*2) t2++;
        if(k[i] == k[t3]*3) t3++;
        if(k[i] == k[t5]*5) t5++;
    }
    return k[n-1];
}

int main(){
    int t;
    cout<<"Enter Test-Cases :";
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cout<<"Enter n :";
        cin>>n;
        cout<<nthUglyNumber(n)<<endl;
    }
}
