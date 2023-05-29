#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_arr(int *, size_t); 

int main(){
    srand(time(NULL));
    size_t len = 5 + rand()%10, new_len;
    int i;
    int *arr = (int*)malloc(sizeof(int) * len);

    /* random array generation */
    for(i = 0; i < len; ++i)
            arr[i] = rand() % 20;
    print_arr(arr, len);
    

    arr = (int*)realloc(arr, len/2); // shrinking array
    print_arr(arr, len/2);

}

void print_arr(int *arr, size_t size){
    int i;
    for(i = 0; i < size; ++i)
        printf("%d ", *(arr + i));
    
    puts("\n");
}
