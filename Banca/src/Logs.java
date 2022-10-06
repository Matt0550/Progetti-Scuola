import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.PrintWriter;
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
                logs.put("iban", data[2]);
                logs.put("ibanDa", data[3]);
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

        // Write to logs.csv file
        String temp = "temp.csv";
        File oldFile = new File("logs.csv");
        File newFile = new File(temp);

        try {
            FileWriter fw = new FileWriter(temp, true);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            Scanner scanner = new Scanner(oldFile);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                pw.println(data[0] + "," + data[1] + "," + data[2] + "," + data[3]);
            }
            scanner.close();
            pw.flush();
            pw.close();
            oldFile.delete();
            File dump = new File("logs.csv");
            newFile.renameTo(dump);
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
                logs.put("iban", data[2]);
                logs.put("ibanDa", data[3]);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return logs;
    }

    public HashMap<String, String> getLogsOfUser(String iban) {
        // Read again logs.csv file
        File file = new File("logs.csv");
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                if (data[2].equals(iban)) {
                    logs.put("azione", data[0]);
                    logs.put("valore", data[1]);
                    logs.put("iban", data[2]);
                    logs.put("ibanDa", data[3]);
                }
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return logs;
    }
}
