public class Main {
    public static void main(String[] args) {
        // In una variabile cubo, mi salvo il risultato del cubo.
        // In questo caso richiamo il metodo statico presente nella
        // classe Calcolo.
        double cubo = Calcolo.cubo(2);
        System.out.println("Il cubo è: " + cubo);
    }
}