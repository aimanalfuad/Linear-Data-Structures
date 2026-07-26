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
        nn->next = *head;
        return;
    }
    
    struct Node* cn = *head;
    do {
        cn = cn->next;
    } while (cn->next != *head);
    
    cn->next = nn;
    nn->next = *head;
}


void DeleteEnd (struct Node** head) {
    if (*head == NULL) return;
    
    struct Node* cn = *head;
    if (cn->next == *head) {
        *head = NULL;
        free (cn);
        return;
    }
    
    struct Node* pn = NULL;
    do {
        pn = cn;
        cn = cn->next;
    } while (cn->next != *head);
    
    pn->next = *head;
    free (cn);
}


void Traverse (struct Node* head) {
    if (head == NULL) return;
    struct Node* cn = head;
    do {
        printf ("%d ", cn->value);
        cn = cn->next;
    } while (cn != head);
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
