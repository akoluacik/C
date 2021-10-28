#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    char data;
    struct listNode *next;
};

/* prototypes */
void insert(struct listNode**, char);
void concatenate(struct listNode**, struct listNode**);
void print_list(struct listNode*);

int main(){
    struct listNode *list1 = NULL, *list2 = NULL;
    char value;
    size_t i;
    for(i = 0; i < 3; ++i){
        printf("Enter the char to be inserted into list1: ");scanf("\n%c",&value);
        insert(&list1, value);
        printf("Enter the char to be inserted into list2: ");scanf("\n%c",&value);
        insert(&list2, value);
    }
    print_list(list1);
    print_list(list2);

    concatenate(&list1, &list2);
    
}

void insert(struct listNode **list, char value){
    struct listNode *newNode = malloc(sizeof(struct listNode));
    
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;
    } else {
        printf("%c cannot be inserted.\n", value);
        return;
    }

    if(*list == NULL) {
        newNode -> next = *list;
        *list = newNode;
    } else {
        struct listNode *current = *list;
        while(current->next)
            current = current -> next;
        current -> next = newNode;
    }

}

void concatenate(struct listNode** list1, struct listNode** list2){
    if(list1 && list2){
        if((*list1) ->next == NULL)
            (*list1)->next = *list2;
        else
            concatenate(&((*list1)->next), list2);
    } else {
        printf("Either list1 or list2 is empty.\n");
    }
}

void print_list(struct listNode *list){
    if(list){
        printf("The list is:\n");
        while(list){
            printf("%c --> ", list->data);
            list = list->next;
        }
        puts("NULL");
    }
}
