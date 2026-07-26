#include <stdio.h>
#define size 100

// global variable: 
// local variable: 

int insertEnd(int end, int value, int arr[]){
    arr[end] = value;
    end = end + 1;
    // printf("end in insertEnd: %d\n", end);
    
    return end;
}

void rightShift(int end, int pos, int arr[]){
    for (int i=end-1; i>=pos; i--){
        arr[i+1] = arr[i];
    }
}

void leftShift(int end, int pos, int arr[]){
    for(int i=pos; i<end; i++){
        arr[i] = arr[i+1];
    }
}

int insertBegin(int end, int value, int arr[]){
    // end = end + 1; // end = 8
    rightShift(end, 0, arr);
    arr[0] = value;
    end = end + 1;
    
    return end;
}



int insertAny(int end, int value, int pos, int arr[]){
    rightShift(end, pos, arr);
    arr[pos] = value;
    end = end+1;
    
    return end;
}

int deleteEnd(int end){
    end = end - 1;
    
    return end;
}

int deleteBegin(int end, int arr[]){
    leftShift(end, 0, arr);
    end = end-1;
    
    return end;
}

int deleteAny(int end, int pos, int arr[]){
    leftShift(end, pos, arr);
    
    end = end - 1;
    return end;
    
}

void traverse(int arr[], int start, int end){
    for(int i=start; i<end; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // const int size = 10;
    int arr[size] = {0, 1, 2, 3, 4};
    
    int start = 0, end = 5; // end = last_index + 1
    
    // printf("end before: %d\n", end);
    // end = insertEnd(end, 5, arr);
    
    // traverse(arr, start, end);
    
    // end = deleteEnd(end);
    // printf("end after: %d\n", end);
    // printf("verify insertion: %d\n", arr[5]);
    
    
    
    // traverse(arr, start, end);
    // end = insertEnd(end, 10, arr);
    // end = insertEnd(end, 20, arr);
    // traverse(arr, start, end);
    // end = insertBegin(end, 15, arr);
    // traverse(arr, start, end);
    // end = insertBegin(end, 16, arr);
    // traverse(arr, start, end);
    // end = deleteBegin(end, arr);
    // traverse(arr, start, end);
    end = insertAny(end, 7, 2, arr);
    traverse(arr, start, end);
    end = deleteAny(end, 2, arr);
    traverse(arr, start, end);
    
    return 0;
}

/**
 * -----------------------
 * 
 * I -> 0 1  2  3  4  5
 * A -> 2 5 10 15 20 25
 * A -> 2 5 15 20 25
 * 
 * 4 -> 5
 * 2 -> 3
 * i -> i + 1
 * -----------------------
 */