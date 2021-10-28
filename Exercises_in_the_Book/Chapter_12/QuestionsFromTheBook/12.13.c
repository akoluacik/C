#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct stackNode{
    int data;
    struct stackNode* next;
};

/*prototypes */
int evaluatePostfixExpression(char *expr); // it evaluates the expression
int calculate(int op1, int op2, char operator); // Evaluate the expression op1 operator op2 .
void push(struct stackNode**, int);
int pop(struct stackNode**); // pop returns int. For evaluation.
char popp(struct stackNode**); // pop returns char.
int isEmpty(struct stackNode*);
void print_stack(struct stackNode*);
void convertToPostfix(char [], char []); // convert the infix exp. to postfix
int isOperator(char); // determine if parameter is operator
int precedence(char, char); // determine if the first param. is less than, equal or greater than the second. returns 1, 0 or -1.
char stackTop(struct stackNode**); // return the top value of the stuch without popping the stack.
int isEmpty(struct stackNode*);
void print_stack(struct stackNode*);

/*
-Append the NULL char to the end of the postfix.
- While '\0' has not been encountered, read the expr. from left to right.
    - If current char is digit:
        -Push its integer value onto the stack. Since we read a string, use this method: postfix[i] - '0'
        -Otherwise, if the current char is operator
            -Pop the two top elements of the stack into variables x and y.
            -Calculate y operator x.
            -Push the result of the calculation onto the stack.
-When '\0' is encontered, pop the value of the stack. This is the result.
*/

int main(){
    char infix[15], postfix[15]={'\0'};
    scanf("%s", infix);
    convertToPostfix(infix, postfix);
    printf("postfix:%s\n", postfix);
    printf("the result is: %d", evaluatePostfixExpression(postfix));
    return 0;
}

int evaluatePostfixExpression(char *expr){
    struct stackNode* stack = NULL;
    size_t i;
    for(i = 0; expr[i] != '\0'; ++i){
        if(isdigit(expr[i])){
            push(&stack, expr[i] - '0');
        } else if(isOperator(expr[i])){
            int x, y, res;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, calculate(y, x, expr[i]));
        }
    }
    return pop(&stack);
}

int calculate(int op1, int op2, char operator){
    switch (operator)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return op1 % op2;
    case '^':
        return op1 ^ op2;
    }   
}

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int precedence(char op1, char op2){
    char ops[] = {'*','/','+','-','%','^'}; // precedence is getting lower towards right.
    size_t i, idx1, idx2;
    for(i = 0; i < 7; ++i){
        if(op1 == ops[i]) idx1 = i;
        if(op2 == ops[i]) idx2 = i;
    }
    //return (idx1 < idx2)?1:((idx1 == idx2)?0:-1);
    return (idx1 - idx2) * (-1); // since precedence becomes lower towards right, idx1 < idx2, (idx1 - idx2) < 0 and to make it the result positive
    // multiply it by (-1). Same for idx1 > idx2.
}

void push(struct stackNode** stack, int val){
    struct stackNode* newStack = (struct stackNode*)malloc(sizeof(struct stackNode));
    if(newStack){
        newStack->data = val;
        newStack->next = *stack;
        *stack = newStack;
    } else {
        printf("%s\n","[ERROR] Not enoough memory space!");
    }
}

int pop(struct stackNode** stack){
    int val = (*stack)->data;
    (*stack) = (*stack)->next;
    return val;
}

char popp(struct stackNode** stack){
    char val = (*stack)->data;
    (*stack) = (*stack)->next;
    return val;
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
                
                if(precedence(stack->data, infix[infix_idx]) >= 1){
                    postfix[postfix_idx++] = popp(&stack);
                }
                else{
                    break;
                }
                //++i;
            }
            push(&stack, infix[infix_idx]);
            ++infix_idx;
        }
        else if(infix[infix_idx] == ')'){
            while(stack->data != '(' && stack != NULL){
                if(isOperator(stack->data)){
                    postfix[postfix_idx++] = popp(&stack);
                }
            }
            popp(&stack);
            ++infix_idx;
        }
    }
}