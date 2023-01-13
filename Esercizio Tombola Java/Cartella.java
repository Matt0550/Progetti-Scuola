import java.util.HashMap;

/**
 * Cartella
 */
public class Cartella {

    private HashMap<Integer, Integer> numeri = new HashMap<Integer, Integer>();
    private int numeroRighe = 3;
    private int numeroColonne = 9;
    private int numeriPerRiga = 5;

    public void stampaCartella() {
        generaCartella();
        for (int i = 0; i < numeroRighe; i++) {
            for (int j = 0; j < numeroColonne; j++) {
                System.out.print(numeri.get(i * numeroColonne + j) + " ");
            }
            System.out.println();
        }
    }



}