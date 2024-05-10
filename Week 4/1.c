#include<stdio.h>

void mSort(int a[],int t[],int lb,int mid,int ub,int *c,int *in){
    int k=lb,le=mid;
    while(lb <= le && mid+1 <= ub){
        (*in)++;
        if(a[lb]<a[mid+1]){
            (*c)++;
            t[k] = a[lb];
            k++;
            lb++;
        }
        else{
            (*c)++;
            t[k] = a[mid+1];
            k++;
            mid++;
        }
    }
    while(lb<=le){
        (*in)++;
        t[k] = a[lb];
        k++;
        lb++;
    }
    while(mid+1 <= ub){
        (*in)++;
        t[k] = a[mid+1];
        k++;
        mid++;
    }
    for(int i=0;i<=ub;i++)
        a[i] = t[i];
}

void merge(int a[],int t[],int lb,int ub,int *c,int *in){
    int mid;
    if(lb < ub){
        mid = (lb +ub)/2;
        merge(a,t,lb,mid,c,in);
        merge(a,t,mid+1,ub,c,in);
        mSort(a,t,lb,mid,ub,c,in);
    }
}


void main(){
    int n,i,a[50],t[50];
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Array Elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int c=0,in=0;
    merge(a,t,0,n-1,&c,&in);
    printf("Sorted Array is :");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nTotal No. of Conversions :%d\nTotal No. of Inversions :%d",c,in);
}
