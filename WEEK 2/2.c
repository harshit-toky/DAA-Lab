#include<stdio.h>
void main(){
    int n,a[50],i,j,k;
    printf("Enter Size :");
    scanf("%d",&n);
    printf("Enter Array :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        j=0;
        k=i-1;
        while(j<k && a[j]+a[k] != a[i]){
            if(a[j]+a[k] < a[i])
                j++;
            else if(a[j]+a[k] > a[i])
                k--;
        }
        if(a[j]+a[k] == a[i])
            break;
    }
    if(a[j] + a[k] != a[i])
        printf("No Sequence Found\n");
    else
        printf("%d %d %d\n",j,k,i);
}
