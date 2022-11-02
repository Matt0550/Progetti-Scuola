/**
 * Main
 * Implementare la classe missile. Possiede delle coordinate e implementare i
 * metodi
 * up
 * down
 * right
 * left
 * 
 * Selezionare il target (x, y)
 */


public class Main {
    public static void main(String[] args) {
        Missile missile = new Missile(3, 5, 10, 10, 10, 8, 3, 1);

        missile.createGrid();

        while (missile.getX() != missile.getTarget_x() || missile.getY() != missile.getTarget_y()) {
            missile.randomMove();
            missile.createGrid();
            // Sleep for 1 second
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            if (missile.getX() == missile.getTarget_x() && missile.getY() == missile.getTarget_y()) {
                System.out.println("Target reached!");
                break;
            }
        }

    }
}