/**
 * Veicolo
 */
abstract class Veicolo {
    private int numeroRuote;
    private int velocitaMassima;
    private String colore;

    public Veicolo(int numeroRuote, int velocitaMassima, String colore) {
        this.numeroRuote = numeroRuote;
        this.velocitaMassima = velocitaMassima;
        this.colore = colore;
    }

    public int getNumeroRuote() {
        return numeroRuote;
    }

    public void setNumeroRuote(int numeroRuote) {
        this.numeroRuote = numeroRuote;
    }

    public int getVelocitaMassima() {
        return velocitaMassima;
    }

    public void setVelocitaMassima(int velocitaMassima) {
        this.velocitaMassima = velocitaMassima;
    }

    public String getColore() {
        return colore;
    }

    public void setColore(String colore) {
        this.colore = colore;
    }

    abstract void accelera();    
}