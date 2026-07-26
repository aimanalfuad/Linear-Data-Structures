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

void InsertAny (struct Node** head, int value, int pos) {
    struct Node* nn = CreateNode (value);
    if (*head == NULL || pos == 0) {
        nn->next = *head;
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
    
    nn->next = cn;
    pn->next = nn;
}

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

    InsertAny (&head, 34, 0);
    InsertAny (&head, 43, 0);
    InsertAny (&head, 54, 1);
    InsertAny (&head, 78, 2);
    InsertAny (&head, 3, 1);
    Traverse (head);
    
    DeleteAny (&head, 1);
    Traverse (head);
    DeleteAny (&head, 0);
    Traverse (head);
    DeleteAny (&head, 1);
    Traverse (head);
    DeleteAny (&head, 0);
    Traverse (head);
    DeleteAny (&head, 0);
    Traverse (head);
    
    
    return 0;
}
