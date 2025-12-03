// Chase Gartner
// huffman.c
// Implementation for Huffman Coding

#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    PQ *pq = NULL;
    if (!makePqFromFile(argc, argv,  &pq)){
        fprintf(stderr, "Error reading file\n");
        return 1;
    }
    
    Node *left, *right, *root;
    if(!(left = EXTRACT_MIN(&pq))){
        printf("Please Check Input File\n");
        return 1;
    }
    while (pq != NULL){
        right = EXTRACT_MIN(&pq);
        
        if (!makeTree(left, right, &root)){
            fprintf(stderr, "Error creating tree\n");
            return 1;
        }
        
        if (!push(&pq, root)){
            fprintf(stderr, "Error pushing to priority queue\n");
            return 1;
        }
        left = EXTRACT_MIN(&pq);
    }
    printTree(left);
    printCodes(left, (char*)malloc(BUF_SIZE * sizeof(char)), 0);
    return 0;
}
