// Chase Gartner
// huffman.c
// Implementation for Huffman Coding

#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc < 2) {
        printf("Please provide an input file\n");
        return 1;
    }

    PQ *pq = NULL;
    char symbols[BUF_SIZE][BUF_SIZE];
    if (!makePqFromFile(argc, argv,  &pq, symbols)){
        fprintf(stderr, "Error reading file\n");
        return 1;
    }
    
    Node *left, *right, *combo;
    if((pq == NULL) || !(left = EXTRACT_MIN(&pq))){
        printf("Please Check Input File\n");
        return 1;
    }
    while (pq != NULL){
        right = EXTRACT_MIN(&pq);
        
        if (!makeTree(left, right, &combo)){
            fprintf(stderr, "Error creating tree\n");
            return 1;
        }
        
        if (!push(&pq, combo)){
            fprintf(stderr, "Error pushing to priority queue\n");
            return 1;
        }
        left = EXTRACT_MIN(&pq);
    }

    printPrettyTree(left);
    if (strlen(symbols[0])){
        printCodes(left, symbols);
    }
    freeTree(left);
    free(pq);
    return 0;
}
