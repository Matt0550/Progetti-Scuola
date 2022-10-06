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


    public Conto(String nome, String cognome, String dataDiNascita, String iban, double saldo, double limite, String username, String password) {
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

    public void setUserName(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getDataDiNascita() {
        return dataDiNascita;
    }

    public void setDataDiNascita(String dataDiNascita) {
        this.dataDiNascita = dataDiNascita;
    }

    public String getIban() {
        return iban;
    }

    public void setIban(String iban) {
        this.iban = iban;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public Boolean preleva(double importo) {
        if (saldo - importo >= limite) {
            saldo -= importo;
            return true;
        }
        return false;
    }

    public Boolean deposita(double importo) {
        if(importo > limite) {
            return false;
        } else {
            saldo += importo;
            return true;
        }
    }

}
