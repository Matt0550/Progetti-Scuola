/**
 * Gatto
 */
public class Gatto extends Animale {
    public Gatto(String nome, int numeroZampe) {
        super(nome, numeroZampe);
    }

    public void miagola() {
        System.out.println("Meow!");
    }
}