// pq.c
// Implementation for Priority Queue structure

#include "pq.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Boolean makePqFromFile(int tokenCount, char **fileName, PQ **pq, char symbols[][BUF_SIZE]){
    FILE *file = fopen(fileName[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return FALSE;
    }

    Symbol symbolBuffer;
    int freq;
    int result = fscanf(file, "%s : %d", symbolBuffer, &freq);
    while(result == 2){
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (!makeNode(symbolBuffer, freq, &newNode))return FALSE;

        if (!push(pq, newNode)) {
            free(newNode);
            fclose(file);
            return FALSE;
        }

        result = fscanf(file, "%s : %d", symbolBuffer, &freq);
    }

    char line[BUF_SIZE];
    int symbolCount = 0;
    result = fscanf(file, "%s", line);
    while(result == 1){
        strcpy(symbols[symbolCount], "");
        strcat(symbols[symbolCount], line);
        result = fscanf(file, "%s", line);
        symbolCount++;
    }
    
    fclose(file);
    return TRUE;
}

Node* EXTRACT_MIN(PQ **pq){
    Node * result = (*pq)->head;
    if (pop(pq)){
        return result;
    }
    return NULL;
}

Boolean pop(PQ **pq){
    PQ *victim = *pq;
    *pq = victim->rest;
    victim = NULL;
    free(victim);
    return TRUE;
}

Boolean push(PQ **pq, Node *node){
    PQ *newPQNode = (PQ*)malloc(sizeof(PQ));
    if (newPQNode == NULL) return FALSE;
    
    newPQNode->head = node;
    newPQNode->rest = NULL;
    
    if (*pq == NULL || node->freq <= (*pq)->head->freq){
        newPQNode->rest = *pq;
        *pq = newPQNode;
        return TRUE;
    }
    
    PQ *temp = *pq;
    while (temp->rest != NULL && temp->rest->head->freq <= node->freq){
        temp = temp->rest;
    }
    
    newPQNode->rest = temp->rest;
    temp->rest = newPQNode;
    return TRUE;
}

void printDEBUG(const PQ *pq){
    if (pq == NULL) return;
    printf("Node Symbol: %s, Freq: %d\n", pq->head->symbol, pq->head->freq);
    printDEBUG(pq->rest);
}