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

void InsertEnd (struct Node** head, int value) {
    struct Node* nn = CreateNode (value);
    if (*head == NULL) {
        *head = nn;
        return;
    }
    
    struct Node* cn = *head;
    while (cn->next != NULL)
        cn = cn->next;
    
    cn->next = nn;
}

void DeleteEnd (struct Node** head) {
    if (*head == NULL) return;
    
    struct Node* cn = *head;
    struct Node* pn = NULL;
    while (cn->next != NULL) {
        pn = cn;
        cn = cn->next;
    }
    
    if (pn == NULL) {
        *head = NULL;
        free (cn);
        return;
    }
    
    pn->next = NULL;
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
        InsertEnd (&head, rand() % 101);
    Traverse (head);
    
    DeleteEnd (&head);
    Traverse (head);
    DeleteEnd (&head);
    Traverse (head);
    DeleteEnd (&head);
    Traverse (head);
    DeleteEnd (&head);
    Traverse (head);
    DeleteEnd (&head);
    Traverse (head);
    DeleteEnd (&head);
    Traverse (head);
    DeleteEnd (&head);
    Traverse (head);
    return 0;
}
