/*
    Q-02 Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.
*/

#include<stdio.h>

void selectionSort(int a[],int n){
    int i,j,pos,comp=0,swaps=0;
    for(i=0;i<n-1;i++){
        pos =i;
        for(j=i+1;j<n;j++){
            comp++;
            if(a[j] < a[pos]){
                pos = j;
            }
        }

            swaps++;
            int temp = a[pos];
            a[pos] = a[i];
            a[i]=temp;
    }
    printf("Swaps :%d\nComparisons :%d\n",swaps,comp);
}

void main()
{
    int n,i,a[50];
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Array Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    printf("Sorted Array is :");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
