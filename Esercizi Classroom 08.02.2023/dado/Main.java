/*
Scrivi un programma che simuli il lancio di un dado e di una moneta stampandone il risultato con e senza l'utilizzo di una classe astratta che rappresenti i comportamenti comuni degli oggetti dado e moneta istanziati. 
*/

package dado;

public class Main {
    
        public static void main(String[] args) {
            Moneta moneta = new Moneta();
            moneta.lancia();
            moneta.stampa();
    
            Dado dado = new Dado();
            dado.lancia();
            dado.stampa();
        }
    
}
