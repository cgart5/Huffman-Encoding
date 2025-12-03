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

Boolean freeTree(Node *root){
    if (root == NULL) return TRUE;

    freeTree(root->left);
    freeTree(root->right);
    freeNode(root);
    return TRUE;
}

void printCodes(Node *root, char symbols[][BUF_SIZE]){
    char *code = (char*)malloc(BUF_SIZE * sizeof(char));
    if (code == NULL) return;
    printCodesHelper(root, code, 0, symbols);    
    free(code);
    return;
}

void printCodesHelper(Node *root, char *code, int depth, char symbols[][BUF_SIZE]){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        for (int i = 0; i < BUF_SIZE; i++){
            if (strcmp(root->symbol, symbols[i]) == 0){
                printf("Symbol: %s, Freq: %d, Code: %s\n", root->symbol, root->freq, code);
                return;
            }
        }
        return;
    }

    code[depth] = '0';
    printCodesHelper(root->left, code, depth + 1, symbols);

    code[depth] = '1';
    printCodesHelper(root->right, code, depth + 1, symbols);

    return;
}

void printTree(Node *root){
    if (root == NULL) return;

    printf("Node-Symbol: %s, Freq: %d\n", root->symbol, root->freq);
    printTree(root->left);
    printTree(root->right);
    return;
}

void printPrettyTreeHelper(Node *root, char *path, Boolean isLeft) {
    if (root == NULL) return;
    
    printf("%s", path);
    if (isLeft) printf("|---");
    else printf("|___");
    
    printf("[%s : %d]\n", root->symbol, root->freq);

    char newPath[BUF_SIZE * 2];
    strcpy(newPath, path);
    if (isLeft)strcat(newPath, "|   ");
    else strcat(newPath, "     ");
    
    if (root->left != NULL || root->right != NULL) {
        if (root->right != NULL) {
            printPrettyTreeHelper(root->right, newPath, root->left != NULL);
        }
        if (root->left != NULL) {
            printPrettyTreeHelper(root->left, newPath, FALSE);
        }
    }

    return;
}

void printPrettyTree(Node *root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }
    
    printf("\nHuffman Tree:\n");  
    printf("[%s : %d]\n", root->symbol, root->freq);
    
    char symbol[BUF_SIZE] = "";
    if (root->right != NULL) {
        printPrettyTreeHelper(root->right, symbol, root->left != NULL);
    }
    if (root->left != NULL) {
        printPrettyTreeHelper(root->left, symbol, FALSE);
    }

    return;
}