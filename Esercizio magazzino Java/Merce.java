/*
Si realizzi una applicazione java per la gestione di un magazzino secondo le
seguenti specifiche:
 Il magazzino contiene 3 tipi di merci: alimentari, casalinghi,
abbigliamento. La merce è identificata attraverso un codice univoco
progressivo;
 Viene implementata la classe base chiamata merce contenente i
seguenti attributi (numeroprogressivo, descrizione, codice fornitore,
quantità, prezzo unitario, scorta minima)
 si estenda la classe merce modellando le seguenti classi:
o alimentari (+data di scadenza, lattosio s/n, glutine s/n)
o casalinghi (+tipo (liquido, polvere, solido), )
o abbigliamento(+taglia, colore, tipo)

Si implementi una classe che modelli il magazzino sopradescritto
offrendo le seguenti operazioni di gestione utilizzando l’interfaccia
grafica:

1] immissione di un nuovo articolo;
2] estrazione dal magazzino di una merce il cui codice viene dato in
input;
3] stampa della situazione della merce sotto scorta;
4] stampa degli alimenti con data di scadenza inferiore a 5 giorni.

*/
public class Merce {
    private int numeroProgressivo;
    private String descrizione;
    private String codiceFornitore;
    private int quantita;
    private double prezzoUnitario;
    private int scortaMinima;

    public Merce(int numeroProgressivo, String descrizione, String codiceFornitore, int quantita, double prezzoUnitario,
            int scortaMinima) {
        this.numeroProgressivo = numeroProgressivo;
        this.descrizione = descrizione;
        this.codiceFornitore = codiceFornitore;
        this.quantita = quantita;
        this.prezzoUnitario = prezzoUnitario;
        this.scortaMinima = scortaMinima;
    }

    public int getNumeroProgressivo() {
        return numeroProgressivo;
    }

    public void setNumeroProgressivo(int numeroProgressivo) {
        this.numeroProgressivo = numeroProgressivo;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public String getCodiceFornitore() {
        return codiceFornitore;
    }

    public void setCodiceFornitore(String codiceFornitore) {
        this.codiceFornitore = codiceFornitore;
    }

    public int getQuantita() {
        return quantita;
    }

    public void setQuantita(int quantita) {
        this.quantita = quantita;
    }

    public double getPrezzoUnitario() {
        return prezzoUnitario;
    }

    public void setPrezzoUnitario(double prezzoUnitario) {
        this.prezzoUnitario = prezzoUnitario;
    }

    public int getScortaMinima() {
        return scortaMinima;
    }

    public void setScortaMinima(int scortaMinima) {
        this.scortaMinima = scortaMinima;
    }
}
