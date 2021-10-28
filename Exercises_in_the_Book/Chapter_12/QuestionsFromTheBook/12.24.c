#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode{
    int data;
    struct treeNode *left, *right;
};

/*
While the pointer to the current node is NOT NULL
    Recursively call the outputTree wit the current node's right subtree and totalspace + 5
    Use a for statemtn to count from 1 to totalSpace and output spaces.
    Output the value in the current node.
    Recursively call outputTree with the current node's left subtree and totalSpaces + 5.
*/



/* prototypes */
void insert(struct treeNode**, int);
void outputTree(struct treeNode* , int);
void inOrder(struct treeNode*);
int main(){
    struct treeNode* root = NULL;
    size_t i;
    int totalSpace = 0;
    srand(time(NULL));
    /*insert(&root, 49);
    insert(&root, 28);
    insert(&root, 83);
    insert(&root, 97);
    insert(&root, 71);
    insert(&root, 40);
    insert(&root, 18);
    insert(&root, 99);
    insert(&root, 92);
    insert(&root, 72);
    insert(&root, 69);
    insert(&root, 44);
    insert(&root, 32);
    insert(&root, 19);
    insert(&root, 11);*/
    for(i = 0; i < 15; ++i) {
        insert(&root, 1 + rand()%25);
    }
    outputTree(root, totalSpace);
    //inOrder(root);
}

void insert(struct treeNode** root, int value){
    if(*root == NULL){
        *root = (struct treeNode*)malloc(sizeof(struct treeNode));
        if(root){
            (*root)->data = value;
            (*root)->left = NULL;
            (*root)->right = NULL;
        } else {
            printf("%s\n", "Not enough memory space for allocation!");
        }
    } else {
        if((*root)->data > value){
            insert(&((*root)->left), value);
        }
        if((*root)->data < value){
            insert(&((*root)->right), value);
        }
    }
}

void outputTree(struct treeNode* root, int totalSpace){
    int i;
   if(!root) return;
    outputTree(root->right, totalSpace + 5);
    for(i = 1; i < totalSpace; ++i)
        printf("%c", ' ');
    printf("%d\n", root->data);
    outputTree(root->left, totalSpace + 5);
    
}

void inOrder(struct treeNode* treePtr){
    if(treePtr != NULL){
        inOrder(treePtr->left);
        printf("%d ", treePtr->data);
        inOrder(treePtr->right);
    }
}