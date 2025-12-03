// Node.java
// Node Class for Huffman Encoding

public class Node {
    private String symbols;
    private int freq;
    private Node left;
    private Node right;
    
    // Node
    // Node constructor to create a node given that you already have the contents of the fields
    public Node(String symbols, int freq, Node left, Node right){
        this.symbols = symbols;
        this.freq = freq;
        this.left = left;
        this.right = right;
    }

    // getSymbols
    // returns the string array of symbols
    public String getSymbols(){
        return this.symbols;
    }

    // getFreq
    // returns the frequency of the node
    public int getFreq(){
        return this.freq;
    }

    // getLeft
    // returns the left node of the object
    public Node getLeft(){
        return this.left;
    }

    // getRight
    // returns the right node of the object
    public Node getRight(){
        return this.right;
    }

    // setSymbols
    // sets the Symbols of the object to a given string array
    public void setSymbols(String symbols){
        this.symbols = symbols;
        return;
    }

    // setFreq
    // sets the nodes frequency of the object to a given integer
    public void setFreq(int freq){
        this.freq = freq;
        return;
    }

    // setLeft
    // sets the nodes left node to a given node
    public void setLeft(Node left){
        this.left = left;
        return;
    }

    // setRight
    // sets the nodes right node to given node
    public void setRight(Node right){
        this.right = right;
        return;
    }

    // toString
    // returns a string representation of the node
    public String toString() {
        String response = "[" + this.symbols + " : " + this.freq + "]";    
        return response;
    }

    // lessThan
    // checks if the node you are passing in is less than the current object
    public Boolean lessThan(Node comp){
        if(this.getFreq() > comp.getFreq()){
            return true;
        }
        return false;
    }
}    