#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct treeNode{
    struct treeNode* left;
    int data;
    struct treeNode* right;
};

/* prototypes */
void insert(struct treeNode**, int);
struct treeNode** binaryTreeSearch(struct treeNode**, int);
void inOrder(struct treeNode*);

int main(){
    size_t i;
    struct treeNode* root = NULL, **found = NULL; // 'found' for the address of the node to be found.
    int number;
    srand(time(NULL));
    for(i = 0; i < 8; ++i){
        insert(&root, rand()%25);
    }
    inOrder(root);
    printf("Enter the number to be searched: "); scanf("%d", &number);
    found = binaryTreeSearch(&root, number);
    //printf("found -> data: %d", found->data);
    if(found){
        printf("%s%p ","the address of the value is: ", found);
        //printf("%s%d\n", "The value is: ", (*found)->data);
    } else {
        printf("%s\n", "The address is empty!");
    }
    return 0;
}

void insert(struct treeNode** root, int value){
    if(!(*root)){
        *root = (struct treeNode*)malloc(sizeof(struct treeNode));
        if(*root){
            (*root) -> data  = value;
            (*root) -> right = NULL;
            (*root) -> left = NULL;
        } else {
            printf("%s\n", "[ERROR] Not enough memory space for allocation!");
        }
    } else {
        if(value > (*root) -> data){
            insert(&((*root)->right), value);
        } else if(value < (*root) -> data) {
            insert(&((*root)->left), value);
        }
    }
}

struct treeNode** binaryTreeSearch(struct treeNode** root, int val){
    if(!(*root)){
        return NULL;
    } else {
        
        if((*root)->data == val){
            return root;
        }
        
        if ((*root)->data > val)
        {
            binaryTreeSearch(&((*root)->left), val);
        }
        else if ((*root)->data < val)
        {
            binaryTreeSearch(&((*root)->right), val);
        }
        
    }
}

void inOrder(struct treeNode* tree){
    if(tree != NULL){
        inOrder(tree->left);
        printf(" %d--> ", tree->data);
        inOrder(tree->right);
    }
}