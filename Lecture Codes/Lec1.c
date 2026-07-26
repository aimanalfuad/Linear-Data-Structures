#include <stdio.h>
#include <stdlib.h>

int main () {
    int A;
    int Ar[5];
    
    A = 10;
    Ar[3] = 10;
    
    printf ("%d %d\n", A, Ar[3]);
    
    A += 10;
    Ar[3] += 10;
    printf ("%d %d\n", A, Ar[3]);
        
    return 0;
}
