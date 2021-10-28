#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treeNode{
    char data[100];
    struct treeNode *left;
    struct treeNode *right;
};

/* prototypes */
void insertNode(struct treeNode**, char []);
void inOrder(struct treeNode*);
void preOrder(struct treeNode*);
void postOrder(struct treeNode*);

void driver(struct treeNode*);

int main(){
    struct treeNode* root = NULL;
    driver(root);
    return 0;
}

void driver(struct treeNode* tree){
    char sentence[100];
    fgets(sentence, 100, stdin);
    sentence[strcspn(sentence, "\n")] = 0;
    char *token = strtok(sentence, " ");
    while(token){
        insertNode(&tree, token);
        token = strtok(NULL, " ");
    }
    puts("Post Order:");
    postOrder(tree);
    puts(" ");

    puts("Pre Order:");
    preOrder(tree);
    puts(" ");

    puts("In Order:");
    inOrder(tree);
    puts(" ");
}

void insertNode(struct treeNode** tree, char word[]){
    if(*tree == NULL){
        *tree = (struct treeNode*)malloc(sizeof(struct treeNode));
        if(*tree){
            strcpy((*tree)->data, word);
            (*tree)->left = NULL;
            (*tree)->right = NULL;
        } else {
            printf("%s not inserted. No memory available.\n", word);
        }

    } else {
        if(strcmp((*tree)->data, word) > 0){
            insertNode(&((*tree)->left), word);
        } else if (strcmp((*tree)->data, word) < 0){
            insertNode(&((*tree)->right), word);
        } else {
            printf("%s", "dup");
        }
    }
}

void inOrder(struct treeNode* tree){
    if(tree){
        inOrder(tree->left);
        printf("%s ", tree->data);
        inOrder(tree->right);
    }
}

void preOrder(struct treeNode* tree){
    if(tree){
        printf("%s ", tree->data);
        inOrder(tree->left);
        inOrder(tree->right);
    }
}

void postOrder(struct treeNode* tree){
    if(tree){
        inOrder(tree->left);
        inOrder(tree->right);
        printf("%s ", tree->data); 
    }
}
