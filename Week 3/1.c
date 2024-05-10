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
    printf("\nComparisons =%d\nShifts =%d",comparisons,shifts);

}

void insertionSortRecusrsive(int a[],int n)
{
    if(n <= 1)
        return;
    insertionSortRecusrsive(a,n-1);
    int j = n-2;
    int t = a[n-1];
    while(j>=0 && a[j]>t){
        a[j+1] = a[j];
        j--;
    }
    a[j+1]=t;
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

    insertionSortRecusrsive(a,n);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
