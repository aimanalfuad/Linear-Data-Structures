#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* CreateNode (int value) {
    struct Node* nn = (struct Node*) malloc (sizeof(struct Node));
    nn->value = value;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void InsertAny (struct Node** head, struct Node** tail, int value, int pos) {
    struct Node* nn = CreateNode (value);
    if (*head == NULL) {
        *head = *tail = nn;
        return;
    }
    
    if (pos == 0) {
        nn->next = *head;
        (*head)->prev = nn;
        *head = nn;
        return;
    }
    
    struct Node* cn = *head;
    struct Node* pn = NULL;
    int i = 0;
    while (cn != NULL && i < pos) {
        pn = cn;
        cn = cn->next;
        i += 1;
    }
    
    if (pn == *tail) {
        pn->next = nn;
        nn->prev = pn;
    }
    
    pn->next = nn;
    nn->prev = pn;
    nn->next = cn;
    cn->prev = nn;
}

/*
void DeleteAny (struct Node** head, int pos) {
    if (*head == NULL) return;
    
    struct Node* cn = *head;
    struct Node* pn = NULL;
    int i = 0;
    while (cn != NULL && i < pos) {
        pn = cn;
        cn = cn->next;
        i += 1;
    }
    
    if (cn == NULL) return;
    if (pn == NULL) {
        *head = cn->next;
        free (cn);
        return;
    }
    pn->next = cn->next;
    free(cn);
}
*/

void TraverseForward (struct Node* head) {
    struct Node* cn = head;
    while (cn != NULL) {
        printf ("%d ", cn->value);
        cn = cn->next;
    }
    printf ("\n");
}

void TraverseBackward (struct Node* tail) {
    struct Node* cn = tail;
    while (cn != NULL) {
        printf ("%d ", cn->value);
        cn = cn->prev;
    }
    printf ("\n");
}

int main () {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    InsertAny (&head, &tail, 34, 0);
    InsertAny (&head, &tail, 43, 0);
    InsertAny (&head, &tail, 54, 1);
    InsertAny (&head, &tail, 78, 2);
    InsertAny (&head, &tail, 3, 1);
    TraverseForward (head);
    TraverseBackward (tail);
    
    return 0;
}
