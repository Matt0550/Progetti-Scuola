import java.time.LocalDate;
import java.util.ArrayList;

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

public class Magazzino {
    private Merce[] magazzino;
    private int numeroMerce;

    public Magazzino(int numeroMerce) {
        this.magazzino = new Merce[numeroMerce];
        this.numeroMerce = 0;
    }

    public void aggiungiMerce(Merce merce) {
        if (numeroMerce < magazzino.length) {
            magazzino[numeroMerce] = merce;
            numeroMerce++;

            System.out.println("Aggiunta merce con il codice " + merce.getNumeroProgressivo());
        }
    }

    public void estraiMerce(int codice) {
        for (int i = 0; i < numeroMerce; i++) {
            if (magazzino[i].getNumeroProgressivo() == codice) {
                magazzino[i] = magazzino[numeroMerce - 1];
                magazzino[numeroMerce - 1] = null;
                numeroMerce--;

                System.out.println("Estratta merce con il codice " + codice);
            }
        }
    }

    public int getNextNumeroProgressivo() {
        return numeroMerce + 1;
    }

    // Ritorno in un arrayList tutti gli articoli
    public ArrayList<Merce> getMagazzino() {
        ArrayList<Merce> merce = new ArrayList<Merce>();
        for (int i = 0; i < numeroMerce; i++) {
            merce.add(magazzino[i]);
        }
        System.out.println(merce);
        return merce;
    }

    // Ritorno in un arrayList solo gli alimenti in scadenza
    public ArrayList<Merce> getAlimentiScadenza() {
        ArrayList<Merce> merce = new ArrayList<Merce>();
        for (int i = 0; i < numeroMerce; i++) {
            if (magazzino[i] instanceof Alimentari) {
                String[] dataScadenza = ((Alimentari) magazzino[i]).getDataDiScadenza().split("/");
                int giorno = Integer.parseInt(dataScadenza[0]);
                int mese = Integer.parseInt(dataScadenza[1]);
                int anno = Integer.parseInt(dataScadenza[2]);
                LocalDate data = LocalDate.of(anno, mese, giorno);
                long differenza = data.toEpochDay() - LocalDate.now().toEpochDay(); // Differenza tra le due date in giorni (toEpochDay() ritorna il numero di giorni trascorsi dal 1/1/1970)
                if (differenza < 5) {
                    merce.add(magazzino[i]);
                }
            }
        }
        System.out.println(merce);
        return merce;
    }
}
