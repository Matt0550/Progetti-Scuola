/**
 * Auto
 */
public class Auto extends Veicolo {
    //Constructor
    public Auto(int numeroRuote, int velocitaMassima, String colore) {
        super(numeroRuote, velocitaMassima, colore);
    }

    //Override the accelerate method
    public void accelera() {
        System.out.println("L'auto sta accelerando.");
    }
}