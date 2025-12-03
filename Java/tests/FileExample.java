import java.io.*;

public class FileExample{
    public static void main(String argv[]){
        try {
            FileReader file = new FileReader("test.txt");
            StreamTokenizer inputStream = new StreamTokenizer(file);
            String node1 = ""; 
            String node2 = "";
            double weight = 0;
            int tokenType = inputStream.nextToken();
            while(tokenType != StreamTokenizer.TT_EOF){
                node1 = inputStream.sval;
                tokenType = inputStream.nextToken();
                node2 = inputStream.sval;
                tokenType = inputStream.nextToken();
                weight = inputStream.nval;
                tokenType = inputStream.nextToken();
            }
            try {
            System.out.println("City 1:" + node1 + "City 2:" +  node2 + "Weight: " + weight);
            }
            catch (Exception e){
                System.exit(1);
            }
        }
        catch (Exception e){
            System.exit(1);
        }
    }
}

