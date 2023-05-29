#include <stdio.h>
#include <stdlib.h>

struct stackNode{
    char c;
    struct stackNode* next;
};

/* prototypes */
void push(struct stackNode** stack, char value);
char pop(struct stackNode** stack);

int main(){
    struct stackNode* stack = NULL;
    char word[10];
    printf("Enter a 9-letter word: ");scanf("%9s", word);
    unsigned int i;
    for(i = 0; i < 10; ++i){
        push(&stack, word[i]);
    }
    for(i = 0; i <10; ++i){
        if(stack)
            printf("%c", pop(&stack));
    }
}

void push(struct stackNode** stack, char value){
    struct stackNode* newStack = (struct stackNode*)malloc(sizeof(struct stackNode));
    if(newStack){
        newStack->c = value;
        newStack->next = *stack;
        *stack = newStack;
    }
}

char pop(struct stackNode** stack){
    //struct stackNode* temp = *stack;
    char val = (*stack)->c;
    (*stack) = (*stack)->next;
    return val;
}