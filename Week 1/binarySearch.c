/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/
#include<stdio.h>
int binarySearch(int a[],int n,int key){
    int l=0,r=n-1,count=0;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m] == key){
            count++;
            return count;
        }
        if(a[m] < key){
            l = m+1;
            count++;
        }
        else{
            r=m-1;
            count++;
        }
    }
    return -1;
}
void main(){
    int a[50],n,key,i;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter Key :");
    scanf("%d",&key);
    int flag=binarySearch(a,n,key);
    if(flag != -1){
        printf("Present %d",flag);
    }
    else{
        printf("Not Present");
    }
}
