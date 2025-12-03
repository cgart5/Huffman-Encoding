// pq.c
// Implementation for Priority Queue structure

#include "pq.h"
#include <stdlib.h>
#include <stdio.h>

Node* EXTRACT_MIN(PQ *pq){
    Node *result = pq->head;
    if(pop((PQ**)(pq))){
        return result;
    }   
    return NULL;
}

Boolean pop(PQ **pq){
    PQ *victim = *pq;
    *pq = victim->rest;
    victim = 0;
    free(victim);
    return TRUE;
}

Boolean push(PQ **pq, Node *node){
    // Create new PQ node
    PQ *newPQNode = (PQ*)malloc(sizeof(PQ));
    if (newPQNode == NULL) return FALSE;
    
    newPQNode->head = node;
    newPQNode->rest = NULL;
    
    // Empty list or insert at head
    if (*pq == NULL || node->freq <= (*pq)->head->freq){
        newPQNode->rest = *pq;
        *pq = newPQNode;
        return TRUE;
    }
    
    // Find insertion point
    PQ *current = *pq;
    while (current->rest != NULL && current->rest->head->freq <= node->freq){
        current = current->rest;
    }
    
    newPQNode->rest = current->rest;
    current->rest = newPQNode;
    return TRUE;
}

void printDEBUG(const PQ *pq){
    if (pq == 0) return;
    printf("Node Symbol: %s, Freq: %d\n", pq->head->symbol, pq->head->freq);
    printDEBUG(pq->rest);
}