#include<stdio.h>
void main(){
    int i,a[50],n,c0=0,temp;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
       if(a[i] == 0){
        temp = a[c0];
        a[c0] = a[i];
        a[i] = temp;
        c0++;
       }
    }
    for(i=c0;i<n;i++){
       if(a[i] == 1){
        temp = a[c0];
        a[c0] = a[i];
        a[i] = temp;
        c0++;
       }
    }
    printf("Sorted Array is :");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
