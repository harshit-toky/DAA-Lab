#include<stdio.h>

void quickSort(int a[],int lb,int ub,int *swap,int *comp)
{
    int i=lb,j=ub,pivot=a[lb],temp;
    if(lb >= ub)
        return;
    while(i < j){
        (*comp)++;
        while(pivot>=a[i] && i<j){
            i++;
        }
        (*comp)++;
        while(pivot<a[j]){
            j--;
        }
        if(i < j){
            (*swap)++;
            temp =a[i];
            a[i] =a[j];
            a[j] =temp;
        }
    }
    (*swap)++;
    a[lb] = a[j];
    a[j] = pivot;
    quickSort(a,lb,j-1,swap,comp);
    quickSort(a,j+1,ub,swap,comp);

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
    int swap=0,comp=0;
    quickSort(a,0,n-1,&swap,&comp);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n%d\n%d",comp,swap);
}
