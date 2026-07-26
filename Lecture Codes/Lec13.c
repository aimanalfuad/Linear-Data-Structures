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

void InsertEnd (struct Node** head, struct Node** tail, int value) {
    struct Node* nn = CreateNode (value);
    if (*head == NULL) {
        *head = *tail = nn;
        return;
    }
    
    (*tail)->next = nn;
    nn->prev = *tail;
    *tail = nn;
}


void DeleteEnd (struct Node** head, struct Node** tail) {
    if (*head == NULL) return;
    struct Node* cn = *tail;
    if (cn->prev == NULL) {
        *head = *tail = NULL;
        free (cn);
        return;
    }
    
    cn->prev->next = NULL;
    *tail = cn->prev;
    free (cn);
}


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

    for (int i = 0; i < 5; i++)
        InsertEnd (&head, &tail, rand() % 101);
    TraverseForward (head);
    TraverseBackward (tail);

    DeleteEnd (&head, &tail);
    TraverseForward (head);
    DeleteEnd (&head, &tail);
    TraverseForward (head);
    DeleteEnd (&head, &tail);
    TraverseForward (head);
    DeleteEnd (&head, &tail);
    TraverseForward (head);
    DeleteEnd (&head, &tail);
    TraverseForward (head);
    DeleteEnd (&head, &tail);
    TraverseForward (head);
    DeleteEnd (&head, &tail);
    TraverseForward (head);
    
    return 0;
}
