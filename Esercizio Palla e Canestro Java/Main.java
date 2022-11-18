public class Main {
    

    public static void main(String[] args) {
        Canestro canestro = new Canestro (10, 10, 10, 10);
        Palla palla = new Palla(5, 10, 1, 1, canestro);
        palla.startGame();
        
    }
}