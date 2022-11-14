/*
Github: @Matt0550
Website: https://matt05.ml

Un’agenzia immobiliare organizza il proprio lavoro attraverso un sistema informatico in cui registra
i dati di ogni immobile. La procedura permette di calcolare il valore dell’immobile in funzione dei
mq, della categoria e della vetustà.
Al valore dell’immobile verrà applicato un correttivo in diminuzione in funzione della vetustà
dell’immobile
Creare un programma in Java che contenga la classe Immobile e che preveda i seguenti metodi:
1. Inserimento i dati dell’immobile;
2. Calcolo del valore dell’immobile secondo le seguenti tabelle;
3. Calcolare le tasse di registro pari al 6% sul valore;
4. Calcolare il canone di affitto pari a 7€ al mq + ulteriori 2€ in caso di locale commerciale.
Categoria Valore a mq Correttivo (Vetustà >= 10 < 20) Correttivo (Vetustà >= 20)

Residenziale 700 15% 27%
Pertinenza 500 10% 18%
Commerciale 950 13% 22%
*/
public class Immobile {
    private int mq;
    private String categoria;
    private int vetusta;
    private double valore;
    private double tasse;
    private double canone;
    
    public Immobile(int mq, String categoria, int vetusta) throws Exception {
        setMq(mq);
        setCategoriaImmobile(categoria);
        setVetusta(vetusta);
    }

    public void setCategoriaImmobile(String categoria) throws Exception {
        if (categoria.equals("Residenziale") || categoria.equals("Pertinenza") || categoria.equals("Commerciale")) {
            this.categoria = categoria;
        } else {
            throw new Exception("Categoria non valida");
        }
    }

    public void setMq(int mq) throws Exception {
        if (mq > 0) {
            this.mq = mq;
        } else {
            throw new Exception("mq non validi");
        }
    }

    public void setVetusta(int vetusta) throws Exception {
        if (vetusta > 0 && vetusta < 30) {
            this.vetusta = vetusta;
        } else {
            throw new Exception("Vetustà non valida");
        }
    }

    public int getMq() {
        return mq;
    }

    public String getCategoria() {
        return categoria;
    }

    public int getVetusta() {
        return vetusta;
    }

    public double getValore() {
        return valore;
    }

    public double getTasse() {
        return tasse;
    }

    public double getCanone() {
        return canone;
    }

    public double calcolaValore() throws Exception {
        if (categoria.equals("Residenziale")) {
            valore = mq * 700;
            if (vetusta >= 10 && vetusta < 20) {
                valore -= valore * 0.15;
            } else if (vetusta >= 20) {
                valore -= valore * 0.27;
            }
        } else if (categoria.equals("Pertinenza")) {
            valore = mq * 500;
            if (vetusta >= 10 && vetusta < 20) {
                valore -= valore * 0.10;
            } else if (vetusta >= 20) {
                valore -= valore * 0.18;
            }
        } else if (categoria.equals("Commerciale")) {
            valore = mq * 950;
            if (vetusta >= 10 && vetusta < 20) {
                valore -= valore * 0.13;
            } else if (vetusta >= 20) {
                valore -= valore * 0.22;
            }
        } else {
            throw new Exception("Categoria non valida");
        }
        return valore;
    }

    public double calcolaTasse() {
        tasse = valore * 0.06;
        return tasse;
    }

    public double calcolaCanone() {
        if (categoria.equals("Commerciale")) {
            canone = (mq * 7) + 2;
        } else {
            canone = mq * 7;
        }
        return canone;
    }

    public void stampa() throws Exception {
        System.out.println("mq: " + mq);
        System.out.println("Categoria: " + categoria);
        System.out.println("Vetustà: " + vetusta);
        System.out.println("Valore: " + calcolaValore());
        System.out.println("Tasse: " + calcolaTasse());
        System.out.println("Canone: " + calcolaCanone());
    }
}