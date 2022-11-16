public class Main {
    public static void main(String[] args) {
        Canestro canestro = new Canestro(10, 10, 10, 10);
        Palla palla = new Palla(4, 3, 2, 1, canestro);
    
        palla.draw2();
    }
}