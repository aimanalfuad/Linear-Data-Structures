// Insertion Sort Algorithm
#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int a[], int n){
}

int main(void){
    int arr[] = {0, 1, 8, 8, 4, 6, 4, 4, 9, 8, 1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
