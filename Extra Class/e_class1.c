#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int id; // 4
    char name[100]; // 1*100 = 100
    float cgpa; // 4
    struct Student *next;
};

/*
student 0: id, name, cgpa, next: student 1(head)
student 1: id, name, cgpa, next: student 3
student 2: id, name, cgpa, next: student 3
student 3: id, name, cgpa, next: s4
student 4: id, name, cgpa, next: null

if you delete kth position, then put k+1's address to k-1's next.

*/

struct Student* createNode(int id, char name[], float cgpa){
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));

    newStudent->id = id;
    int i=0;
    for(i=0; name[i]!='\0'; i++){
        newStudent->name[i] = name[i];
    }
    newStudent->name[i] = '\0';

    newStudent->cgpa = cgpa;

    newStudent->next = NULL;

    return newStudent;
}

void traverse(struct Student *head){
    if(head==NULL){
        printf("No node\n");
        return;
    }

    struct Student *temp = head;

    int count = 0;
    while(temp!=NULL){
        printf("ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("CGPA: %.2f\n", temp->cgpa);
        printf("-----------------\n");

        temp = temp->next;
        count++;
    }

    printf("Total Student: %d\n", count);
}

void insertAtLast(struct Student *(*head), int id, char name[], float cgpa){
    struct Student *newStudent = createNode(id, name, cgpa);

    // student list is empty
    if(*head==NULL){
        *head = newStudent;
        return;
    }

    struct Student *temp = *head; // null

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newStudent;

}

void insertAtFirst(struct Student **head, int id, char name[], float cgpa){
    struct Student *newStudent = createNode(id, name, cgpa);

    newStudent->next = *head;
    *head = newStudent;
}

void deleteFirst(struct Student **head){
    if(*head==NULL){
        printf("the list is empty\n");
        return;
    }

    if((*head)->next==NULL){
        *head = NULL;
        return;
    }

    *head = (*head)->next;
}

void deleteLast(struct Student **head){
    if(*head==NULL){
        printf("the list is empty\n");
        return;
    }

    if((*head)->next==NULL){
        *head = NULL;
        return;
    }

    struct Student *temp = *head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }

    temp->next = NULL;
}

void deleteAtPos(struct Student **head, int pos){
    if(*head==NULL){
        printf("the list is empty\n");
        return;
    }

    if(pos==1){
        deleteFirst(head);
        return;
    }

    struct Student *temp = *head;
    // taget temp = 2
    // temp = 2, i = 2
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    // temp = 2, temp->next = 3
    struct Student *deleteNode = temp->next;

    temp->next = deleteNode->next;
}

void updateCGPA(struct Student *head, char name[], float newCG){
    struct Student *temp = head;

    while(temp!=NULL){
        if(strcmp(temp->name, name)==0){
            temp->cgpa = newCG;
            printf("cgpa updated\n");
            return;
        }
        temp = temp->next;
    }

    printf("student not found\n");
}

void sortByCGPA(struct Student *head){
    if(head==NULL){
        printf("the list is empty\n");
        return;
    }

    struct Student *i, *j;

    for(i = head; i!=NULL; i=i->next){
        for(j=i->next; j!=NULL; j=j->next){
            if(i->cgpa>j->cgpa){
                // id
                int tempId = i->id;
                i->id = j->id;
                j->id = tempId;

                // name
                char tempName[100];
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                // cgpa
                float tempcg = i->cgpa;
                i->cgpa = j->cgpa;
                j->cgpa = tempcg;
            }
        }
    }
}

int main()
{
    struct Student *head = NULL;

    insertAtLast(&head, 1, "A", 4.88);
    insertAtLast(&head, 2, "B", 3.94);
    insertAtLast(&head, 3, "Kayum", 4.00);
    insertAtLast(&head, 4, "Tanmoy", 4.50);
    // deleteLast(&head);
    // deleteFirst(&head);
    // deleteAtPos(&head, 3);

    // updateCGPA(head, "D", 3.44);


    sortByCGPA(head);
    traverse(head);


}
