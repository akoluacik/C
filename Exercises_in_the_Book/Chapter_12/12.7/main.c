#include <stdio.h>
#include <stdlib.h>


struct listNode
{
    char data;
    struct listNode* next;
};

/* prototypes */
void insert(struct listNode**, char);
void concatanate(struct listNode**, struct listNode**);
struct listNode* sort(struct listNode*);
void swap(char*, char*);
void driver();
void print_list(struct listNode *list);

int main(){
    struct listNode *list1 = NULL, *list2 = NULL;
    int i;
    char c;
    for(i=0;i<5;++i){
        printf("? ");scanf("\n%c", &c);
        insert(&list1, c);
    }
    print_list(list1);
    list1 = sort(list1);
    print_list(list1);
}

void insert(struct listNode** list, char value){
    struct listNode* newNode = malloc(sizeof(struct listNode));
    if(newNode){
        
        newNode -> data = value;
        newNode -> next = NULL;

        struct listNode* current = *list;
        struct listNode* previous = NULL;

        while (current){
            previous = current;
            current = current -> next;
        }
        
        if(!previous){
            newNode -> next = *list;
            *list = newNode;
        } else {
            previous -> next = newNode;
            newNode -> next = current;
        }
    } else {
        printf("%c could not be inserted.\n", value);
    }
}

void concatanate(struct listNode** list1, struct listNode** list2){
    if(*list1 && *list2){
        if((*list1)->next == NULL)
            (*list1) -> next = *list2;
        else
            concatanate(&((*list1)->next), list2);
    } else {
        printf("Either list1 or list2 is empty.\n");
    }
}

struct listNode* sort(struct listNode* merged){
    struct listNode* result = NULL, *iter = merged;
    char temp;
    for(;iter->next;iter = iter->next){
        for(result = iter->next;result;result = result->next){
            if(iter->data > result->data){
                //printf("%c -> %c\t", iter->data, result->data);
                /*temp = result->data;
                result->data = iter->data;
                iter->data = temp;*/
                swap(&iter->data, &result->data);
                //printf("%c -> %c\n", iter->data, result->data);
            }
        }
        puts("");
    }
    return merged;
}

void print_list(struct listNode *list){
    if(!list)
        printf("The list is empty.\n");
    else{
        while(list){
            printf("%c --> ", list -> data);
            list = list -> next;
        }
        printf("%s\n", "NULL");
    }
}

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}