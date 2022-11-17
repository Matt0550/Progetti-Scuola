public class Canestro {
    private int x;
    private int y;
    private int width;
    private int height;

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
            throw new IllegalArgumentException("x must be between 0 and " + getWidth());
        }
    }

    public void setY(int y) {
        if (y > 0 && y <= getHeight()) {
            this.y = y;
        } else {
            throw new IllegalArgumentException("y must be between 0 and " + getHeight());
        }
    }

    public void setWidth(int width) {
        if (width > 0 && width <= 30) {
            this.width = width;
        } else {
            throw new IllegalArgumentException("Width must be between 0 and 30");
        }
    }
    public void setHeight(int height) {
        if (height > 0 && height <= 30) {
            this.height = height;
        } else {
            throw new IllegalArgumentException("Height must be between 0 and 30");
        }
    }

    
}