# Make File for Huffman Coding Implementation

huffman: pq.o huffman.o btree.o node.o
	gcc -o huffman pq.o huffman.o btree.o node.o

pq.o: pq.c pq.h node.h boolean.h
	gcc -c pq.c

huffman.o: huffman.c huffman.h pq.h btree.h node.h boolean.h
	gcc -c huffman.c

btree.o: btree.c btree.h node.h boolean.h
	gcc -c btree.c

node.o: node.c node.h boolean.h
	gcc -c node.c