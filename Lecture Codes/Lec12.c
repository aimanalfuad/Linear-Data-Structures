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

void InsertBegin (struct Node** head, struct Node** tail, int value) {
    struct Node* nn = CreateNode (value);
    if (*head == NULL) {
        *head = *tail = nn;
        return;
    }
    
    nn->next = *head;
    (*head)->prev = nn;
    *head = nn;
}


void DeleteBegin (struct Node** head, struct Node** tail) {
    if (*head == NULL) return;
    struct Node* cn = *head;
    if (cn->next == NULL) {
        *head = *tail = NULL;
        free (cn);
        return;
    }
    
    cn->next->prev = NULL;
    *head = cn->next;
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
        InsertBegin (&head, &tail, rand() % 101);
    TraverseForward (head);
    TraverseBackward (tail);

    DeleteBegin (&head, &tail);
    TraverseForward (head);
    DeleteBegin (&head, &tail);
    TraverseForward (head);
    DeleteBegin (&head, &tail);
    TraverseForward (head);
    DeleteBegin (&head, &tail);
    TraverseForward (head);
    DeleteBegin (&head, &tail);
    TraverseForward (head);
    DeleteBegin (&head, &tail);
    TraverseForward (head);
    DeleteBegin (&head, &tail);
    TraverseForward (head);
    
    return 0;
}
