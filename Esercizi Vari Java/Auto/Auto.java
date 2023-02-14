/*
    Implementare un programma che simuli un concessionario d'auto, dando in output il nome della marca, la cilindrata, quanti cavalli ha e il prezzo.
    Le classi figlie avranno anche il colore.
    La classe auto avrà il metodo stampa, che verrà ereditato da tutte le classi figlie.
    Implementare inoltre un metodo astratto per il calcolo del prezzo con e senza iva (22%).
*/

/**
 * Auto
 */
public abstract class Auto { // Classe genitore
    private String marca;
    private int cilindrata;
    private int cavalli;
    private double prezzo;

    public Auto(String marca, int cilindrata, int cavalli, double prezzo) { // Costruttore della classe genitore
        this.marca = marca;
        this.cilindrata = cilindrata;
        this.cavalli = cavalli;
        this.prezzo = prezzo;
    }

    public void stampa() {
        System.out.println("Marca: " + marca + "\nCilindrata: " + cilindrata + "\nCavalli: " + cavalli + "\nPrezzo senza iva: " + prezzo);
        System.out.println("Prezzo con iva: " + Iva.calcoloIva(prezzo));
    }

    abstract void accelera(); // Creo un metodo astratto che verrà implementato nelle classi figlie
    // Override/overwriting: sovrascrivere un metodo
    // Una classe astratta serve per creare delle classi figlie che ereditano i metodi e i costruttori della classe genitore
    // Una classe astratta non può essere istanziata (non può essere creata un oggetto)

    // L’overloading consente di creare diversi metodi con lo stesso nome ma con parametri formali differenti.
    /* ESEMPIO:
        public static int somma(int a, int b) {
            return a + b;
        }
        public static int somma(int a, int b, int c) {
            return a + b + c;
        }
        public static int somma(int a, int b, int c, int d) {
            return a + b + c + d;
        } 
    */
}