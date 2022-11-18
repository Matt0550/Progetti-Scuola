import java.util.Scanner;

public class Palla {
    private int x;
    private int y;
    private int speedX;
    private int speedY;
    private Canestro canestro;
    private int originalX;
    private int originalY;
    private int maxSpeedX = 10;
    private int maxSpeedY = 10;
    private int moves;
    private int maxMoves;
    private int score;
    private int difficulty;
    Scanner scanner = new Scanner(System.in);

    public Palla(int x, int y, int speedX, int speedY, Canestro canestro) {
        this.canestro = canestro;
        setX(x);
        setY(y);
        setSpeedX(speedX);
        setSpeedY(speedY);
        setMaxMoves();
    }

    public void move(String direction) {
        // Also check if the ball touches the wall
        // If the Y-speed is more than 0, the ball not touches the wall else it touches
        // the wall
        // If the Y+speed is more than the height of the wall, the ball touches the wall
        // If the X-speed is more than 0, the ball not touches the wall else it touches
        // the wall
        // If the X+speed is more than the width of the wall, the ball touches the wall

        if (direction.equals("up") && getY() - getSpeedY() > 0) {
            setY(getY() - getSpeedY());
        } else if (direction.equals("down") && getY() + getSpeedY() <= canestro.getHeight()) {
            setY(getY() + getSpeedY());
        } else if (direction.equals("left") && getX() - getSpeedX() > 0) {
            setX(getX() - getSpeedX());
        } else if (direction.equals("right") && getX() + getSpeedX() <= canestro.getWidth()) {
            setX(getX() + getSpeedX());
        } else if (direction.equals("up") && getY() - getSpeedY() <= 0) {
            setY(1);
        } else if (direction.equals("down") && getY() + getSpeedY() > canestro.getHeight()) {
            setY(canestro.getHeight());
        } else if (direction.equals("left") && getX() - getSpeedX() <= 0) {
            setX(1);
        } else if (direction.equals("right") && getX() + getSpeedX() > canestro.getWidth()) {
            setX(canestro.getWidth());
        }
    }

    public void randomMove() {
        int random = (int) (Math.random() * 4);
        if (random == 0) {
            move("up");
        } else if (random == 1) {
            move("down");
        } else if (random == 2) {
            move("left");
        } else if (random == 3) {
            move("right");
        }
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
        if (speedX > 0 && speedX <= maxSpeedX) {
            this.speedX = speedX;
        } else {
            throw new IllegalArgumentException("SpeedX must be between 1 and " + maxSpeedX);
        }
    }

    public void setSpeedY(int speedY) {
        if (speedY > 0 && speedY <= maxSpeedY) {
            this.speedY = speedY;
        } else {
            throw new IllegalArgumentException("SpeedY must be between 1 and " + maxSpeedY);
        }
    }

    public void setX(int x) {
        if (x > 0 && x <= canestro.getWidth()) {
            if (originalX == 0) {
                originalX = x;
            }
            this.x = x;
        } else {
            throw new IllegalArgumentException("x must be between 1 and " + canestro.getWidth());
        }
    }

    public void setY(int y) {
        if (y > 0 && y <= canestro.getHeight()) {
            if (originalY == 0) {
                originalY = y;
            }
            this.y = y;
        } else {
            throw new IllegalArgumentException("y must be between 1 and " + canestro.getHeight());
        }
    }

    // Create a grid and mark the position of the ball and the basket and print the
    // trajectory of the ball.
    /*
     * Example:
     * 1 2 3 4 5 6 7 8 9 10
     * 1 · · · · · · · · · ·
     * 2 · · · · · · · · · ·
     * 3 · · · · · · · · · ·
     * 4 · · · · · · · · · ·
     * 5 · · · · · · · · · ·
     * 6 · · · · · · · · · ·
     * 7 · · · · P · · · · ·
     * 8 · · · · · · · · · ·
     * 9 · · · · · · · · · ·
     * 10 · · · · · · · · · C
    */
    public void draw() {
        for (int i = 0; i <= canestro.getHeight(); i++) {
            if (i == 0) {
                // Write the numbers of the columns
                for (int j = 0; j <= canestro.getWidth(); j++) {
                    if (j == 0) {
                        // Write the space of the first column
                        if (i > 10) {
                            System.out.print("   ");
                        } else {
                            System.out.print("    ");
                        }
                    } else {
                        System.out.print(j + "  ");
                    }
                }
                System.out.println();
            } else {
                // Write the numbers of the rows and fill the grid with the ball and the basket
                for (int j = 0; j <= canestro.getWidth(); j++) {
                    if (j == 0) {
                        if (i < 10) {
                            System.out.print(i + "  ");
                        } else {
                            System.out.print(i + " ");
                        }
                    } else if (j == canestro.getX() && i == canestro.getY()) {
                        System.out.print(" C ");
                    } else if (j == x && i == y) {
                        System.out.print(" P ");
                    } else {
                        System.out.print(" · ");
                    }
                }
                System.out.println();
            }
        }
    }

    public void reset() {
        canestro.setCanestro(difficulty);
        setMaxMoves();
        setDifficulty(difficulty);
        moves = 0;
        randomCoordinates();
        drawGame();
    }

    public void randomCoordinates() {
        // Generate random coordinates for the ball between 1 and the width and height
        // of the wall
        int randomX = (int) (Math.random() * canestro.getWidth()) + 1;
        int randomY = (int) (Math.random() * canestro.getHeight()) + 1;

        if (randomX == canestro.getX() && randomY == canestro.getY()) {
            randomCoordinates();
        } else {
            originalX = randomX;
            originalY = randomY;
            setX(randomX);
            setY(randomY);
        }
        System.out.println("Random coordinates: " + randomX + ", " + randomY);
    }

    public void setMaxMoves() {
        // Calculate the minimum moves to reach the basket. Diagonal moves are not
        // allowed.
        int x = getX();
        int y = getY();
        int basketX = canestro.getX();
        int basketY = canestro.getY();
        int moves = 0;

        // Calculate the minimum moves to reach the basket in the horizontal axis
        if (x > basketX) {
            moves += x - basketX;
        } else {
            moves += basketX - x;
        }

        // Calculate the minimum moves to reach the basket in the vertical axis
        if (y > basketY) {
            moves += y - basketY;
        } else {
            moves += basketY - y;
        }

        maxMoves = moves;
    }

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

    public void setDifficulty(int difficulty) {
        if (difficulty > 0 && difficulty <= 3) {
            this.difficulty = difficulty;

            switch (difficulty) {
                case 1:
                    maxMoves += 500;
                    canestro.setCanestro(difficulty);
                    break;
                case 2:
                    maxMoves += 3;
                    canestro.setCanestro(difficulty);
                    break;
                case 3:
                    maxMoves += 1;
                    canestro.setCanestro(difficulty);
                    break;
            }
        } else {
            throw new IllegalArgumentException("Difficulty must be between 1 and 3");
        }
    }

    public void selectDifficulty() {
        clearScreen();
        // Select the difficulty of the game
        System.out.println("Select the difficulty of the game:");
        System.out.println("1. Easy");
        System.out.println("2. Medium");
        System.out.println("3. Hard");
        System.out.print("Select a number: ");
        int difficulty = scanner.nextInt();

        setDifficulty(difficulty);
    }

    public void drawGame() {
        clearScreen();
        draw();
        System.out.println("Moves: " + moves + " - Max moves: " + maxMoves + " - Speed: " + getSpeedX() + " - Score: " + score + " - X: " + getX() + " - Y: " + getY());
    }

    public void startGame() {
        // Start the game
        selectDifficulty();
        System.out.println("Use WASD to move the ball");
        System.out.println("Use R to reset the ball");
        System.out.println("Use T to random move the ball");
        System.out.println("Use P to increase the speed");
        System.out.println("Use O to decrease the speed");
        System.out.println("Use Q to quit");
        while (true) {
            drawGame();   
            
            String input = scanner.nextLine();
            // Split the input in case the user pressed more than one key
            String[] inputs = input.split("");
            for (String i : inputs) {
                if (i.equalsIgnoreCase("w")) {
                    move("up");
                    moves+= getSpeedY();
                } else if (i.equalsIgnoreCase("s")) {
                    move("down");
                    moves+= getSpeedY();
                } else if (i.equalsIgnoreCase("a")) {
                    move("left");
                    moves+= getSpeedX();
                } else if (i.equalsIgnoreCase("d")) {
                    move("right");
                    moves+= getSpeedX();
                } else if (i.equalsIgnoreCase("r")) {
                    reset();
                } else if (i.equalsIgnoreCase("t")) {
                    randomMove();
                    moves++;
                } else if (i.equalsIgnoreCase("q")) {
                    scanner.close();
                    break;
                } else if (i.equalsIgnoreCase("p")) {
                    setSpeedX(getSpeedX() + 1);
                    setSpeedY(getSpeedY() + 1);
                } else if (i.equalsIgnoreCase("o")) {
                    setSpeedX(getSpeedX() - 1);
                    setSpeedY(getSpeedY() - 1);
                }
            }
            // Check if the ball is inside the basket
            if (getX() == canestro.getX() && getY() == canestro.getY()) {
                System.out.println("You won!");
                score += 10;
                reset();
            }
            // Check the moves
            if (moves >= maxMoves) {
                System.out.println("You lost!");
                score -= 3;
                reset();
            }
        }
    }
}