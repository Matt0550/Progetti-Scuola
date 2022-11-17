public class Palla {
    private int x;
    private int y;
    private int speedX;
    private int speedY;
    private int angle;
    private Canestro canestro;
    private int originalX;
    private int originalY;

    public Palla(int x, int y, int speedX, int speedY, int angle, Canestro canestro) {
        this.canestro = canestro;
        this.angle = angle;
        setX(x);
        setY(y);
        setSpeedX(speedX);
        setSpeedY(speedY);
    }

    public void move(String direction) {
        // Check if the ball touches the wall
        if (direction.equals("up") && getY()-getSpeedY() > 0) {
            setY(getY() - getSpeedY());
        } else if (direction.equals("down") && getY() + getSpeedY() < canestro.getHeight()) {
            setY(getY() + getSpeedY());
        } else if (direction.equals("left") && getX()-getSpeedX() > 0) {
            setX(getX() - getSpeedX());
        } else if (direction.equals("right") && getX() + getSpeedX() < canestro.getWidth()) {
            setX(getX() + getSpeedX());
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
        if (speedX > 0 && speedX <= 10) {
            this.speedX = speedX;
        } else {
            throw new IllegalArgumentException("SpeedX must be between 0 and 10");
        }
    }

    public void setSpeedY(int speedY) {
        if (speedY > 0 && speedY <= 10) {
            this.speedY = speedY;
        } else {
            throw new IllegalArgumentException("SpeedY must be between 0 and 10");
        }
    }

    public void setX(int x) {
        if (x > 0 && x <= canestro.getWidth()) {
            if(originalX == 0) {
                originalX = x;
            }
            this.x = x;
        } else {
            throw new IllegalArgumentException("x must be between 0 and " + canestro.getWidth());
        }
    }

    public void setY(int y) {
        if (y > 0 && y <= canestro.getHeight()) {
            if(originalY == 0) {
                originalY = y;
            }
            this.y = y;
        } else {
            throw new IllegalArgumentException("y must be between 0 and " + canestro.getHeight());
        }
    }

    public int getAngle() {
        return angle;
    }

    public void setAngle(int angle) {
        if (angle > 0 && angle <= 360) {
            this.angle = angle;
        } else {
            throw new IllegalArgumentException("Angle must be between 0 and 360");
        }
    }    

    // Create a grid and mark the position of the ball and the basket and print the trajectory of the ball.
    /*
    Example:
    1 2 3 4 5 6 7 8 9 10
    2 
    3
    4
    5       
    6
    7        
    8         
    9            
    10 P               C
    */
    public void draw() {
        for (int i = 0; i <= canestro.getHeight(); i++) {
            // Mark the position of the ball and the basket with P and C. Fill the rest of the grid with · and write the numbers of the rows and columns.
            if (i == 0) {
                for (int j = 0; j <= canestro.getWidth(); j++) {
                    if (j == 0) {
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
        setX(originalX);
        setY(originalY);
    }
}