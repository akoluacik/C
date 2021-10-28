#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treeNode{
    char data[5];
    struct treeNode *left;
    struct treeNode *right;
};

int main(){

    struct treeNode* tree = malloc(sizeof(struct treeNode));
    memcpy(tree->data, "test", 4);
    printf("%s", tree->data);
    /*tree -> data = 'c';
    tree->left = NULL;
    tree->right = NULL;
    printf("%c", tree->data);*/
    return 0;
}