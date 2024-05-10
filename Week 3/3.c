#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
    int temp[50],i=lb,j=mid+1,k=lb;
    while(i<=mid && j<=ub){
        if(a[i] < a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
            temp[k]=a[i];
            k++;
            i++;
    }
    while(j<=ub){
            temp[k]=a[j];
            k++;
            j++;
    }
    for(i=0;i<=ub;i++){
        a[i] = temp[i];
    }
}
void Sort(int a[],int lb,int ub)
{
    int mid;
    if(lb < ub){
        mid =(lb+ub)/2;
        Sort(a,lb,mid);
        Sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void check(int a[],int n){
    int i;
    for(i=0;i<n-1;i++){
        if(a[i] == a[i+1])
            break;
    }
    if(i != n-1)
        printf("YES");
    else
        printf("NO");
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
    Sort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    check(a,n);
}
