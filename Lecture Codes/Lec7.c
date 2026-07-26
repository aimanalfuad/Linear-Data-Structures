#include <stdio.h>
#include <stdlib.h>

void CBR (int *p, int *q) {
    *p = 10;
    *q = 20;
}

int main () {
    int a, b;
    CBR (&a, &b);
    printf ("a: %d, b: %d\n", a, b);
    return 0;
}

/*
int main () {
    int a, *p;
    a = 10;
    p = &a;
    
    printf ("%d %d\n", a, *p);
    
    *p = 20;
    printf ("%d %d\n", a, *p);
    
    return 0;
}
*/
