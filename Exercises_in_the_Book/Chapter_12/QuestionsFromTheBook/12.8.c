#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct listNode
{
    int data;
    struct listNode* next;
};

/* prototypes */
void insert(struct listNode**, int);
void print_list(struct listNode*);

int main(){
    struct listNode* head = NULL;
    int value = 0, prev, i=0;;
    srand(time(NULL));
    for(int i = 0; i < 25; ++i)
        insert(&head, rand()%101);
    print_list(head);
    return 0;
}

void insert(struct listNode** list, int value){
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;

        struct listNode* current = *list;
        struct listNode* prev = NULL;

        while(current && current->data < value){
            prev = current;
            current = current -> next;
        }

        if(!prev){
            newNode->next = *list;
            *list = newNode;
        } else {
            newNode->next = current;
            prev->next = newNode;
        }
    } else {
        printf("%d cannot be inserted. Not enough memory space.\n", value);
    }
}

void print_list(struct listNode* list){
    if(!list){
        printf("%s\n","The list is empty.");
    } else {
        printf("%s\n", "The list is:");
        for(;list;list=list->next)
            printf("%d-->", list->data);
    }
    printf("%s\n","NULL");
}