
import java.io.*;
import java.net.*;
import javax.swing.*;

public class ChatClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5555);
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            out.println("Hello from Java client!");
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
