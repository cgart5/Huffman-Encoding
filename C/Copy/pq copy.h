// pq.h
// Priority Queue Header file

#include "node.h"
#include "boolean.h"

#ifndef PQ_H
#define PQ_H

typedef struct PQ {
    Node *head;
    struct PQ *rest;
} PQ;

// makePqFromFile
// reads in the text file and builds the priority queue
Boolean makePqFromFile(int tokenCount, char **fileName, PQ **pq);

// EXTRACT_MIN
// returns the node in the beggining of the priority queue and pops the element off
Node* EXTRACT_MIN(PQ **pq);

// pop
// removes the first element from the priority queue
Boolean pop(PQ **pq);

// push
// adds a new node to the priority queue in the correct position based on frequency
Boolean push(PQ **pq, Node *node);

// printDEBUG
// prints the contents of the priority queue for debugging purposes
void printDEBUG(const PQ *pq);

#endif




