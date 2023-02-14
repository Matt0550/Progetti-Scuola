/*
    Implementare un programma che simuli un concessionario d'auto, dando in output il nome della marca, la cilindrata, quanti cavalli ha e il prezzo.
    Le classi figlie avranno anche il colore.
    La classe auto avrà il metodo stampa, che verrà ereditato da tutte le classi figlie.
    Implementare inoltre un metodo statico per il calcolo del prezzo con e senza iva (22%).
    Implementare infine un metodo astratto per accelerare
*/
/**
 * Iva
 */
public class Iva {
    public static Double calcoloIva(Double prezzoSenzaIva) { // La facciamo static perché non dobbiamo creare un costruttore.
        // Calcolo il 22% di iva
        return (prezzoSenzaIva * 0.22) + prezzoSenzaIva;
    }
}