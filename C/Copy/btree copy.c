// btree.c
// Implementation for Binary Tree structure

#include "btree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Boolean makeTree(Node *left, Node *right, Node **result){ 
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return FALSE;

    newNode->left = left;
    newNode->right = right;
    newNode->freq = left->freq + right->freq;
    strcpy(newNode->symbol,left->symbol); 
    strcat(newNode->symbol, right->symbol);

    *result = newNode;
    return TRUE;
}

Boolean printCodes(Node *root, char *code, int depth){
    if (root == NULL) return TRUE;

    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("Symbol: %s, Freq: %d, Code: %s\n", root->symbol, root->freq, code);
        return TRUE;
    }

    code[depth] = '0';
    printCodes(root->left, code, depth + 1);

    code[depth] = '1';
    printCodes(root->right, code, depth + 1);

    return TRUE;
}

Boolean printTree(Node *root){
    if (root == NULL) return TRUE;

    printf("Node Symbol: %s, Freq: %d\n", root->symbol, root->freq);
    printTree(root->left);
    printTree
    (root->right);

    return TRUE;
}
