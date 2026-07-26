#include "Utility.h"

#define SIZE 100

int BinarySearch (int A[], int lb, int ub, int value) {
    int beg = lb;
    int end = ub;
    
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (A[mid] == value) return mid;
        else if (A[mid] > value) end = mid - 1;
        else beg = mid + 1;
    }
    return -1;
}

void Update (int A[], int idx, int value) {
    A[idx] = value;
}

int Merge (int A[], int lb1, int ub1, int B[], int lb2, int ub2) {
    for (int i = ub1 + 1; i <= ub1 + ub2 + 1; i++) 
        A[i] = B[i - ub1 - 1];
    return ub1 + ub2 + 1;
} 

int main () {
    int Ar[SIZE];
    int Br[SIZE] = {34, 56, 78, 90};
    int lb, ub;
    lb = 0, ub = 10;

    Initialize (Ar, lb, ub);
    Traverse (Ar, lb, ub);
    
    Traverse (Br, 0, 3);
    
    ub = Merge (Ar, lb, ub, Br, 0, 3);
    Traverse (Ar, lb, ub);
    
    return 0;
}
