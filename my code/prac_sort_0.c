// Selection Sort Algorithm
#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;

        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_index]) min_index = j;
        }
        if(min_index != i) swap(&a[i], &a[min_index]);
    }
}

int main(void){
    int arr[] = {0, 1, 8, 8, 4, 6, 4, 4, 9, 8, 1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
