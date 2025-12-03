// Btree.java

public class Btree{
    private Node root;
    
    // Btree
    // constructor
    public Btree(){
        this.root = null; 
    }

    // makeTree
    // takes in two nodes and combines them into one node
    public void makeTree(Node left, Node right){
        try{
            String newSymbols = left.getSymbols() + right.getSymbols();
            int newFreq = left.getFreq() + right.getFreq();

            Node newRoot = new Node(newSymbols, newFreq, left, right);
            this.root = newRoot;
        }
        catch(Exception e){
            e.printStackTrace();
            System.exit(1);
        }
        return;
    }

    // setRoot
    // sets the root of the object to a given node
    public void setRoot(Node root){
        this.root = root;
        return;
    }

    // getRoot
    // returns the root of the object
    public Node getRoot(){
        return this.root;
    }
    
    // printPrettyTree
    // prints the contents of the tree in a pretty and structured way
    public void printPrettyTree() {
        if (root == null) {
            System.out.println("Empty tree");
            return;
        }

        System.out.println("Huffman Tree:");
        System.out.println(root.toString());
        
        if (root.getRight() != null) {
            printPrettyTreeHelper(root.getRight(), "", root.getLeft() != null);
        }
        if (root.getLeft() != null) {
            printPrettyTreeHelper(root.getLeft(), "", false);
        }
        return;
    }

    // printPrettyTreeHelper
    // helper function for the printPrettyTree function that keeps track of the path
    private void printPrettyTreeHelper(Node node, String path, boolean isLeft) {
        if (node == null) return;

        System.out.print(path);
        if (isLeft){ 
            System.out.print("|---");
        }
        else{
            System.out.print("|___");
        }

        System.out.println(node.toString());

        String newPath = path;
        if(isLeft){
            newPath += "|   ";
        }
        else{
            newPath += "    ";
        }

        if (node.getRight() != null || node.getLeft() != null) {
            if (node.getRight() != null) {
                printPrettyTreeHelper(node.getRight(), newPath, node.getLeft() != null);
            }

            if (node.getLeft() != null) {
                printPrettyTreeHelper(node.getLeft(), newPath, false);
            }
        }
        return;
    }

    // printCodes
    // prints the binary codes for the tree(Left is 0, Right is 1) given a string of symbols
    public void printCodes(String[] symbols){
        String[] codes = new String[symbols.length];
        System.out.println("Binary Codes:");
        printCodesHelper(this.root, symbols, codes, 0);
        return;
    }

    // printCodesHelper
    // helper function for printCodes 
    private void printCodesHelper(Node node, String[] symbols, String[] codes, int depth){
        if(node == null) return;
        if(node.getLeft() == null && node.getRight() == null) {
            for(int i=0; i < symbols.length; ++i){
                if(node.getSymbols().equals(symbols[i])){
                    System.out.print("Node " + node.toString() + ", Code: ");
                    for (int j = 0; j < depth; ++j){
                        System.out.print(codes[j]);
                    }
                    System.out.println();
                    return;
                }
            }
        }

        codes[depth] = "0";
        printCodesHelper(node.getLeft(), symbols, codes, depth + 1);

        codes[depth] = "1";
        printCodesHelper(node.getRight(), symbols,codes,depth + 1);

        return;
    }
}