/*
    Q-02 Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap1(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int lb, int ub, int *swap, int *comp) {
    int randomIndex = lb + rand() % (ub - lb + 1);
    swap1(&a[lb], &a[randomIndex]);
    (*swap)++;
    int pivot = a[lb];
    int i = lb;
    int j = ub;

    while (i < j) {
        while (i <= ub && a[i] <= pivot) {
            (*comp)++;
            i++;
        }
        while (a[j] > pivot) {
            (*comp)++;
            j--;
        }
        if (i < j) {
            swap1(&a[i], &a[j]);
            (*swap)++;
        }
    }
    swap1(&a[lb], &a[j]);
    (*swap)++;
    return j;
}
void quickSort(int a[], int lb, int ub, int *swap, int *comp) {
    if (lb < ub) {
        int loc = partition(a, lb, ub, swap, comp);
        quickSort(a, lb, loc - 1, swap, comp);
        quickSort(a, loc + 1, ub, swap, comp);
    }
}
int main() {
    int n, a[50], i;
    printf("Enter Size: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int swap = 0, comp = 0;
    srand(time(0));
    quickSort(a, 0, n - 1, &swap, &comp);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nNumber of comparisons: %d\nNumber of swaps: %d\n", comp, swap);
    return 0;
}

