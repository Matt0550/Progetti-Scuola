/**
 * Main
 */
public class Main {

    public static void main(String[] args) {
        Forma f = new Forma("Forma");
        f.stampa();

        Triangolo t = new Triangolo("Triangolo", 10, 5);
        t.stampa();

        Rettangolo r = new Rettangolo("Rettangolo", 10, 5);
        r.stampa();


    }
}