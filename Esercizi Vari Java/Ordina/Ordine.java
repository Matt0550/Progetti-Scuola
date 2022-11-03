/*
Implementare la classe Ordine, per la gestione degli ordini di un ristorante.
L'ordine è caratterizzato dal numero di tavolo, dal nome del cliente, dal numero di coperti (persone) e dal totale da pagare.

La classe deve possedere i seguenti metodi:
- getTavolo
- getNomeCliente
- getNumeroPersone
- getTotale

- setTavolo
- setNomeCliente
- setNumeroPersone
- setTotale

- stampaOrdine
*/

public class Ordine {
    // Visibilità di una variabile:
    // Private: variabile o metodo visibile solo all'interno della stessa classe (set e get)
    // Public: variabile o metodo visibile ovunque

    // Set: impostare (modificare) una variabile
    // Get: prendere o stampare a schermo una variabile (in genere si una il return)

    // 1. Creiamo gli attributi necessari
    // String: testo
    // int: numeri senza virgola
    // double: numeri con la virgola

    private int nTavolo;
    private String nomeCliente;
    private int nPersone;
    private int totPagare;

    // 2. Creiamo il costruttore
    Ordine(int nT, String nC, int nP, int tP) {
        // Assegnamo i valori del costruttore agli attributi dichiarati sopra
        // Se le variabili hanno lo stesso dobbiamo mettere il this prima altrimenti lo possiamo anche togliere.
        // Con il this indichiamo gli attributi che abbiamo dichiarato sopra. 
        nTavolo = nT;
        nomeCliente = nC;
        nPersone = nP;
        totPagare = tP;
    }

    // Metodi get
    public int getTavolo() {
        // Restituisco il valore del numero del tavolo (return)
        return nTavolo;
    }

    public String getNomeCliente() {
        return nomeCliente;
    }

    public int getNumeroPersone() {
        return nPersone;
    }

    public int getTotPagare() {
        return totPagare;
    }

    // Metodi set
    // Per i metodi set in genere si usa il void (public void)
    public void setTavolo(int nT) {
        // Impostiamo il valore di nTavolo su nT
        nTavolo = nT;
    }

    public void setNomeCliente(String nC) {
        nomeCliente = nC;
    }

    public void setNumeroPersone(int nP) {
        nPersone = nP;
    }

    public void setTotaleDaPagare(int tP) {
        totPagare = tP;
    }

    // Metodo stampa ordine
    public void stampaOrdine() {
        System.out.println("Numero del tavolo: " + nTavolo);
        System.out.println("Nome del cliente: " + nomeCliente);
        System.out.println("Numero di persone: " + nPersone);
        System.out.println("Totale da pagare: " + totPagare);
    }
}