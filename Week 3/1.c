/*
    Q-01 Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
total number of times the array elements are shifted from their place) required for sorting the
array.
*/
#include<stdio.h>

void insertionSort(int a[],int n){
    int i,j,t;
    int shifts=0,comparisons=0;
    for(i=1;i<n;i++){
        comparisons++;
        t=a[i];
        j=i-1;
        while(j>=0 && a[j]>t){
            a[j+1]=a[j];
            j--;
            shifts++;
            comparisons++;
        }
        a[j+1]=t;
    }

    printf("Sorted Array is :");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nShifts =%d\nComparisons =%d",comparisons,shifts);

}
void main()
{
    int n,a[50],key,i;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    insertionSort(a,n);
}
