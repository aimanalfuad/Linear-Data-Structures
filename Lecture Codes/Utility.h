#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Traverse (int A[], int lb, int ub) {
    for (int i = lb; i <= ub; i++)
        printf ("%d ", A[i]);
    printf ("\n");
}

void Initialize (int A[], int lb, int ub) {
    srand (time(NULL));
    for (int i = lb; i <= ub; i++)
        A[i] = rand() % 101;
}

void RightShift (int A[], int lb, int ub) {
    for (int i = ub; i >= lb; i--)
        A[i+1] = A[i];
}

int LeftShift (int A[], int lb, int ub) {
    for (int i = lb; i < ub; i++)
        A[i] = A[i+1];
}

void Swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int FindMax (int A[], int lb, int ub) {
    int max = A[lb];
    for (int i = lb+1; i <= ub; i++)
        if (max < A[i]) max = A[i];
    return max;
}

int LinearSearch (int A[], int lb, int ub, int value) {
    for (int i = lb; i <= ub; i++)
        if (A[i] == value)
            return i;
    return -1;
}

void SelectionSort (int A[], int lb, int ub) {
    for (int j = ub; j >= lb; j--) {
        int idx = j;
        for (int i = lb; i <= j; i++) 
            if (A[idx] < A[i]) idx = i;
        if (idx != j)
            Swap (&A[idx], &A[j]);
    }
}

void BubbleSort (int A[], int lb, int ub) {
    for (int j = lb; j <= ub; j++)
        for (int i = lb; i < ub - j; i++)
            if (A[i] > A[i+1]) Swap (&A[i], &A[i+1]);
}

void InsertSort (int A[], int lb, int ub) {
    for (int i = lb+1; i <= ub; i++) {
        int key = A[i];
        int j = i-1;
        
        while (j >= 0 && key < A[j]) {
            A[j+1] = A[j];
            j -= 1;
        }
        A[j+1] = key;
    } 
}

void CountingSort (int A[], int lb, int ub) {
    int max = FindMax (A, lb, ub);
    int C[max+1];
    for (int i = 0; i <= max; i++) C[i] = 0;
    for (int i = lb; i <= ub; i++) C[A[i]] += 1;
    for (int i = 1; i <= max; i++) C[i] += C[i-1];
    Traverse (A, lb, ub);
    Traverse (C, 0, max);
    int B[ub-lb+1];
    for (int i = ub; i >= lb; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]] -= 1;
    }
    for (int i = lb; i <= ub; i++) A[i] = B[i];
}
