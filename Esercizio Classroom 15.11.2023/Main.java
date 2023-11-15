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


public class Main {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.println("Inserisci l'host (es. www.google.com): ");
            String url = scanner.nextLine();

            System.out.println("Inserisci la path (es. /img/logo.png): ");
            String path = scanner.nextLine();

            System.out.println("Inserisci la porta: ");
            int port = scanner.nextInt();

            scanner.close();

            String httpRequest = "GET "+ path +" HTTP/1.0\nHost: " + url + "\n\n";

            System.out.println("Connessione in corso a " + httpRequest + "------\n");

            Socket client = new Socket(url, port);

            DataOutputStream outVersoServer = new DataOutputStream(new BufferedOutputStream(client.getOutputStream()));
            BufferedReader inDalServer = new BufferedReader(new InputStreamReader(client.getInputStream()));
            
            outVersoServer.write(httpRequest.getBytes());
            outVersoServer.flush();

            String message;
            while ((message = inDalServer.readLine()) != null) {
                System.out.println(message);
            }

            client.close();

        } catch (Exception e) {
            System.out.println("ERRORE:" + e);
        }

    }
}