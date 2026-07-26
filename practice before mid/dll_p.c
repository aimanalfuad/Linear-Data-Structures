#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* getNode(int val){
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insertion
void insertBegin(struct Node** head, int val){
    struct Node* newNode = getNode(val);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEnd(struct Node** head, int val){
    struct Node* newNode = getNode(val);

    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

}

void insertNth(struct Node** head, int val, int n){
    struct Node* newNode = getNode(val);

    if(n == 0){
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    int i = 0;
    struct Node* curr = *head;
    while(curr != NULL && i < n - 1){
        curr = curr->next;
        i++;
    }

    if(curr == NULL){
        printf("Insertion not possible!\n");
        return;
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    if(curr->next != NULL)
        curr->next->prev = newNode;
    curr->next = newNode;

}

// Delete
void deleteBegin(struct Node** head){
    if(*head == NULL){
        printf("Empty list!\n");
        return;
    }
    struct Node* toDelete = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(toDelete);
    toDelete = NULL;
}

void deleteEnd(struct Node** head){
    struct Node* toDelete = *head;

    if(*head == NULL) return;

    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    while(toDelete->next != NULL){
        toDelete = toDelete->next;
    }
    toDelete->prev->next = NULL;
    free(toDelete);
}

void deleteNth(struct Node** head, int n){
    struct Node* toDelete = *head;

    if(n == 0){
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(toDelete);
        return;
    }

    int i = 0;
    while(toDelete != NULL && i < n){
        toDelete = toDelete->next;
        i++;
    }

    if(toDelete == NULL){
        printf("Deletion not possible!\n");
        return;
    }

    toDelete->prev->next = toDelete->next;

    if(toDelete->next){
        toDelete->next->prev = toDelete->prev;
    }

    free(toDelete);
}

// Print
void printList(struct Node* head){
    while(head != NULL){
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reversePrint(struct Node* head){
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(void){
    struct Node* head = NULL;
    insertBegin(&head, 4);
    insertBegin(&head, 6);
    insertBegin(&head, 8);
    // insertBegin(&head, 9);
    // printList(head);
    // reversePrint(head);

    // insertEnd(&head, 99);
    // insertEnd(&head, 78);
    // insertEnd(&head, 68);
    printList(head);
    reversePrint(head);

    insertNth(&head, 64, 3);
    insertNth(&head, 88, 2);
    insertNth(&head, 89, 1);
    insertNth(&head, 99, 0);
    printList(head);
    reversePrint(head);

    deleteBegin(&head);
    printList(head);
    reversePrint(head);

    deleteEnd(&head);
    printList(head);
    reversePrint(head);

    printf("--------\n");
    deleteNth(&head, 1);
    printList(head);
    reversePrint(head);

    return 0;
}
