#include <stdio.h>
#include <stdlib.h>

struct Node {
    int a;
    int b;
};

int main () {
    struct Node *p;
    p = (struct Node*) malloc (sizeof(struct Node));
    p->a = 10;
    printf ("%d\n", p->a);
    return 0;
}

/*
int main () {
    int *p;
    p = (int*) calloc (SIZE, sizeof(int));
    p[1] = 10;
    p[2] = 30;
    printf ("%d %d\n", p[1], p[2]);
    free (p);
    printf ("%d %d\n", p[1], p[2]);
    return 0;
}
*/
/*
int main () {
    int *p;
    p = (int*) malloc (sizeof(int));
    *p = 10;
    printf ("%d\n", *p);
    *p += 5;
    printf ("%d\n", *p);
    free (p);
    printf ("%d\n", *p);
    return 0;
}
*/
/*
int main () {
    int a = 10, *p, **q;
    p = &a;
    q = &p;
    printf ("a: %d, *p: %d, **q: %d\n", a, *p, **q);
    
    **q = 20;
    printf ("a: %d, *p: %d, **q: %d\n", a, *p, **q);
    
    return 0;
}
*/
