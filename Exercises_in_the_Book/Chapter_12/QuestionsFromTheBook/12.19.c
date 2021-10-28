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
void inOrder(struct treeNode*);
int depth(struct treeNode*);

int main(){
    size_t i;
    struct treeNode* root = NULL;
    srand(time(NULL));
    for(i = 0; i < 8; ++i){
        insert(&root, rand()%25);
    }
    inOrder(root);
    printf("%s%d\n", "The depth of the tree is: ", depth(root));
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

void inOrder(struct treeNode* tree){
    if(tree != NULL){
        inOrder(tree->left);
        printf(" %d--> ", tree->data);
        inOrder(tree->right);
    }
}

int depth(struct treeNode* root){
    if(!root)
        return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}