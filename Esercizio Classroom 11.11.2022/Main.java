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
public class Main {
    public static void main(String[] args) throws Exception {
        Immobile immobile = new Immobile(100, "Residenziale", 15);
        immobile.stampa();


        
    }
}