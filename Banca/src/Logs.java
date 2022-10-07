import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Logs {
    private HashMap<String, String> logs = new HashMap<String, String>();
    public Logs() {
        // Open logs.csv file
        File file = new File("logs.csv");
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                logs.put("azione", data[0]);
                logs.put("valore", data[1]);
                logs.put("utente", data[2]);
                logs.put("iban", data[3]);
                logs.put("ibanDa", data[4]);
                logs.put("data", data[5]);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public void addLog(String azione, String valore, String utente, String iban, String ibanDa) {
        logs.put("azione", azione);
        logs.put("valore", valore);
        logs.put("utente", utente);
        logs.put("iban", iban);
        logs.put("ibanDa", ibanDa);
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        logs.put("data", now.format(formatter));
        try {
            FileWriter fileWriter = new FileWriter("logs.csv", true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            PrintWriter printWriter = new PrintWriter(bufferedWriter);
            printWriter.println(azione + "," + valore + "," + utente + "," + iban + "," + ibanDa + "," + now.format(formatter));
            printWriter.close();
            System.out.println("Saved logs.csv");
        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public HashMap<String, String> getLogs() {
        // Read again logs.csv file
        File file = new File("logs.csv");
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                logs.put("azione", data[0]);
                logs.put("valore", data[1]);
                logs.put("utente", data[2]);
                logs.put("iban", data[3]);
                logs.put("ibanDa", data[4]);
                logs.put("data", data[5]);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return logs;
    }

    public ArrayList<Object> getLogsOfUser(String username) {
        // Read again logs.csv file and return logs of user (0: [azione, valore, utente, iban, ibanDa])
        ArrayList<Object> logsOfUser = new ArrayList<Object>();
        File file = new File("logs.csv");
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                if (data[2].equals(username)) {
                    logsOfUser.add(data);
                }
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return logsOfUser;
    }
}
