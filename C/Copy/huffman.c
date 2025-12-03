// Chase Garnter
// huffman.c
// Implementation for Huffman Coding

#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    PQ *pq = NULL;
    if (!readFile(argc, argv,  &pq)){
        fprintf(stderr, "Error reading file\n");
        return 1;
    }
    
    Node *left, *right, *root;
    while (pq->rest != NULL){
        left = EXTRACT_MIN(&pq);
        right = EXTRACT_MIN(&pq);
        
        if (!makeTree(left, right, &root)){
            fprintf(stderr, "Error creating tree\n");
            return 1;
        }
        
        if (!push(&pq, root)){
            fprintf(stderr, "Error pushing to priority queue\n");
            return 1;
        }
    }
    Node *final = EXTRACT_MIN(pq);
    printTree(final);
    printCodes(final, (char*)malloc(BUF_SIZE * sizeof(char)), 0);
    return 0;
}

Boolean readFile(int argc, char **argv, PQ **pq){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return FALSE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return FALSE;
    }

    Symbol symbolBuffer;
    int freq;
    while (fscanf(file, "%s : %d", symbolBuffer, &freq) == 2) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (!makeNode(symbolBuffer, freq, &newNode))return FALSE;

        if (!push(pq, newNode)) {
            free(newNode->symbol);
            free(newNode);
            fclose(file);
            return FALSE;
        }
    }

    fclose(file);
    return TRUE;
}

Boolean makeNode(Symbol symbol, Freq freq, Node **node) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return FALSE;

    int i = 0;
    // Copy symbol into newNode
    while (symbol[i] != '\0' && i < BUF_SIZE - 1) {
        newNode->symbol[i] = symbol[i];
        i++;
    }
    newNode->symbol[i] = '\0';
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    *node = newNode;
    return TRUE;
}