import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.time.Duration;
import java.time.LocalDateTime;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.println("Inserisci l'host (es. localhost):" + ConsoleColors.BLUE);
            String url = scanner.nextLine();

            System.out.println(ConsoleColors.RESET + "Inserisci la porta:" + ConsoleColors.BLUE);
            int port = scanner.nextInt();

            Socket client = new Socket(url, port);
            System.out.println(ConsoleColors.GREEN + "Connesso a " + ConsoleColors.BLUE + client.getInetAddress() + ConsoleColors.RESET);

            BufferedWriter outVersoServer = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
            BufferedReader inDalServer = new BufferedReader(new InputStreamReader(client.getInputStream()));

            String message = inDalServer.readLine();
            System.out.println(ConsoleColors.YELLOW + "[SERVER] " + ConsoleColors.GREEN + message + ConsoleColors.RESET);

            while (scanner.hasNextLine()) {
                System.out.println("Inserisci un messaggio da inviare al server ('exit' per uscire):" + ConsoleColors.BLUE);
                String text = scanner.nextLine();
                if (!text.isEmpty()) {
                    // Registra il tempo di invio del messaggio
                    LocalDateTime startTime = LocalDateTime.now();
                    
                    // Invia il messaggio al server
                    System.out.println(ConsoleColors.PURPLE + "[INPUT]: " + ConsoleColors.BLUE + startTime + ConsoleColors.PURPLE + " - " + ConsoleColors.GREEN + text + ConsoleColors.BLUE);
                    outVersoServer.write(text + "\r\n");
                    outVersoServer.flush();
                    
                    // Ricevi la risposta dal server
                    message = inDalServer.readLine();
                    
                    // Calcola e stampa il ping
                    LocalDateTime endTime = LocalDateTime.now();
                    Duration duration = Duration.between(startTime, endTime);
                    System.out.println(ConsoleColors.YELLOW + "[SERVER] " + ConsoleColors.BLUE + endTime + ConsoleColors.YELLOW + " - " + ConsoleColors.GREEN + message + ConsoleColors.CYAN + " - Ping: " + duration.toMillis() + " ms" + ConsoleColors.RESET);

                    if (text.toLowerCase().contains("close") || text.toLowerCase().contains("exit")) {
                        System.out.println(ConsoleColors.RED + "Hai interrotto la connessione con il server." + ConsoleColors.RESET);
                        break;
                    }
                }
            }

            scanner.close();
            client.close();

        } catch (IOException e) {
            System.err.println("Errore di I/O: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Errore generale: " + e.getMessage());
        }
    }
}
