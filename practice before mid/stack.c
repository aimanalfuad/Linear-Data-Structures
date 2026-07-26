#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100
int Stack[SIZE];
int top = -1;

bool isFull () {
    if (top >= SIZE) return true;
    return false;
}

bool isEmpty () {
    if (top < 0) return true;
    return false;
}

int getTop () {
    return Stack[top];
}

void Push (int value) {
    if (isFull()) {
        printf ("Overflow");
        return;
    }

    Stack[++top] = value;
}

void Pop () {
    if (isEmpty()) {
        printf ("Underflow");
        return;
    }

    top -= 1;
}

void Traverse () {
    for (int i = 0; i <= top; i++)
        printf ("%d ", Stack[i]);
    printf ("\n");
}

int main () {
    for (int i = 0; i < 5; i++)
        Push (rand() % 101);
    Traverse ();

    for (int i = 0; i < 5; i++) {
        Pop ();
        Traverse ();
    }

    return 0;
}
