#include <stdio.h>
#include <stdlib.h>

struct listNode{
    char data;
    struct listNode* next;
};

/* prototypes */
void append(struct listNode**, char value);
struct listNode* reverse(struct listNode*);
void print_list(struct listNode*);

int main(){
    struct listNode* head = NULL;
    int i;
    char item;
    for(i=0;i<10;++i){
        printf("Enter the char: ");scanf("\n%c", &item);
        append(&head, item);
    }
    print_list(head);
    struct listNode* reversed = reverse(head);
    print_list(reversed);
}

void append(struct listNode** list, char value){
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;
        if(!(*list)){
            *list = newNode;
            return;
        }
        struct listNode* current = *list;
        while(current -> next != NULL)
            current = current -> next;
        current -> next = newNode;
                
    } else{
        printf("Not enough memory space to append %c", value);
    }
}

struct listNode* reverse(struct listNode* list){
    struct listNode* reverse = NULL;
    if(!reverse){
        reverse = (struct listNode*)malloc(sizeof(struct listNode));
        reverse->data = list->data;
        reverse->next = NULL;
    }

    size_t i;
    for(i=1;i<10;++i){
        struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
        list = list->next;
        newNode->data = list->data;
        newNode->next=reverse;
        reverse = newNode;
    }
    return reverse;
}

void print_list(struct listNode* list){
    if(!list){
        printf("%s\n", "List is empty.");
    } else {
        for(;list;list = list->next)
            printf("%c --> ", list->data);
        puts("NULL");
    }
}