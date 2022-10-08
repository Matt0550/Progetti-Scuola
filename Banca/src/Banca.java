/*
    Developed by:  Matt05
    Website:       http://matt05.ml
    GitHub:        @Matt0550
*/

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author Matteo
 */
public class Banca {
    public Conto[] conti = new Conto[2];
    Logs logs = new Logs();

    public Banca() {
        // Open conti.csv file
        File file = new File("conti.csv");
        try {
            Scanner scanner = new Scanner(file);
            int i = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                conti[i] = new Conto(data[0], data[1], data[2], data[3], Double.parseDouble(data[4]), Double.parseDouble(data[5]), data[6], data[7]);
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
            if (conti[i].getUserName().equals(username) && conti[i].getPassword().equals(password)) {
                return true;
            }
        }
        return false;
    }

    public Conto getConto(String iban) {
        if (iban != null && iban.length() == 27) {
            for (int i = 0; i < conti.length; i++) {
                if (conti[i].getIban().equals(iban)) {
                    return conti[i];
                }
            }
        }
        return null;
    }

    public Boolean preleva(String iban, double importo) {
        for (int i = 0; i < conti.length; i++) {
            if (conti[i].getIban().equals(iban)) {
                if (conti[i].preleva(importo)) {
                    logs.addLog("Prelievo", String.valueOf(importo), conti[i].getUserName(), iban, iban);
                    return true;
                }
            }
        }
        return false;
    }

    public Boolean deposita(String iban, double importo) {
        for (int i = 0; i < conti.length; i++) {
            if (conti[i].getIban().equals(iban)) {
                if (conti[i].deposita(importo)) {
                    logs.addLog("Deposito", String.valueOf(importo), conti[i].getUserName(), iban, iban);
                    return true;
                }
            }
        }
        return false;
    }

    public Boolean bonifico(String iban1, String iban2, double importo) {
        Conto conto1 = getConto(iban1);
        Conto conto2 = getConto(iban2);
        if (conto1 != null && conto2 != null) {
            if (conto1.preleva(importo)) {
                if (conto2.deposita(importo)) {
                    logs.addLog("Bonifico", String.valueOf(importo), conto1.getUserName(), iban1, iban2);
                    return true;
                }
            }
        }
        return false;
    }

    public Boolean modificaIntestatario(String username, String nome, String cognome, String dataDiNascita) {
        for (int i = 0; i < conti.length; i++) {
            if (conti[i].getUserName().equals(username)) {
                if (nome != null && nome.length() > 0 && cognome != null && cognome.length() > 0 && dataDiNascita != null && dataDiNascita.length() > 0) {
                    conti[i].setNome(nome);
                    conti[i].setCognome(cognome);
                    conti[i].setDataDiNascita(dataDiNascita);
                    
                    logs.addLog("Modifica Intestatario", "", username, conti[i].getIban(), conti[i].getIban());
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    public void saveCSV() {
        String tmp = "tmp.csv";
        File oldFile = new File("conti.csv");
        File newFile = new File(tmp);

        try {
            FileWriter fw = new FileWriter(tmp, true);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);

            for (int i = 0; i < conti.length; i++) {
                pw.println(conti[i].getNome() + "," + conti[i].getCognome() + "," + conti[i].getDataDiNascita() + "," + conti[i].getIban() + "," + conti[i].getSaldo() + "," + conti[i].getLimite() + "," + conti[i].getUserName() + "," + conti[i].getPassword());
            }

            pw.flush();
            pw.close();

            oldFile.delete();
            File dump = new File("conti.csv");
            newFile.renameTo(dump);
            System.out.println("Saved conti.csv");
            
        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    // return hash map of user data
    public HashMap<String, String> getUserData(String username, String iban) {
        HashMap<String, String> userData = new HashMap<String, String>();
        for (int i = 0; i < conti.length; i++) {
            if(username != null) {
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
            } else if(iban != null) {
                if (conti[i].getIban().equals(iban)) {
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
        }
        return userData;
    }
}