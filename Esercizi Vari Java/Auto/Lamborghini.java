/*
    Implementare un programma che simuli un concessionario d'auto, dando in output il nome della marca, la cilindrata, quanti cavalli ha e il prezzo.
    Le classi figlie avranno anche il colore.
    La classe auto avrà il metodo stampa, che verrà ereditato da tutte le classi figlie.
    Implementare inoltre un metodo astratto per il calcolo del prezzo con e senza iva (22%).
*/

/**
 * Lamborghini
 */
public class Lamborghini extends Auto {
    private String colore;
    
    public Lamborghini(String marca, int cilindrata, int cavalli, double prezzo, String colore) { // Costruttore della classe figlio
        super(marca, cilindrata, cavalli, prezzo); // Richiama il costruttore della classe genitore
        this.colore = colore; // Aggiungo il nuovo costruttore
    }

    public void stampa() {
        super.stampa();
        System.out.println("Colore: " + colore);
    }

    public void accelera() { // Implemento il metodo astratto (sovrascrivo il metodo)
        System.out.println("Lamborghini sta accelerando!");
    }    
}