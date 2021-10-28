#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode{
    int x;
    struct listNode* next;
};

/* prototypes */
void insert(struct listNode**, int);
int* search(struct listNode*, int);
void print_list(struct listNode*);

int main(){
    struct listNode* list = NULL;
    int value, *valuePtr;
    size_t i;
    srand(time(NULL));
    for(i = 0; i< 8; ++i)
        insert(&list, 1 + rand()%45);
    print_list(list);
    printf("Enter the value to be searched: "); scanf("%d", &value);
    valuePtr = search(list, value);
    //printf("The address of the value is: %p", valuePtr);
    if(valuePtr){
        printf("The address of the value is: %p", valuePtr);
    } else {
        printf("The value cannot be found!");
    }
}

void insert(struct listNode** list, int value){
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    if(newNode){
        newNode -> x = value;
        newNode -> next = NULL;

        if(!(*list)){
            (*list) = newNode;
        } else {
            struct listNode* iter = *list;
            while(iter -> next)
                iter = iter -> next;
            iter -> next = newNode;
        }
    }
}

int* search(struct listNode* list, int value){
    if(!list){
        return NULL;
    }
    if(list->x != value){
        search(list->next, value);
    } else {
        return (&(list->x));
    }
}

void print_list(struct listNode* list){
    if(!list) printf("%s\n", "List is empty.");
    else{
        while(list){
            printf("%d --> ", list -> x);
            list = list -> next;
        }
        puts(" NULL");
    }
}