// Chase Gartner
// Huffman.java
// Huffman Class for Huffman encoding
// Symbolic Constants in Java Cite(Sad since there are no Pre-processor Directives)
// https://www.geeksforgeeks.org/java/java-symbolic-constants/
// EXTRA CREDIT: Binary Codes for Huffman Tree & Documentation was made for each class under the Documentation Folder

import java.io.*;

public class Huffman{
    public static final int CODES_MAX = 256;

    public static void main(String argv[]){
        try{
            PriorityQueue pq = new PriorityQueue();
            String[] codes = new String[CODES_MAX];

            if(argv.length == 0){
                System.out.println("Please give a file name, Usage: java Huffman <filename>");
                System.exit(1);
            }
            
            Boolean printCodes = pq.makePQFromFile(argv[0], codes);

            Btree combo = new Btree();
            Node left = pq.EXTRACT_MIN();
            while(pq.getHead() != null){
                Node right = pq.EXTRACT_MIN();

                combo.makeTree(left, right);
                pq.push(combo.getRoot());
                
                left = pq.EXTRACT_MIN();
            }

            combo.setRoot(left);
            combo.printPrettyTree();
            
            // EXTRA CREDIT
            if (printCodes){
                combo.printCodes(codes);
            }
            return;
        }
        catch(Exception e){
            e.printStackTrace(); 
            System.exit(1);
        }
    }
}