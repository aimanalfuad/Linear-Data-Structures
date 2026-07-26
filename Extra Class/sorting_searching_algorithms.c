// Binary Search and Algorithms
#include <stdio.h>
//#include <string.h> // for memset()

#define SIZE 100

// Swap
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void BubbleSort(int lb, int ub, int A[]){
    for(int i = lb; i <= ub; i++){
        for(int j = lb; j <= ub - 1 - i; j++){
            if(A[j] > A[j + 1]) Swap(&A[j], &A[j + 1]);
        }
    }
}

// Selection Sort
void SelectionSort(int lb, int ub, int A[]){
    for(int i = lb; i <= ub; i++){
        int min_indx = i;

        for(int j = i; j <= ub; j++){
            if(A[j] < A[min_indx]) min_indx = j;
        }

        if(min_indx != i) Swap(&A[i], &A[min_indx]);
    }
}

// Insertion Sort
void InsertionSort(int lb, int ub, int A[]){
    for(int i = lb + 1; i <= ub; i++){
        int key = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Counting Sort // My own implementation
void CountingSort(int lb, int ub, int A[]){
    int max = -1;
    for(int i = lb; i <= ub; i++)
        if(A[i] > max) max = A[i];

    int B[max + 1];
    //memset(B, 0, sizeof(B));
    for(int i = 0; i <= max; i++)
        B[i] = 0;
    for(int i = lb; i <= ub; i++){
        B[A[i]]++;
    }
    //Traverse(lb, max, B);
    int j = 0;
    for(int i = lb; i <= ub; ){
        while(B[j] > 0){
            A[i++] = j;
            B[j]--;
        }
        j++;
    }
}

// Binary Search
int BinarySearch(int lb, int ub, int A[], int val){
    int low = lb, high = ub;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(A[mid] == val) return mid;
        else if(A[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Traverse
void Traverse(int lb, int ub, int A[]){
    for(int i = lb; i <= ub; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void){
    int a[SIZE] = {0, 1, 8, 8, 4, 6, 4, 9, 8, 1, 4};
    int lb = 0, ub = 10;

    //BubbleSort(lb, ub, a);
    //SelectionSort(lb, ub, a);
    //InsertionSort(lb, ub, a);
    CountingSort(lb, ub, a);
    Traverse(lb, ub, a);

    int indx = BinarySearch(lb, ub, a, 6);

    if(indx != -1) printf("Element found at index %d\n", indx);
    else puts("Element not found!");

    return 0;
}
