/*
    Implementare un programma che simuli un concessionario d'auto, dando in output il nome della marca, la cilindrata, quanti cavalli ha e il prezzo.
    Le classi figlie avranno anche il colore.
    La classe auto avrà il metodo stampa, che verrà ereditato da tutte le classi figlie.
    Implementare inoltre un metodo astratto per il calcolo del prezzo con e senza iva (22%).
*/

/**
 * Main
 */
public class Main {
    public static void main(String[] args) {
        Ferrari ferrari = new Ferrari("Ferrari", 100, 200, 300, "Rossa");
        ferrari.stampa();
    }
}