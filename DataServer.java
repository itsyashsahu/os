import java.net.*;
import java.io.*;

public class DataServer {

    public static void main(String[] args) {
        try {
            ServerSocket sock = new ServerSocket(6063);
            while (true) {
                Socket client = sock.accept();
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
                pout.println("Some Random Jokes.\n");
                client.close();
            }
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}

// axiosClient.get("/getCard");const response=await
// axiosClient.get("/getCard");setResArr(respone)