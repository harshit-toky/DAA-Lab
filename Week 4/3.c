/*
    Q-03Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
#include<stdio.h>
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l,temp;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    temp=arr[i];
    arr[i]=arr[r];
    arr[r]=temp;
    return i;
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r,k - index + l - 1);
    }
}
void main()
{
    int n,a[50],i;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k;
    printf("Enter K :");
    scanf("%d",&k);

    int number= kthSmallest(a,0,n-1,k);
    printf("%d",number);
}
