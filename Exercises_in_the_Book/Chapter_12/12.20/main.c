#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode{
    int x;
    struct listNode* next;
};

/* prototypes */
void insert(struct listNode**, int);
void print_list(struct listNode*);

int main(){
    size_t i;
    struct listNode* list = NULL;
    srand(time(NULL));
    for(i = 0; i < 8; ++i){
        insert(&list, 1 + rand()%50);
    }
    print_list(list);
}

void insert(struct listNode** list, int data){
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    if(newNode){
        newNode->x = data;
        newNode->next = NULL;

        struct listNode* prev = NULL, *current = *list;
        while (current)
        {
            prev = current;
            current = current -> next;
        }
        if(!prev){
            newNode -> next = *list;
            *list = newNode;
        } else {
            prev -> next = newNode;
            newNode -> next = current;
        }
    } else {
        printf("%s\n", "[ERROR] Not enough memory space!");
    }
}

void print_list(struct listNode* list){
    if(!list) printf("%s\n", "NULL");
    else {
        printf("%d --> ", list->x);
        print_list(list->next);
    }
}