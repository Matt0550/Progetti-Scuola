import java.util.Scanner;
import java.io.IOException;

/**
 * Main
 */
public class Main {
    public static void main(String[] args) {

        // Read keyboard input
        System.out.println("Seleziona 1 per essere il tabellone, 2 per prendere una o più cartelle");
        Scanner scanner = new Scanner(System.in);
        while (true) {
            String input = scanner.nextLine();
            if (input.equals("1")) {
                Tabellone tabellone = new Tabellone();
                tabellone.stampaTabellone();
                scanner.close();
                break;

            } else if (input.equals("2")) {
                System.out.println("Quante cartelle vuoi prendere?");
                int numeroCartelle = scanner.nextInt();
                scanner.nextLine();
                while (numeroCartelle < 1 || numeroCartelle > 10) {
                    System.out.println("Input non valido");
                    numeroCartelle = scanner.nextInt();
                    scanner.nextLine();
                }
                Cartella[] cartelle = new Cartella[numeroCartelle];
                for (int i = 0; i < numeroCartelle; i++) {
                    cartelle[i] = new Cartella();
                    cartelle[i].stampaCartella();
                }

                while (true) {
                    // Chiedo all'utente di chiudere un numero
                    System.out.println("Inserisci un numero da chiudere");
                    int numeroDaChiudere = scanner.nextInt();

                    while (numeroDaChiudere < 1 || numeroDaChiudere > 90) {
                        System.out.println("Input non valido");
                        numeroDaChiudere = scanner.nextInt();
                        scanner.nextLine();
                    }
                    // Chiudo il numero
                    for (int i = 0; i < numeroCartelle; i++) {
                        cartelle[i].chiudiNumero(numeroDaChiudere);
                    }
                    final String os = System.getProperty("os.name");

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
                    // Stampo le cartelle
                    for (int i = 0; i < numeroCartelle; i++) {
                        cartelle[i].stampaCartella();
                    }
                }

            } else {
                System.out.println("Input non valido");
            }
        }
    }
}