#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* getNode(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int val){
    struct Node* nn = getNode(val);

    if(*head == NULL){
        *head = nn;
        nn->next = *head;
        return;
    }

    struct Node* cn = *head;
    do{
        cn = cn->next;
    }while(cn->next != *head);

    cn->next = nn;
    nn->next = *head;
}

void deleteEnd(struct Node** head){
    if(*head == NULL) return;

    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* pn = NULL;
    struct Node* cn = *head;
    do{
        pn = cn;
        cn = cn->next;
    }while(cn->next != *head);

    pn->next = *head;
    free(cn);

}

void traverse(struct Node* head){
    struct Node* cn = head;

    do{
        printf("%d -> ", cn->data);
        cn = cn->next;
    }while(cn != head);
    printf("(Head)\n");
}

int main(void){
    struct Node* head = NULL;
    insertEnd(&head, 4);
    insertEnd(&head, 6);
    insertEnd(&head, 4);
    insertEnd(&head, 9);
    insertEnd(&head, 8);
    insertEnd(&head, 1);
    insertEnd(&head, 4);
    traverse(head);

    deleteEnd(&head);
    deleteEnd(&head);
    deleteEnd(&head);
    traverse(head);

    return 0;
}
