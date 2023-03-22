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

public class Alimentari extends Merce {
    private String dataDiScadenza;
    private boolean lattosio;
    private boolean glutine;

    public Alimentari(int numeroProgressivo, String descrizione, String codiceFornitore, int quantita,
            double prezzoUnitario, int scortaMinima, String dataDiScadenza, boolean lattosio, boolean glutine) {
        super(numeroProgressivo, descrizione, codiceFornitore, quantita, prezzoUnitario, scortaMinima);
        this.dataDiScadenza = dataDiScadenza;
        this.lattosio = lattosio;
        this.glutine = glutine;
    }

    public String getDataDiScadenza() {
        return dataDiScadenza;
    }

    public void setDataDiScadenza(String dataDiScadenza) {
        this.dataDiScadenza = dataDiScadenza;
    }

    public boolean isLattosio() {
        return lattosio;
    }

    public void setLattosio(boolean lattosio) {
        this.lattosio = lattosio;
    }

    public boolean isGlutine() {
        return glutine;
    }

    public void setGlutine(boolean glutine) {
        this.glutine = glutine;
    }
}