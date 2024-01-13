/*
Create un classe in Java che, tramite l'uso dei socket e del package Java.net, esegua una richiesta HTTP ad un sito internet e legga la risposta.
Potete scegliere di richiedere in input il sito da interrogare, oppure lasciarlo statico nel codice.
*/

import java.net.*;
import java.util.Scanner;

public class Server {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.println("Inserisci la porta di ascolto (es. 80):" + ConsoleColors.BLUE);
            int port = scanner.nextInt();

            scanner.close();

            ServerSocket server = new ServerSocket(port);
            System.out.println(ConsoleColors.RESET + ConsoleColors.YELLOW + "Server in ascolto sulla porta "
                    + ConsoleColors.RESET + ConsoleColors.BLUE + server.getLocalPort() + ConsoleColors.RESET);

            while (true) {

                Socket client = server.accept();

                System.out.println(ConsoleColors.GREEN + "Il client " + ConsoleColors.BLUE_UNDERLINED
                        + client.getInetAddress() + ConsoleColors.RESET + ConsoleColors.GREEN + " si è connesso a "
                        + ConsoleColors.BLUE + server.getLocalPort() + ConsoleColors.RESET);

                Thread t = new Thread(new Runner(client));
                t.start();

            }


        } catch (Exception e) {
            System.out.println(ConsoleColors.RED + "ERRORE:" + ConsoleColors.YELLOW + e + ConsoleColors.RESET);
        }

    }
}