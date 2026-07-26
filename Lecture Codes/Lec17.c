#include <stdio.h>
#include <stdlib.h>

void ToH (int n, char A, char B, char C) {
    if (n == 1) { 
        printf ("<%c,%c> ", A, B);
        return;
    }
    
    ToH (n-1, A, C, B);
    printf ("<%c,%c> ", A, B);
    ToH (n-1, C, B, A);
}


int main () {
    ToH (20, 'A', 'B', 'C');
    printf ("\n");
    return 0;
} 
