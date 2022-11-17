import java.util.Scanner;

public class Main {
    // Clear the screen
    public static void clearScreen() {
        // Check if the OS is Windows
        if (System.getProperty("os.name").contains("Windows")) {
            try {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } catch (Exception e) {
                System.out.println("Error: " + e);
            }
        } else {
            System.out.print("\033[H\033[2J");
            System.out.flush();
        }
    }

    public static void main(String[] args) {
        Canestro canestro = new Canestro (10, 10, 10, 10);
        Palla palla = new Palla(5, 10, 1, 1, 15, canestro);

        clearScreen();
        palla.draw();
        System.out.println("Use WASD to move the ball");
        System.out.println("Use R to reset the ball");
        System.out.println("Use T to random move the ball");
        System.out.println("Use P to increase the speed");
        System.out.println("Use O to decrease the speed");
        System.out.println("Use Q to quit");

        Scanner scanner = new Scanner(System.in);
        while (true) {
            // Check if the ball is inside the basket
            if (palla.getX() >= canestro.getX() && palla.getX() <= canestro.getX() + canestro.getWidth() && palla.getY() >= canestro.getY() && palla.getY() <= canestro.getY() + canestro.getHeight()) {
                System.out.println("You won!");
                scanner.close();
                break;
            }
            String input = scanner.nextLine();
            // Split the input in case the user pressed more than one key
            String[] inputs = input.split("");
            for (String i : inputs) {
                if (i.equalsIgnoreCase("w")) {
                    palla.move("up");
                } else if (i.equalsIgnoreCase("s")) {
                    palla.move("down");
                } else if (i.equalsIgnoreCase("a")) {
                    palla.move("left");
                } else if (i.equalsIgnoreCase("d")) {
                    palla.move("right");
                } else if (i.equalsIgnoreCase("r")) {
                    palla.reset();
                } else if (i.equalsIgnoreCase("t")) {
                    palla.randomMove();
                } else if (i.equalsIgnoreCase("q")) {
                    scanner.close();
                    break;
                } else if (i.equalsIgnoreCase("p")) {
                    palla.setSpeedX(palla.getSpeedX() + 1);
                    palla.setSpeedY(palla.getSpeedY() + 1);
                } else if (i.equalsIgnoreCase("o")) {
                    palla.setSpeedX(palla.getSpeedX() - 1);
                    palla.setSpeedY(palla.getSpeedY() - 1);
                }
            }
            clearScreen();
            palla.draw();
            System.out.println("Use WASD to move the ball");
            System.out.println("Use R to reset the ball");
            System.out.println("Use T to random move the ball");
            System.out.println("Use P to increase the speed");
            System.out.println("Use O to decrease the speed");
            System.out.println("Use Q to quit");
        }
    }
}