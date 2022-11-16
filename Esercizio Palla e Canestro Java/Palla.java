public class Palla {
    private int x;
    private int y;
    private int speedX;
    private int speedY;
    private Canestro canestro;

    public Palla(int x, int y, int speedX, int speedY, Canestro canestro) {
        this.x = x;
        this.y = y;
        this.speedX = speedX;
        this.speedY = speedY;
        this.canestro = canestro;
    }

    public void move() {
        x += speedX;
        y += speedY;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getSpeedX() {
        return speedX;
    }

    public int getSpeedY() {
        return speedY;
    }

    public void setSpeedX(int speedX) {
        this.speedX = speedX;
    }

    public void setSpeedY(int speedY) {
        this.speedY = speedY;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    // Predict the line of the ball's trajectory and check if it will hit the basket. Print the x and y of all the points on the trajectory.
    public void draw2() {
        int x = this.x;
        int y = this.y;
        int speedX = this.speedX;
        int speedY = this.speedY;
        int canestroX = this.canestro.getX();
        int canestroY = this.canestro.getY();
        int canestroWidth = this.canestro.getWidth();
        int canestroHeight = this.canestro.getHeight();

        // Print the x and y of all the points on the trajectory.
        while (true) {
            System.out.println("x: " + x + " y: " + y);
            x += speedX;
            y += speedY;

            // Check if the ball will hit the basket.
            if (x >= canestroX && x <= canestroX + canestroWidth && y >= canestroY && y <= canestroY + canestroHeight) {
                System.out.println("The ball will hit the basket.");
                break;
            }
        }
    }

    // Create a grid and mark the position of the ball and the basket
    /*
    Example:
    1 2 3 4 5 6 7 8 9 10
    2 P
    3
    4
    5       C
    6
    7
    8
    9
    10
    */
    public void draw() {
        for (int i = 0; i <= canestro.getHeight(); i++) {
            for (int j = 0; j <= canestro.getWidth(); j++) {
                if (i == 0) {
                    System.out.print(j + " ");
                } else if (j == 0) {
                    System.out.print(i + " ");
                } else if (i == y && j == x) {
                    System.out.print("P ");
                } else if (i == canestro.getY() && j == canestro.getX()) {
                    System.out.print("C ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }
}