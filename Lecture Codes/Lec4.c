#include "Utility.h"

#define SIZE 100

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

int main () {
    int Ar[SIZE];
    int lb, ub;
    lb = 0, ub = 10;

    Initialize (Ar, lb, ub);
    Traverse (Ar, lb, ub);
    
    int idx = LinearSearch (Ar, lb, ub, 80);
    if (idx >= 0) printf ("Value is found\n");
    else printf ("value is not found\n");
    
    BubbleSort (Ar, lb, ub);
    Traverse (Ar, lb, ub);
    
    return 0;
}
