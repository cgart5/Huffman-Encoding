// huffman.h
// Huffman Coding Header file

#include "node.h"
#include "pq.h"
#include "btree.h"
#include "boolean.h"
#include <stdio.h>

// readFile
// reads in the text file and builds the priority queue
Boolean readFile(int argc, char **argv, PQ **pq);

// makeNode
// creates a new node with given symbol and frequency
Boolean makeNode(Symbol symbol, Freq freq,  Node **node);
