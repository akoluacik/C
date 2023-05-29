#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stackNode {
    char data;
    struct stackNode* next;
};

/* protototypes */
void convertToPostfix(char [], char []); // convert the infix exp. to postfix
int isOperator(char); // determine if parameter is operator
int precedence(char, char); // determine if the first param. is less than, equal or greater than the second. returns 1, 0 or -1.
void push(struct stackNode**, char); // push a value to the stack.
char pop(struct stackNode**); // pop a value off the stack.
char stackTop(struct stackNode**); // return the top value of the stuch without popping the stack.
int isEmpty(struct stackNode*);
void print_stack(struct stackNode*);
/*
Create a stack in main.
1.Push a left parenthesis onto the stack.
2.Append a right parenthesis to the infix.
3.While stack is not empty
    -Copy the current char of infix to the postfix if curr. char is digit.
    -Push the curr. char onto stack if current of infix is left parenthesis.
    -if current char of infix is an operator
        -(if any) Pop operators (if there are any) at the top of the stack while they have equal or higher precedence
        than the current operator, and insert the popped operators in postfix .
        -Push the current character in infix onto the stack.
    -If the current character in infix is a right parenthesis
        -Pop operators from the top of the stack and insert them in postfix until a left parenthesis is at the top of the stack.
        -Pop (and discard) the left parenthesis from the stack.
*/
int main(){
    char infix[15], postfix[15]={'\0'};
    scanf("%s", infix);
    convertToPostfix(infix, postfix);
    printf("postfix:%s\n", postfix);
    return 0;
}

void convertToPostfix(char infix[], char postfix[]){
    int infix_idx = 0, postfix_idx = 0,i=0;
    struct stackNode* stack = NULL;
    push(&stack, '(');
    strcat(infix, ")");
    while(stack){
        if(isdigit(infix[infix_idx])){
            postfix[postfix_idx++] = infix[infix_idx++];
        }
        else if(infix[infix_idx] == '(') {
            push(&stack, '(');
            ++infix_idx;
        }
        else if(isOperator(infix[infix_idx])){
            while(isOperator(stack->data)){
                if(precedence(stack->data, infix[infix_idx]) == 1){
                    postfix[postfix_idx++] = pop(&stack);
                }
                else{
                    break;
                }
            }
            push(&stack, infix[infix_idx++]);            
        }
        else if(infix[infix_idx] == ')'){
            while(stack->data != '(' && stack != NULL){
                //printf("\t%s:\n", "while in fourth elif");
                if(isOperator(stack->data)){
                    postfix[postfix_idx++] = pop(&stack);
                } else{
                    break;
                }
            }
            pop(&stack);
            ++infix_idx;
        } else {
            break;
        }
    }
}

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int precedence(char op1, char op2){
    char ops[] = {'*','/','+','-','%','^'};
    size_t i, idx1, idx2;
    for(i = 0; i < 7; ++i){
        if(op1 == ops[i]) idx1 = i;
        if(op2 == ops[i]) idx2 = i;
    }
    return (idx1 < idx2)?1:((idx1 == idx2)?0:-1);
}

void push(struct stackNode** stack, char val){
    struct stackNode* newStack = (struct stackNode*)malloc(sizeof(struct stackNode));
    if(newStack){
        newStack->data = val;
        newStack->next = *stack;
        *stack = newStack;
    } else {
        printf("%s\n","[ERROR] Not enoough memory space!");
    }
}

char pop(struct stackNode** stack){
    char val = (*stack)->data;
    (*stack) = (*stack)->next;
    return val;
}