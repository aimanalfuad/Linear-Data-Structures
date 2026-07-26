#include <stdio.h>

void ToH(int n, char A, char B, char C){
    if(n == 1){
        printf("<%c, %c> ", A, B);
        return;
    }

    ToH(n - 1, A, C, B);
    printf("<%c, %c> ", A, B);
    ToH(n - 1, C, B, A);
}

int main(void){
    ToH(5, 'A', 'B', 'C');

    return 0;
}
