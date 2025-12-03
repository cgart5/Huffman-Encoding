// node.c
// // Implementation for Node datatype

#include "node.h"
#include <string.h>
#include <stdlib.h>

Boolean makeNode(Symbol symbol, Freq freq, Node **node) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return FALSE;

    strcpy(newNode->symbol, symbol);
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    *node = newNode;
    return TRUE;
}