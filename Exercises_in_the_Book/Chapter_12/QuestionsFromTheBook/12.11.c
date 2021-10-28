#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stackNode
{
    char c;
    struct stackNode* next;
};

/* prototypes */
void push(struct stackNode**, char);
char pop(struct stackNode**);
int palindrome_checker(struct stackNode*, char []);
void print_stack(struct stackNode*);

int main(){
    struct stackNode* head = NULL;
    char word[20];
    size_t i;
    printf("Enter a word: ");fgets(word, 20, stdin); // consider input does not contain any number
    word[strcspn(word, "\n")]=0;
    for(i=0;word[i]!='\0';++i){
        if(!isalpha(word[i])) continue; // if word[i] is a punctuation or white space
        push(&head, word[i]);
    }
    
    if(palindrome_checker(head, word)){
        printf("%s\n", "Palindrome!");
    } else {
        printf("%s\n", "Not Palindrome!");
    }
}

void push(struct stackNode** list, char value){
    struct stackNode* newPtr = (struct stackNode*)malloc(sizeof(struct stackNode));
    if(newPtr){
        newPtr->c = value;
        newPtr->next = *list;
        *list = newPtr;
    }
}

char pop(struct stackNode** list){
    char popValue = (*list)->c;
    *list = (*list)->next;
    return popValue;
}

int palindrome_checker(struct stackNode* list, char word[]){
    size_t i;
    for(i = 0; word[i] != '\0'; ++i){
        if(!isalpha(word[i])) continue;
        if(pop(&list) != word[i]) return 0;
    }
    return 1;
}


void print_stack(struct stackNode* stack){
    if(!stack) printf("%s\n","The stack is empty.");
    else {
        while(stack){
            printf("%c-->", stack->c);
            stack = stack -> next;
        }
        puts("NULL");
    }
}