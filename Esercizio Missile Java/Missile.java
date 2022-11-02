import java.util.ArrayList;

public class Missile {
    private int x;
    private int y;
    private int max_x;
    private int max_y;
    private int target_x;
    private int target_y;
    private int speed;
    private int direction;
    private int type;

    Missile(int x, int y, int max_x, int max_y, int target_x, int target_y, int speed, int type) {
        this.x = x;
        this.y = y;
        this.max_x = max_x;
        this.max_y = max_y;
        this.target_x = target_x;
        this.target_y = target_y;
        this.speed = speed;
        this.type = type;
    }

    public void up() {
        if (y > 0) {
            y -= speed;
        }
    }

    public void down() {
        if (y < max_y) {
            y += speed;
        }
    }

    public void left() {
        if (x > 0) {
            x -= speed;
        }
    }

    public void right() {
        if (x < max_x) {
            x += speed;
        }
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getTarget_x() {
        return target_x;
    }

    public int getTarget_y() {
        return target_y;
    }

    public int getSpeed() {
        return speed;
    }

    public int getType() {
        return type;
    }

    public void setTarget_x(int target_x) {
        this.target_x = target_x;
    }

    public void setTarget_y(int target_y) {
        this.target_y = target_y;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setMax_x(int max_x) {
        this.max_x = max_x;
    }

    public void setMax_y(int max_y) {
        this.max_y = max_y;
    }

    public int getMax_x() {
        return max_x;
    }

    public int getMax_y() {
        return max_y;
    }

    public void setDirection(int direction) {
        this.direction = direction;
    }

    public int getDirection() {
        return direction;
    }

    // Create a grid of max_x by max_y
    /*
        Example
        1 2 3 4 5 6 7 8 9 10
        2
        3
        4
        5
        6
        7       X
        8
        9
        10 
    */
    public void createGrid() {
        // Print the row numbers at the top, the column numbers at the left, the P at the current position, and the T at the target position
        for (int i = 0; i <= max_x; i++) {
            for (int j = 0; j <= max_y; j++) {
                if (i == 0) {
                    System.out.print(j + " ");
                } else if (j == 0) {
                    System.out.print(i + " ");
                } else if (i == x && j == y) {
                    System.out.print("P ");
                } else if (i == target_x && j == target_y) {
                    System.out.print("T ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }

    // Calculate the distance between the missile and the target
    public double distance() {
        return Math.sqrt(Math.pow(target_x - x, 2) + Math.pow(target_y - y, 2));
    }
    
    // Randomly move the missile
    // Insert in array used to check if the missile has already been in that position hashmap
    // {x: 2, y: 3}, {x: 3, y: 3}, {x: 4, y: 3}
    // Create a hashmap of all the positions the missile has been in
    ArrayList<int[]> positions = new ArrayList<int[]>();

    public void randomMove() {
        // Create a random number between 1 and 4
        int random = (int) (Math.random() * 4) + 1;
        // Check if the missile has already been in that position
        boolean alreadyBeen = false;
        int[] position = new int[2];
        position[0] = x;
        position[1] = y;
        for (int i = 0; i < positions.size(); i++) {
            if (positions.get(i)[0] == position[0] && positions.get(i)[1] == position[1]) {
                alreadyBeen = true;
            }
        }
        if (!alreadyBeen) {
            positions.add(position);
        }
        // If the missile has already been in that position, then move in a different direction
        if (alreadyBeen) {
            switch (random) {
                case 1:
                    up();
                    break;
                case 2:
                    down();
                    break;
                case 3:
                    left();
                    break;
                case 4:
                    right();
                    break;
            }
        }
    }

}
