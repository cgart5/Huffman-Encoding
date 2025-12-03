// PriorityQueue.java
// PriorityQueue Class for Huffman

import java.io.*;

public class PriorityQueue{
    private Node head;
    private PriorityQueue rest;
    public static final int WORD_VALUE = -3;
    public static final int NUMBER_VALUE = -2;
    public static final int COLON_VALUE = 58;

    // PriorityQueue
    // constructor
    public PriorityQueue(){
        head = null;
        rest = null;
    }

    // makePQFromFile
    // take in a file, and an empty array of codes for the function to fill in
    // if the file contains a codes section it returns true, if not false
    public Boolean makePQFromFile(String fileString, String[] codes){
        try{
            FileReader file = new FileReader(fileString);
            StreamTokenizer inputStream = new StreamTokenizer(file);
            int tokenType = inputStream.nextToken();
            Boolean codeFlag = false;
            int codeCount = 0;
            int lineCount = 0;
            String code;

            while(tokenType != StreamTokenizer.TT_EOF){
                if (tokenType != WORD_VALUE){
                    System.out.println("File Line " + (lineCount + 1) + ": Incorrect Format, Symbols must be words or letters");
                    System.exit(1);
                }
                
                if(codeFlag){
                    code = inputStream.sval;
                    codes[codeCount] = code;
                    ++codeCount;
                    ++lineCount;
                    tokenType = inputStream.nextToken();
                }
                else{
                    String symbol;
                    symbol = inputStream.sval;
                    if (!symbol.equals("codes")){

                        tokenType = inputStream.nextToken();
                        if (tokenType != COLON_VALUE){
                            System.out.println("File Line " + (lineCount + 1) + ": Incorrect Format\nUsage: <symbol> : <frequency>");
                            System.exit(1);  
                        }

                        tokenType = inputStream.nextToken();
                        if(tokenType != NUMBER_VALUE){
                            System.out.println("File Line " +(lineCount + 1) + ": Frequency values must be Integers");
                            System.exit(1);
                        }
                        int freq = (int) inputStream.nval;
                        if (freq <= 0){
                            System.out.println("File Line " +(lineCount + 1) + ": Frequency values must be greater than 0");
                            System.exit(1);
                        }

                        Node newNode = new Node(symbol, freq, null, null);
                        this.push(newNode);

                        codeCount++;
                        lineCount++;
                    }
                    else{
                        codeFlag = true;
                        codeCount = 0;
                        lineCount++;
                    }
                    tokenType = inputStream.nextToken();
                }
            }

            if (codeCount == 0 && !codeFlag){
                System.out.println("File is empty, please add atleast one symbol frequency pair\nUsage: <symbol> : <frequency>");
                System.exit(1);
            }

            return codeFlag;
        }

        catch(IOException e){
            System.out.println("File not found: " + e.getMessage());
            System.exit(1);
            return false;
        }
        
        catch (Exception e){
            System.exit(1);
            e.printStackTrace();
            return false;
        }
    }

    // push
    // adds a node to the priority queue in the correct spot
    public void push(Node node) {
        if (this.getHead() == null || this.getHead().lessThan(node)) {
            PriorityQueue newRest = new PriorityQueue();
            newRest.head = head;
            newRest.rest = rest;
    
            head = node;
            rest = newRest;
            return;
        }
    
        if (rest == null) {
            rest = new PriorityQueue();
        }

        rest.push(node);
        return;
    }
    
    // EXTRACT_MIN
    // returns the node with the minimum frequency value
    public Node EXTRACT_MIN(){
        Node temp = new Node(head.getSymbols(), head.getFreq(), head.getLeft(), head.getRight());
        if (rest != null){
            head = rest.head;
            rest = rest.rest;
        }
        return temp;
    }
    
    // getHead
    // returns the head node of the queue
    public Node getHead(){
        return this.head;
    }

    // setHead
    // sets the head of the object to a given node
    public void setHead(Node head){
        this.head = head;
        return;
    }

    // setRest
    // sets the rest of the object to a given PQ
    public void setRest(PriorityQueue rest){
        this.rest = rest;
        return;
    }

    // getRest
    // returns the rest of the object
    public PriorityQueue getRest(){
        return this.rest;
    }

    // printPQ
    // prints the PQ for DEBUG purposes
    public void printPQ() {
        if (head != null) {
            System.out.println(this.head.getSymbols());
        }
        if (rest != null) {
            rest.printPQ();
        }
        return;
    }
}
