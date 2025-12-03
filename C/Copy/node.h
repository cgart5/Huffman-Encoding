// node.h
// Header file for node datatype

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

#endif
