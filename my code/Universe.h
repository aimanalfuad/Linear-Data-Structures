#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100

void initialize(int a[], int low, int up){
    for(int i = low; i <= up; i++)
        a[i] = rand() % 100 + 1;
}

void insert_end(int a[],int* up, int value){
    if((*up) < SIZE - 1){
        (*up)++;
        a[*up] = value;
    }
    else printf("Out of the bound!\n");
}

void right_shift(int a[], int* low, int* up, int* flag){
    if((*up) < SIZE - 1){
        for(int i = (*up); i >= (*low); i--){
            a[i + 1] = a[i];
        }
        (*up)++;
    }
    else {
        printf("No space available!\n");
        *flag = 1;
    }
}

void insert_begin(int a[], int* low, int* up, int value){
    int flag = 0;
    right_shift(a, low, up, &flag);
    if(!flag) a[0] = value;
}

void print_arr(int a[], int low, int up){
    for(int i = low; i <= up; i++)
        printf("%d ", a[i]);
    printf("\n");
}
