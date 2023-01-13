/**
 * Tombolone
 */
public class Tabellone {
    private int numeroColonneTabellone = 10;
    private int numeroRigheTabellone = 90 / numeroColonneTabellone;

    public Tabellone() {}

    public void generaTabellone() {
        //Add the numbers in rows
        for (int i = 0; i < numeroRigheTabellone; i++) {
            for (int j = 0; j < numeroColonneTabellone; j++) {
                // In the first row, add more spaces to the numbers to make the table look better
                if (i == 0) {
                    if (j < 9) {
                        System.out.print(" " + (i * numeroColonneTabellone + j + 1) + " ");
                    } else {
                        System.out.print((i * numeroColonneTabellone + j + 1) + " ");
                    }
                } else {
                    System.out.print((i * numeroColonneTabellone + j + 1) + " ");
                }
            }
            System.out.println();
        }
    }

    public void stampaTabellone() {
        generaTabellone();
    }

    
}