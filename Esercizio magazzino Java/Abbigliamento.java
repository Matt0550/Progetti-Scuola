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

public class Abbigliamento extends Merce {
    private String taglia;
    private String colore;
    private String tipo;

    public Abbigliamento(int numeroProgressivo, String descrizione, String codiceFornitore, int quantita,
            double prezzoUnitario, int scortaMinima, String taglia, String colore, String tipo) {
        super(numeroProgressivo, descrizione, codiceFornitore, quantita, prezzoUnitario, scortaMinima);
        this.taglia = taglia;
        this.colore = colore;
        this.tipo = tipo;
    }

    public String getTaglia() {
        return taglia;
    }

    public void setTaglia(String taglia) {
        this.taglia = taglia;
    }

    public String getColore() {
        return colore;
    }

    public void setColore(String colore) {
        this.colore = colore;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
}