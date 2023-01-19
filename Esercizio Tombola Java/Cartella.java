import java.util.ArrayList;

/**
 * Cartella
 */
public class Cartella {
    private int numeroRighe = 3;
    private int numeroColonne = 9;
    private int numeriPerRiga = 5;
    private int numeriPerCartella = numeroRighe * numeriPerRiga;
    
    private int numeriCartella[][] = new int[numeroRighe][numeroColonne];
    private int numeriUsati[][] = new int[numeroRighe][numeroColonne];

    public void generaNumeri() {
        ArrayList<Integer> numeri_generati = new ArrayList<Integer>();
        
        for (int i = 0; i < numeroRighe; i++) {
            for (int j = 0; j < numeroColonne; j++) {
                numeriCartella[i][j] = 0;
            }
        }

        for (int i = 0; i < numeriPerCartella; i++) {
            // Genero un numero casuale tra 1 e 90 verificando che non sia già stato generato
            // Verifico che ci siano obbligatoriamente 5 numeri per riga. Nel caso rigenero il numero
            int numero = (int) (Math.random() * 90 + 1);
            while (numeri_generati.contains(numero)) {
                numero = (int) (Math.random() * 90 + 1);
            }
            numeri_generati.add(numero);

            // Calcolo la decina corrispondente
            int decina = (int) (numero / 10);
            // Verifico se ci sono più di 3 numeri della stessa decina e quindi della stessa colonna
            int k = 0;
            for (int j = 0; j < numeri_generati.size(); j++) {
                if (numeri_generati.get(j) / 10 == decina) {
                    k++;
                }
            }
            if (k > 3) {
                numeri_generati.remove(i);
                i--;
            }

        }

        for (int i = 0; i < numeriPerCartella; i++) {
            int numero = numeri_generati.get(i);
            int decina = numero / 10;
            if (decina == 9) {
                decina--;
            }
            for (int j = 0; j < 3; j++) {
                int contatore = 0;
                for(int l = 0; l < 9; l++) {
                    if (numeriCartella[j][l] != 0) {
                        contatore++;
                    }
                }
                if (contatore < 5) {
                    if (numeriCartella[j][decina] == 0) {
                        numeriCartella[j][decina] = numero;
                        break;
                    }
                }
            }
        }
    }


    public void verificaVincite() {
        for (int i = 0; i < numeriUsati.length; i++) {
            int contatore = 0;
            ArrayList<Integer> numeri = new ArrayList<Integer>();

            for (int j = 0; j < numeriUsati[i].length; j++) {
                if (numeriUsati[i][j] != 0) {
                    contatore++;
                    numeri.add(numeriUsati[i][j]);
                }
            }

            if (contatore == 5) {
                System.out.println("Riga " + (i + 1) + ": " + "Hai fatto " + ConsoleColors.BLUE + "cinquina" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
            }

            if (contatore == 4) {
                System.out.println("Riga " + (i + 1) + ": " + "Hai fatto " + ConsoleColors.YELLOW + "quaterna" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
            }

            if (contatore == 3) {
                System.out.println("Riga " + (i + 1) + ": " + "Hai fatto " + ConsoleColors.GREEN + "terno" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
            }

            if (contatore == 2) {
                System.out.println("Riga " + (i + 1) + ": " + "Hai fatto " + ConsoleColors.RED + "ambo" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
            }
        }
        // Check for tombola
        int contatore = 0;
        for (int i = 0; i < numeriUsati.length; i++) {
            for (int j = 0; j < numeriUsati[i].length; j++) {
                if (numeriUsati[i][j] != 0) {
                    contatore++;
                }
            }
        }
        if (contatore == 15) {
            System.out.println("HAI FATTO " + ConsoleColors.PURPLE + "TOMBOLA" + ConsoleColors.RESET);
        }
    }

    public void generaCartella() {
        verificaVincite();
        System.out.println("-------------------Cartella------------------");
        // Stampo la cartella. 5 numeri per riga e 4 spazi tra i numeri usando i separatori
        for (int i = 0; i < numeroRighe; i++) {
            System.out.print("|");
            for (int j = 0; j < numeroColonne; j++) {
                if (numeriCartella[i][j] == 0) {
                    if (j == 0) { // Se è la prima colonna metto 3 spazi
                        System.out.print("   ");
                    } else { // Altrimenti metto 4 spazi
                        System.out.print("    ");
                    }
                } else {
                    // Verifico se il numero è già stato usato
                    if (numeriUsati[i][j] == 0) {
                        System.out.print(" " + numeriCartella[i][j] + " ");
                    } else {
                        if (j == 0) { // Se è la prima colonna metto 3 spazi
                            System.out.print(" X ");
                        } else { // Altrimenti metto 4 spazi
                            System.out.print("  X ");
                        }
                    }

                    
                }
                System.out.print("|");
            }
            System.out.println();
        }
        System.out.println("---------------------------------------------");
    }

    public void chiudiNumero(int numeroDaChiudere) {
        // Aggiorno l'array dei numeri usati
        for (int i = 0; i < numeriUsati.length; i++) {
            for (int j = 0; j < numeriUsati[i].length; j++) {
                if (numeriCartella[i][j] == numeroDaChiudere) {
                    numeriUsati[i][j] = numeroDaChiudere;
                }
            }
        }

    }

    public void stampaCartella() {
        generaCartella();
        System.out.println();
    }

    public Cartella() {
        generaNumeri();
    }
}