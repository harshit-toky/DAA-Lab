/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k
] and so on. Once the interval (arr[2k
] <
key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
 to find the element
key
*/
#include<stdio.h>
#include<math.h>
int jumpSearch(int a[],int n,int key){
    int k=0,count=0;
    count++;
    if(a[0] == key){
        return count;
    }
    while(pow(2,k) < n){
        count++;
        if(a[(int)pow(2,k)] == key){
            return count;
        }else if(a[(int)pow(2,k+1)] == key){
            return count;
        }else if(a[(int)pow(2,k)] < key && a[(int)pow(2,k+1)] > key)
            break;
        k++;
    }
    for(int i=(int)pow(2,k)+1;i<=(int)pow(2,k+1);i++){
        count++;
        if(a[i] == key)
            return 1;
    }
    return -1;
}
void main(){
    int n,a[50],i,key,flag;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Array Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter Key :");
    scanf("%d",&key);
    flag=jumpSearch(a,n,key);
    if(flag != -1){
        printf("Key Found after %d Comparisons\n",flag);
    }else
        printf("Key Not Found\n");
}
