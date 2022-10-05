import java.util.HashMap;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Matteo
 */
public class Conto {
    private String nome;
    private String cognome;
    private String dataDiNascita;
    private String iban;
    private double saldo;
    private double limite;

    private String username;
    private String password;

    // Hashmap per memorizzare i prelievi e i depositi
    private HashMap<String, Double> prelievi = new HashMap<String, Double>();
    private HashMap<String, Double> versamenti = new HashMap<String, Double>();

    public Conto(String nome, String cognome, String dataDiNascita, String iban, double saldo, double limite, String username, String password, String prelievi, String versamenti) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = dataDiNascita;
        this.iban = iban;
        this.saldo = saldo;
        this.limite = limite;
        this.username = username;
        this.password = password;
    }
    
    public String getUserName() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getDataDiNascita() {
        return dataDiNascita;
    }

    public String getIban() {
        return iban;
    }

    public double getSaldo() {
        return saldo;
    }

    public double getLimite() {
        return limite;
    }


}
