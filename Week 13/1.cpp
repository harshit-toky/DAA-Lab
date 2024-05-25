/*
    Q-01 Given an array of characters, you have to find distinct characters from this array. Design an
algorithm and implement it using a program to solve this problem using hashing. (Time
Complexity = O(n))
*/
#include<iostream>
#include<map>

using namespace std;

void countFrequency(const string &str) {
    map<char, int> frequency;

    for (char c : str) {
        if (c != ' ') // Ignoring spaces
            frequency[c]++;
    }

    for (auto pair : frequency) {
        cout << pair.first << " - " << pair.second << endl;
    }
}

int main(){
    int n;
    cout<<"Enter Size :";
    cin>>n;
    string str;
    cin.ignore();
    cout<<"Enter String :";
    getline(cin,str);
    countFrequency(str);
}
