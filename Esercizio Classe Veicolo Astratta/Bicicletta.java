/**
 * Bicicletta
 */
public class Bicicletta extends Veicolo {
    //Constructor
    public Bicicletta(int numeroRuote, int velocitaMassima, String colore) {
        super(numeroRuote, velocitaMassima, colore);
    }

    //Override the accelerate method
    public void accelera() {
        System.out.println("La bicicletta sta pedalando più velocemente.");
    }
}