/*
    Q-03 You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
*/
#include<stdio.h>

void show(int a[],int m,int b[],int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i] == b[j]){
            printf("%d ",a[i]);
            i++;
            j++;
        }
        else if(a[i] < b[j])
            i++;
        else
            j++;
    }
}

void main()
{
    int m,n,a[50],b[50],i;
    printf("Enter Size :");
    scanf("%d",&m);
    printf("Enter Elements :");
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    show(a,m,b,n);
}
