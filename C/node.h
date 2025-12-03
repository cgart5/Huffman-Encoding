// node.h
// Header file for node datatype

#include "boolean.h"

#ifndef NODE_H
#define NODE_H

#define BUF_SIZE 256

typedef int Freq;
typedef char Symbol[BUF_SIZE];

typedef struct Node {
    Freq freq;
    Symbol symbol;
    struct Node *left;
    struct Node *right;    
} Node;

// makeNode
// creates a new node with given symbol and frequency
Boolean makeNode(Symbol symbol, Freq freq, Node **node);

// freeNode
// frees the memory allocated for a node
Boolean freeNode(Node *node);

#endif
