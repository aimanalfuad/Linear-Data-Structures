#include "Utility.h"

#define SIZE 100

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

int main () {
    int Ar[SIZE];
    int lb = 0, ub = 10;
    
    Initialize (Ar, lb, ub);
    Traverse (Ar, lb, ub);
    
    CountingSort (Ar, lb, ub);
    Traverse (Ar, lb, ub);
    
    return 0;
}
