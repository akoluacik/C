#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode{
    struct treeNode* left;
    int data;
    struct treeNode* right;
};

struct queueNode{
    struct treeNode* tree;
    struct queueNode* next;
};


/* prototype */
void insert(struct treeNode**, int); // tree creator
void levelOrder(struct treeNode*);
void inOrder(struct treeNode*);
void enqueue(struct queueNode**, struct queueNode**, struct treeNode*);
struct treeNode* dequeue(struct queueNode**, struct queueNode**);

int main(){
    struct treeNode* root = NULL;
    levelOrder(root);
    puts("NULL");
}

void insert(struct treeNode** root, int val){
    if(!(*root)){ // when root is empty
        *root = (struct treeNode*)malloc(sizeof(struct treeNode));
        if(*root){ // if allocation is achieved
            (*root) -> data = val;
            (*root) -> right = NULL;
            (*root) -> left = NULL;
        } else { // if allocation is not succesfull
            printf("%s\n", "[ERROR] Not enough memory space for allocation!");
        }
    } else { // if root is not empty
        if(val > (*root) -> data)
            insert(&(*root) -> right, val);
        else if(val < (*root) -> data)
            insert(&(*root) -> left, val);
    }
}

void enqueue(struct queueNode** head, struct queueNode** tail, struct treeNode* tree){
    struct queueNode* newNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    if( newNode ){
        newNode -> tree = tree;
        newNode -> next = NULL;
        if(!(*head))
            *head = newNode;
        else
            (*tail) -> next = newNode;
        (*tail) = newNode;
    } else {
        printf("%s\n", "[ERROR] Not enough memory space for allocation!");
    }
}

struct treeNode* dequeue(struct queueNode** head, struct queueNode** tail){
    struct treeNode* val = (*head)->tree;
    struct queueNode* temp = *head;
    *head = (*head) -> next;
    if(!(*head))
        *tail = NULL;
    free(temp);
    return val;
}

void levelOrder(struct treeNode* root){
    struct treeNode* output = NULL;
    struct queueNode* head = NULL, *tail = NULL;
    size_t i;
    srand(time(NULL));
    for(i = 0; i < 9; ++i){
        insert(&root, 1 + rand()%16); // randomly created binary tree
    }

    enqueue(&head, &tail, root); // enqueueing the head
    while(head){
        output = dequeue(&head, &tail);
        printf("%d-->", output->data);
        if(output->left){
            enqueue(&head, &tail, output->left); // enqueuing the left child
        }
        if(output->right){
            enqueue(&head, &tail, output->right); // enqueuing the right child
        }
    }
}
