#include "Utility.h"

#define SIZE 100

int InsertEnd (int A[], int ub, int value) {
    ub += 1;
    A[ub] = value;
    return ub;
}

int InsertBegin (int A[], int lb, int ub, int value) {
    if (ub < SIZE - 1) {
        RightShift (A, lb, ub);
        A[0] = value;
        ub += 1;
        return ub;
    }
}

int InsertAny (int A[], int p, int ub, int value) {
    if (ub < SIZE - 1) {
        RightShift (A, p, ub);
        A[p] = value;
        ub += 1;
        return ub;
    }
}

int DeleteEnd (int A[], int ub) {
    return ub - 1;
}  

int DeleteBegin (int A[], int lb, int ub) {
    LeftShift (A, lb, ub);
    ub -= 1;
    return ub;
}

int DeleteAny (int A[], int p, int ub) {
    LeftShift (A, p, ub);
    ub -= 1;
    return ub;
}

int main () {
    int Ar[SIZE];
    int lb, ub;
    lb = 0, ub = -1;

    Initialize (Ar, lb, ub);
    
    ub = InsertBegin (Ar, lb, ub, 34);
    ub = InsertBegin (Ar, lb, ub, 45);
    ub = InsertBegin (Ar, lb, ub, 93);
    ub = InsertBegin (Ar, lb, ub, 64);
    Traverse (Ar, lb, ub);
    
    ub = InsertAny (Ar, 0, ub, 23);
    ub = InsertAny (Ar, 3, ub, 47);
    ub = InsertAny (Ar, 1, ub, 56);
    Traverse (Ar, lb, ub);
    
    ub = DeleteAny (Ar, ub, ub);
    Traverse (Ar, lb, ub);
    ub = DeleteAny (Ar, lb, ub);
    Traverse (Ar, lb, ub);
    ub = DeleteAny (Ar, 2, ub);
    Traverse (Ar, lb, ub);
    
    return 0;
}
