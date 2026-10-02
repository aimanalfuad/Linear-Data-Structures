#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next ;
}Node;

Node* getNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert
void insertHead(Node** head, int val){
    Node* newNode = getNode(val);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int val){
    Node* newNode = getNode(val);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void inserNth(Node** head, int val, int n){
    Node* newNode = getNode(val);
    if(n == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int i = 0;
    while(i < n - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("Insert not possible!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete
void deleteBegin(Node** head){
    Node* toDelete = *head;
    *head = (*head)->next;
    free(toDelete);
    toDelete = NULL;
}

void deleteEnd(Node** head){
    Node* toDelete = *head;
    while(toDelete->next->next != NULL){
        toDelete = toDelete->next;
    }
    free(toDelete->next);
    toDelete->next = NULL;
}

void deleteNth(Node** head, int n){
    Node* toDelete = *head;
    if(n == 0){
        *head = (*head)->next;
        free(toDelete);
        toDelete = NULL;
        return;
    }
    Node* prev = NULL;
    int i = 0;
    while(i < n && toDelete != NULL){ // insertNth -> condition i < n - 1;
        prev = toDelete;              // deleteNth -> condition i < n;
        toDelete = toDelete->next;
        i++;
    }
    if(toDelete == NULL){
        printf("Node doesn't exist!\n");
        return;
    }
    prev->next = toDelete->next;
    free(toDelete);
    toDelete = NULL;
}

void printList(Node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }printf("NULL\n");
}

int main(void){
    Node* head = NULL;
    insertHead(&head, 4);
    insertHead(&head, 6);
    insertHead(&head, 4);
    insertHead(&head, 9);
    insertHead(&head, 8);
    printList(head);

    insertEnd(&head, 99);
    printList(head);

    // inserNth(&head, 46, 5);
    // inserNth(&head, 46, 1);
    // inserNth(&head, 46, 0);
    inserNth(&head, 46, 1);
    printList(head);

    deleteBegin(&head);
    printList(head);

    deleteEnd(&head);
    printList(head);
    printf("-------\n");

    deleteNth(&head, 4);
    printList(head);

    return 0;
}
