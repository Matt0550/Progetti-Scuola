import java.io.IOException;
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
        for (int i = 0; i < numeriUsati.length; i++) {
            if (numero == numeriUsati[i] && i != numeriUsati.length - 1) {
                pescaNumero();
                return;
            } else if (numeriUsati[i] == 0) {
                numeriUsati[i] = numero;
                break;
            }
        }

        System.out.println("Numero estratto: " + ConsoleColors.GREEN + numero + ConsoleColors.RESET);
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
                generaTabellone();
            }
            scanner.close();
            
           
        }
    }
}