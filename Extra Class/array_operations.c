// Operations in arrays
#include <stdio.h>

#define SIZE 100

// Traverse
void traverse(int lb, int ub, int a[]){
    for(int i = lb; i <= ub; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Shift
void leftShift(int lb, int ub, int a[]){
    for(int i = lb; i <= ub - 1; i++){
        a[i] = a[i + 1];
    }
}

void rightShift(int lb, int ub, int a[]){
    for(int i = ub; i >= lb; i--){
        a[i + 1] = a[i];
    }
}

// Deletion
int deleteEnd(int ub){
   if(ub >= 0) return --ub; // post decrement won't work
}

int deleteBegin(int lb, int ub, int a[]){
    leftShift(lb, ub, a);
    return --ub;
}

int deleteAny(int pos, int ub, int a[]){
    leftShift(pos, ub, a);
    return --ub;
}

// Insertion
int insertBegin(int val, int lb, int ub, int a[]){
    rightShift(lb, ub, a);
    a[lb] = val;
    return ++ub;
}

int insertEnd(int val, int ub, int a[]){
    a[ub + 1] = val;
    return ++ub;
}

int insertAny(int val, int pos, int ub, int a[]){
    rightShift(pos, ub, a);
    a[pos] = val;
    return ++ub;
}

// Update
void Update(int val, int pos, int a[]){
    a[pos] = val;
}

// Linear Search
int linearSearch(int val, int lb, int ub, int a[]){
    for(int i = lb; i <= ub; i++){
        if(a[i] == val) return i;
    }
    return -1;
}

// Merge
int Merge(int ub_1, int ub_2, int A[], int B[]){
    int j = 0;
    for(int i = ub_1 + 1; i <= ub_1 + ub_2 + 1; i++){
        A[i] = B[j];
        j++;
    }
    return ub_1 + ub_2 + 1;
}

// Delete by value
int deleteValue(int val, int lb, int ub, int a[]){
    for(int i = lb; i <= ub; i++){
        if(a[i] == val){
            leftShift(i, ub, a);
            return --ub;
        }
    }
    return ub;
}

int main(void){
    int a[SIZE] = {0, 1, 8, 8, 4, 6, 4, 9, 8, 1, 4};
    int lb = 0, ub = 10;

    ub = deleteEnd(ub);
    traverse(lb, ub, a);

    ub = deleteBegin(lb, ub, a);
    traverse(lb, ub, a);

    ub = deleteAny(6, ub, a);
    traverse(lb, ub, a);

    ub = insertBegin(0, lb, ub, a);
    traverse(lb, ub, a);

    ub = insertAny(9, 7, ub, a);
    traverse(lb, ub, a);

    ub = insertEnd(4, ub, a);
    traverse(lb, ub, a);

    Update(1884649814, 0, a);
    traverse(lb, ub, a);

    int index = linearSearch(8, lb, ub, a);
    if(index != -1) printf("Found at index %d\n", index);
    else puts("Not found");

    int b[] = {0, 1, 6, 1, 7, 2, 3, 3, 9, 0, 8};
    int ub_1 = ub;
    int ub_2 = sizeof(b)/sizeof(b[0]) - 1;

    ub = Merge(ub_1, ub_2, a, b);
    traverse(lb, ub, a);

    ub = deleteValue(8, lb, ub, a);
    traverse(lb, ub, a);

    return 0;
}
