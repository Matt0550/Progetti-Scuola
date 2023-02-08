/*
Realizza un programma che sia in grado di valutare il volume di oggetti tridimensionali come cilindri e parallelepipedi basandosi sul valore della loro area e dell'altezza. Delegare i metodi comuni, come il calcolo e la stampa del volume ad una classe astratta. 
*/

package volume;

/**
 * Main
 */
public class Main {
    
        public static void main(String[] args) {
            Cilindro cilindro = new Cilindro(2, 3);
            cilindro.stampaVolume();
    
            Parallelepipedo parallelepipedo = new Parallelepipedo(2, 3, 4);
            parallelepipedo.stampaVolume();
        }

}