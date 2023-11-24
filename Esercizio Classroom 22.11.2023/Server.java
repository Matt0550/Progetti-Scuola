/*
Create un classe in Java che, tramite l'uso dei socket e del package Java.net, esegua una richiesta HTTP ad un sito internet e legga la risposta.
Potete scegliere di richiedere in input il sito da interrogare, oppure lasciarlo statico nel codice.
*/

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.*;
import java.util.Scanner;
import java.time.LocalDateTime; 


public class Server {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.println("Inserisci la porta di ascolto (es. 80):" + ConsoleColors.BLUE);
            int port = scanner.nextInt();

            scanner.close();
            
            ServerSocket server = new ServerSocket(port);
            System.out.println(ConsoleColors.RESET + ConsoleColors.YELLOW + "Server in ascolto sulla porta " + ConsoleColors.RESET + ConsoleColors.BLUE + server.getLocalPort() + ConsoleColors.RESET);
            Socket client = server.accept();

            System.out.println(ConsoleColors.GREEN + "Il client " + ConsoleColors.BLUE_UNDERLINED + client.getInetAddress() + ConsoleColors.RESET +  ConsoleColors.GREEN + " si è connesso a " + ConsoleColors.BLUE + server.getLocalPort() + ConsoleColors.RESET);

            BufferedReader inDalClient = new BufferedReader(new InputStreamReader(client.getInputStream()));
            DataOutputStream outVersoClient = new DataOutputStream(new BufferedOutputStream(client.getOutputStream()));

            outVersoClient.writeBytes("Benvenuto. Inviami un messaggio e io ti risponderò in CAPS!\r\n");
            outVersoClient.flush();

            String message;
            while ((message = inDalClient.readLine()) != null) {
                System.out.println(ConsoleColors.YELLOW + "[CLIENT] " + ConsoleColors.RESET + ConsoleColors.BLUE + LocalDateTime.now() + ConsoleColors.RESET + ConsoleColors.YELLOW + " - " + ConsoleColors.GREEN + message + ConsoleColors.RESET);
                
                if (message.toLowerCase().contains("close") || message.toLowerCase().contains("exit")) {
                    outVersoClient.writeBytes("ARRIVEDERCI. \r\n");
                    outVersoClient.flush();
                    System.out.println(ConsoleColors.RED + "Connessione interrotta dal client." + ConsoleColors.RESET);
                    break;
                }               
                outVersoClient.writeBytes(message.toUpperCase() + "\r\n");
                outVersoClient.flush();                
            }
            
            client.close();
            server.close();

        } catch (Exception e) {
            System.out.println(ConsoleColors.RED + "ERRORE:" + ConsoleColors.YELLOW + e + ConsoleColors.RESET);
        }

    }
}