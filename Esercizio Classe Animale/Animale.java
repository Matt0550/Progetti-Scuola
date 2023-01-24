/**
 * Animale
 */
public class Animale {
    private int numeroZampe;
    private String nome;

    public Animale(String nome, int numeroZampe) {
        this.nome = nome;
        this.numeroZampe = numeroZampe;
    }

    public void stampa() {
        System.out.println("Nome: " + nome + " Numero zampe: " + numeroZampe);
    }
}