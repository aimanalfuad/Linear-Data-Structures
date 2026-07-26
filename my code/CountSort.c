#include <stdio.h>

#define SIZE 100

void CountSort(int lb, int ub, int A[]){
    int max = -1;
    for(int i = lb; i <= ub; i++)
        if(A[i] > max) max = A[i];

    int B[max + 1];
    for(int i = lb; i <= max; i++)
        B[i] = 0;
    for(int i = lb; i <= ub; i++){
        B[A[i]]++;
    }
    int k = 0;
    for(int i = lb; i <= ub; ){
        while(B[k] > 0){
            A[i++] = k;
            B[k]--;
        }
        k++;
    }
}

void Traverse(int lb, int ub,int A[]){
    for(int i = lb; i <= ub; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main() {
    int A[SIZE] = {0, 1, 8, 8, 4, 6, 4, 9, 8, 1, 4};
    int lb =0;
    int ub = 10;
    CountSort(lb, ub, A);
    Traverse(lb, ub, A);

    return 0;
}
