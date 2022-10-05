import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Matteo
 */
public class Banca {
    public Conto[] conti = new Conto[2];

    public Banca() {
        // Open conti.csv file
        File file = new File("conti.csv");
        try {
            Scanner scanner = new Scanner(file);
            int i = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                conti[i] = new Conto(data[0], data[1], data[2], data[3], Double.parseDouble(data[4]), Double.parseDouble(data[5]), data[6], data[7], data[8], data[9]);
                i++;
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public Boolean checkLogin(String username, String password) {
        System.out.println("Checking login for " + username + " " + password);
        for (int i = 0; i < conti.length; i++) {
            System.out.println(conti[i].getUserName() + " " + conti[i].getPassword());
            if (conti[i].getUserName().equals(username) && conti[i].getPassword().equals(password)) {
                return true;
            }
        }
        return false;
    }

    // return hash map of user data
    public HashMap<String, String> getUserData(String username) {
        HashMap<String, String> userData = new HashMap<String, String>();
        for (int i = 0; i < conti.length; i++) {
            if (conti[i].getUserName().equals(username)) {
                userData.put("nome", conti[i].getNome());
                userData.put("cognome", conti[i].getCognome());
                userData.put("dataDiNascita", conti[i].getDataDiNascita());
                userData.put("iban", conti[i].getIban());
                userData.put("saldo", Double.toString(conti[i].getSaldo()));
                userData.put("limite", Double.toString(conti[i].getLimite()));
                userData.put("username", conti[i].getUserName());
                userData.put("password", conti[i].getPassword());
            }
        }
        return userData;
    }
}
