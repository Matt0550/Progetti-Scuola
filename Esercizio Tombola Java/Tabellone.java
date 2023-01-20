import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Tombolone
 */
public class Tabellone {
    private int numeroColonneTabellone = 10;
    private int numeroRigheTabellone = 90 / numeroColonneTabellone;
    // Array of used numbers
    private int[] numeriUsati = new int[90];

    public Tabellone() {
    }

    private void pescaNumero() {
        // When function is called, generate a random number between 1 and 90 and add it
        // to the array of used numbers. If the number is already in the array, generate
        // a new number until it is not in the array
        int numero = (int) (Math.random() * 90 + 1);
        while (numeriUsati[numero - 1] != 0) {
            numero = (int) (Math.random() * 90 + 1);
        }
        numeriUsati[numero - 1] = numero;

        System.out.println("Numero estratto: " + ConsoleColors.GREEN + numero + ConsoleColors.RESET);
    }

    public int calcoloNumeroCartella(int numero) {
        // I numeri da 1 a 5, da 11 a 15 e da 21 a 25 sono nella prima cartella
        // I numeri da 6 a 10, da 16 a 20 e da 26 a 30 sono nella seconda cartella
        // I numeri da 31 a 35, da 41 a 45 e da 51 a 55 sono nella terza cartella
        // I numeri da 36 a 40, da 46 a 50 e da 56 a 60 sono nella quarta cartella
        // I numeri da 61 a 65, da 71 a 75 e da 81 a 85 sono nella quinta cartella
        // I numeri da 66 a 70, da 76 a 80 e da 86 a 90 sono nella sesta cartella
        if (numero >= 1 && numero <= 5 || numero >= 11 && numero <= 15 || numero >= 21 && numero <= 25) {
            return 1;
        } else if (numero >= 6 && numero <= 10 || numero >= 16 && numero <= 20 || numero >= 26 && numero <= 30) {
            return 2;
        } else if (numero >= 31 && numero <= 35 || numero >= 41 && numero <= 45 || numero >= 51 && numero <= 55) {
            return 3;
        } else if (numero >= 36 && numero <= 40 || numero >= 46 && numero <= 50 || numero >= 56 && numero <= 60) {
            return 4;
        } else if (numero >= 61 && numero <= 65 || numero >= 71 && numero <= 75 || numero >= 81 && numero <= 85) {
            return 5;
        } else if (numero >= 66 && numero <= 70 || numero >= 76 && numero <= 80 || numero >= 86 && numero <= 90) {
            return 6;
        } else {
            return 0;
        }
    }
    String vinciteUscite[] = new String[5];

    public void verificaVincite() {
        // Verifico le vincite per cartella. Prendo i numeri a 5 a 5 
        for (int i = 0; i < numeriUsati.length; i += 5) {
            int contatore = 0;
            ArrayList<Integer> numeri = new ArrayList<Integer>();

            // Conto i numeri usati
            for (int j = 0; j < 5; j++) {
                if (numeriUsati[i + j] != 0) {
                    contatore++;
                    numeri.add(numeriUsati[i + j]);
                }
            }

            int cartella = 0;
            for (int j = 0; j < numeri.size(); j++) {
                cartella = calcoloNumeroCartella(numeri.get(j));
            }


            if (contatore == 5 && vinciteUscite[0] != "cinquina") {
                System.out.println("Cartella " + cartella + ": " + "Hai fatto " + ConsoleColors.BLUE + "cinquina" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
                // Aggiungo la vincita alla lista delle vincite uscite
                vinciteUscite[0] = "cinquina";

            }

            if (contatore == 4 && vinciteUscite[1] != "quaterna") {
                System.out.println("Cartella " + cartella + ": " + "Hai fatto " + ConsoleColors.YELLOW + "quaterna" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
                // Aggiungo la vincita alla lista delle vincite uscite
                vinciteUscite[1] = "quaterna";
            }
            
            if (contatore == 3 && vinciteUscite[2] != "terno") {
                System.out.println("Cartella " + cartella + ": " + "Hai fatto " + ConsoleColors.GREEN + "terno" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
                // Aggiungo la vincita alla lista delle vincite uscite
                vinciteUscite[2] = "terno";
            }
            
            if (contatore == 2 && vinciteUscite[3] != "ambo") {
                System.out.println("Cartella " + cartella + ": " + "Hai fatto " + ConsoleColors.RED + "ambo" + ConsoleColors.RESET + " con i seguenti numeri: ");
                for (int j = 0; j < numeri.size(); j++) {
                    System.out.print(numeri.get(j) + " ");
                }
                System.out.println();
                // Aggiungo la vincita alla lista delle vincite uscite
                vinciteUscite[3] = "ambo";
            }
        }

        // Verifico la tombola (se 15 numeri della stessa cartella sono usciti)
        int contatoreCartella1 = 0;
        int contatoreCartella2 = 0;
        int contatoreCartella3 = 0;
        int contatoreCartella4 = 0;
        int contatoreCartella5 = 0;
        int contatoreCartella6 = 0;

        for (int i = 0; i < numeriUsati.length; i++) {
            if (calcoloNumeroCartella(numeriUsati[i]) == 1) {
                contatoreCartella1++;
            } else if (calcoloNumeroCartella(numeriUsati[i]) == 2) {
                contatoreCartella2++;
            } else if (calcoloNumeroCartella(numeriUsati[i]) == 3) {
                contatoreCartella3++;
            } else if (calcoloNumeroCartella(numeriUsati[i]) == 4) {
                contatoreCartella4++;
            } else if (calcoloNumeroCartella(numeriUsati[i]) == 5) {
                contatoreCartella5++;
            } else if (calcoloNumeroCartella(numeriUsati[i]) == 6) {
                contatoreCartella6++;
            }
        }

        if (contatoreCartella1 == 15 && vinciteUscite[4] != "tombola") {
            System.out.println("Hai fatto " + ConsoleColors.PURPLE + "tombola" + ConsoleColors.RESET + " con la cartella 1");
            vinciteUscite[4] = "tombola";
        } else if (contatoreCartella2 == 15 && vinciteUscite[4] != "tombola") {
            System.out.println("Hai fatto " + ConsoleColors.PURPLE + "tombola" + ConsoleColors.RESET + " con la cartella 2");
            vinciteUscite[4] = "tombola";
        } else if (contatoreCartella3 == 15 && vinciteUscite[4] != "tombola") {
            System.out.println("Hai fatto " + ConsoleColors.PURPLE + "tombola" + ConsoleColors.RESET + " con la cartella 3");
            vinciteUscite[4] = "tombola";
        } else if (contatoreCartella4 == 15 && vinciteUscite[4] != "tombola") {
            System.out.println("Hai fatto " + ConsoleColors.PURPLE + "tombola" + ConsoleColors.RESET + " con la cartella 4");
            vinciteUscite[4] = "tombola";
        } else if (contatoreCartella5 == 15 && vinciteUscite[4] != "tombola") {
            System.out.println("Hai fatto " + ConsoleColors.PURPLE + "tombola" + ConsoleColors.RESET + " con la cartella 5");
            vinciteUscite[4] = "tombola";
        } else if (contatoreCartella6 == 15 && vinciteUscite[4] != "tombola") {
            System.out.println("Hai fatto " + ConsoleColors.PURPLE + "tombola" + ConsoleColors.RESET + " con la cartella 6");
            vinciteUscite[4] = "tombola";
        }
    }

    public void generaTabellone() {
        // Add the numbers in rows
        for (int i = 0; i < numeroRigheTabellone; i++) {
            if (i == 0) {
                System.out.println("-------------Tombola-------------");
            }

            // Add the numbers in columns (if the number is in the array, print X, otherwise
            // print the number)
            for (int j = 0; j < numeroColonneTabellone; j++) {
                int numero = i * numeroColonneTabellone + j + 1;
                // Check if the number is in the array if it is, print X, otherwise print the
                // number
                for (int k = 0; k < numeriUsati.length; k++) {
                    if (numero == numeriUsati[k]) {
                        if (i == 0) {
                            if (j < 10) {
                                System.out.print(ConsoleColors.RED + " X " + ConsoleColors.RESET);
                            } else {
                                System.out.print(ConsoleColors.RED + "X " + ConsoleColors.RESET);
                            }
                        } else {
                            System.out.print(ConsoleColors.RED + " X " + ConsoleColors.RESET);
                        }
                        break;
                    } else if (k == numeriUsati.length - 1) {
                        // In the first row, add more spaces to the numbers to make the table look
                        // better
                        if (i == 0) {
                            if (j < 9) {
                                System.out.print(" " + (numero) + " ");
                            } else {
                                System.out.print((numero) + " ");
                            }
                        } else {
                            System.out.print((numero) + " ");
                        }
                    }
                }

                // Every 5 numbers, add a separator
                if ((numero) % 5 == 0) {
                    System.out.print("| ");
                }

                // Every 30 numbers, add a new line
                if ((numero) % 30 == 0) {
                    System.out.println();
                }
            }

            System.out.println();
        }
    }

    public void stampaTabellone() {
        final String os = System.getProperty("os.name");

        while (true) {
            generaTabellone();
            // Read keyboard input to generate a new number
            System.out.println("Premi invio per generare un nuovo numero");
            Scanner scanner = new Scanner(System.in);

            // Loop until the user presses q
            while (true) {
                String input = scanner.nextLine();
                if (input.equals("q")) {
                    break;
                }
                if (os.contains("Windows")) {
                    try {
                        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                    } catch (IOException | InterruptedException e) {
                        e.printStackTrace();
                    }
                } else {
                    try {
                        new ProcessBuilder("clear").inheritIO().start().waitFor();
                    } catch (IOException | InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                pescaNumero();
                verificaVincite();
                generaTabellone();
            }
            scanner.close();
            
           
        }
    }
}