// btree.h
// Binary Tree Header file

#include "node.h"
#include "boolean.h"

#ifndef BTREE_H
#define BTREE_H

// makeTree
// creates a new tree node with given left and right children
Boolean makeTree(Node *left, Node *right, Node **result);

// printTree
// prints the contents of the tree
Boolean printTree(Node *root);

// printCodes
// prints the Huffman codes for each symbol in the tree
Boolean printCodes(Node *root, char *code, int depth);

#endif
