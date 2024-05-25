/*
    Q-01 Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

*/
#include<stdio.h>
void main(){
    int i,a[50],n,key,count=0;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Array Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter Key :");
    scanf("%d",&key);
    int l=0,r=n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == key){
            count++;
            for(i=mid-1;i>=0;i--){
                if(a[i]!=key)
                    break;
                else
                    count ++;
            }
            for(i=mid+1;i<n;i++){
                if(a[i]!=key)
                    break;
                else
                    count++;
            }
        }
        if(a[mid]<key){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(count == 0)
        printf("Not Found\n");
    else
        printf("%d %d\n",key,count);
}
