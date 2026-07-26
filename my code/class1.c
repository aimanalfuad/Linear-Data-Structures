#include "Universe.h"

int main(void){
    int arr[SIZE];
    int low = 0, up = 19;

    initialize(arr, low, up);
    print_arr(arr, low, up);

    insert_end(arr, &up, -25);
    print_arr(arr, low, up);

    insert_begin(arr, &low, &up, -21);
    print_arr(arr, low, up);

    return 0;
}
