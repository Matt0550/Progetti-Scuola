/**
 * Uccello
 */
public class Uccello extends Animale {
    public Uccello(String nome, int numeroZampe) {
        super(nome, numeroZampe);
    }

    public void cinguetta() {
        System.out.println("Cinguettio!");
    }
}