public class Canestro {
    private int x;
    private int y;
    private int width;
    private int height;
    private int maxWidth = 30;
    private int maxHeight = 30;

    public Canestro(int x, int y, int width, int height) {
        setWidth(width);
        setHeight(height);
        setX(x);
        setY(y);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public void setX(int x) {
        if (x > 0 && x <= getWidth()) {
            this.x = x;
        } else {
            throw new IllegalArgumentException("x must be between 1 and " + getWidth());
        }
    }

    public void setY(int y) {
        if (y > 0 && y <= getHeight()) {
            this.y = y;
        } else {
            throw new IllegalArgumentException("y must be between 1 and " + getHeight());
        }
    }

    public void setWidth(int width) {
        if (width > 0 && width <= maxWidth) {
            this.width = width;
        } else {
            throw new IllegalArgumentException("Width must be between 1 and " + maxWidth);
        }
    }
    public void setHeight(int height) {
        if (height > 0 && height <= maxHeight) {
            this.height = height;
        } else {
            throw new IllegalArgumentException("Height must be between 1 and " + maxHeight);
        }
    }

    public void setCanestro(int difficulty) {
        switch (difficulty) {
            case 1:
                // Random grid size between 5 and 10
                setWidth((int) (Math.random() * 5) + 5);
                setHeight((int) (Math.random() * 5) + 5);
                // Random x and y between 1 and grid size
                setX((int) (Math.random() * getWidth()) + 1);
                setY((int) (Math.random() * getHeight()) + 1);
                break;
            case 2:
                // Random grid size between 10 and 20
                setWidth((int) (Math.random() * 10) + 10);
                setHeight((int) (Math.random() * 10) + 10);
                // Random x and y between 1 and grid size
                setX((int) (Math.random() * getWidth()) + 1);
                setY((int) (Math.random() * getHeight()) + 1);
                break;
            case 3:
                // Random grid size between 20 and 30
                setWidth((int) (Math.random() * 10) + 20);
                setHeight((int) (Math.random() * 10) + 20);
                // Random x and y between 1 and grid size
                setX((int) (Math.random() * getWidth()) + 1);
                setY((int) (Math.random() * getHeight()) + 1);
                break;
            default:
                throw new IllegalArgumentException("Difficulty must be between 1 and 3");
        }
    }
}