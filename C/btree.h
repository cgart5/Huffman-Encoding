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
void printTree(Node *root);

// freeTree
// frees the memory allocated for the tree
Boolean freeTree(Node *root);

// printCodes
// passes the Node into the internal function
void printCodes(Node *root, char symbols[][BUF_SIZE]);

// printCodesHelper
// prints the Huffman codes for each symbol in the tree
void printCodesHelper(Node *root, char *code, int depth, char symbols[][BUF_SIZE]);

// printPrettyTree
// prints the tree in a pretty format
void printPrettyTree(Node *root);

// printPrettyTreeHelper
// helper function for printPrettyTree
void printPrettyTreeHelper(Node *root, char *path, Boolean isLeft);

#endif
