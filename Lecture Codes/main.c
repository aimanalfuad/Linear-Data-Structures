#include <stdio.h>
#include <stdlib.h>

void Initialize (int A[], int lb, int ub) {
    for (int i = lb; i <= ub; i++)
        A[i] = rand() % 11;
}

void Traverse (int A[], int lb, int ub) {
    for (int i = lb; i <= ub; i++)
        printf ("%d ", A[i]);
    printf ("\n");
}

#define SIZE 100

int InsertEnd (int A[], int ub, int value) {
    ub += 1;
    A[ub] = value;
    return ub;
}

int main () {
    int Ar[SIZE];
    int lb, ub;
    lb = 0, ub = 10;

    Initialize (Ar, lb, ub);

    ub = InsertEnd (Ar, ub, 34);
    ub = InsertEnd (Ar, ub, 46);
    ub = InsertEnd (Ar, ub, 98);
    ub = InsertEnd (Ar, ub, 35);
    ub = InsertEnd (Ar, ub, 23);
    Traverse (Ar, lb, ub);

    return 0;
}
