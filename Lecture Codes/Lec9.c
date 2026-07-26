#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* CreateNode (int value) {
    struct Node* nn = (struct Node*) malloc (sizeof(struct Node));
    nn->value = value;
    nn->next = NULL;
    return nn;
}

void InsertBegin (struct Node** head, int value) {
    struct Node* nn = CreateNode (value);
    if (*head == NULL) {
        *head = nn;
        return;
    }
    
    nn->next = *head;
    *head = nn;
}

void DeleteBegin (struct Node** head) {
    if (*head == NULL) return;
    
    struct Node* cn = *head;
    *head = cn->next;
    free (cn);
}

void Traverse (struct Node* head) {
    struct Node* cn = head;
    while (cn != NULL) {
        printf ("%d ", cn->value);
        cn = cn->next;
    }
    printf ("\n");
}

int main () {
    struct Node* head = NULL;

    for (int i = 0; i < 5; i++)
        InsertBegin (&head, rand() % 101);
    Traverse (head);
    
    DeleteBegin (&head);
    Traverse (head);
    DeleteBegin (&head);
    Traverse (head);
    DeleteBegin (&head);
    Traverse (head);
    DeleteBegin (&head);
    Traverse (head);
    DeleteBegin (&head);
    Traverse (head);
    DeleteBegin (&head);
    Traverse (head);
    DeleteBegin (&head);
    Traverse (head);
    return 0;
}
