
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.*;
import java.time.LocalDateTime;

public class Runner implements Runnable {
    private Socket client;

    public Runner(Socket client) {
        this.client = client;
    }

    public void run() {
        try {
            BufferedReader inDalClient = new BufferedReader(new InputStreamReader(client.getInputStream()));
            DataOutputStream outVersoClient = new DataOutputStream(new BufferedOutputStream(client.getOutputStream()));

            outVersoClient.writeBytes("Benvenuto. Inviami un messaggio e io ti risponderò in CAPS!\r\n");
            outVersoClient.flush();

            String message;
            while ((message = inDalClient.readLine()) != null) {
                System.out.println(ConsoleColors.YELLOW + "[CLIENT] " + ConsoleColors.RESET + ConsoleColors.BLUE
                        + LocalDateTime.now() + ConsoleColors.RESET + ConsoleColors.YELLOW + " - " + ConsoleColors.GREEN
                        + message + ConsoleColors.RESET);

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
        } catch (Exception e) {
            System.out.println(ConsoleColors.RED + "ERRORE:" + ConsoleColors.YELLOW + e + ConsoleColors.RESET);
        }

    }
}
