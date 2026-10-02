#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

bool isFull(){
    if(top >= SIZE) return true;
    return false;
}

bool isEmpty(){
    if(top < 0) return true;
    return false;
}

int getTop(){
    return stack[top];
}

void push(int val){
    if(isFull()) {
        printf("Overflow!\n");
        return;
    }

    stack[++top] = val;
}

void pop(){
    if(isEmpty()) {
        printf("Underflow!\n");
        return;
    }
    top -= 1;
}

void traverse(){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(void){

    for(int i = 0; i < 8; i++){
        push(i);
        printf("%d\n", getTop());
    }
    traverse();

    for(int i = 0; i < 3; i++){
        pop();
        traverse();
    }

    return 0;
}
