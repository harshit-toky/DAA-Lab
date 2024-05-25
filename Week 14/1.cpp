/*
    Q-01 Given a number n, write an algorithm and a program to find nth ugly number. Ugly numbers are
those numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12,
15, 16, 18, 20, 24,..... is sequence of ugly numbers.
*/
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
