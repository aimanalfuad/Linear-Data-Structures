// Bubble Sort Algorithm
#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
        }
    }
}

int main(void){
    int arr[] = {0, 1, 8, 8, 4, 6, 4, 4, 9, 8, 1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
