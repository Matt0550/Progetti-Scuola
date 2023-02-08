package dado;

public class Dado extends Astratta {
    private int faccia;

    public Dado() {
        this.faccia = 0;
    }

    public void lancia() {
        this.faccia = (int) (Math.random() * 6) + 1;
    }

    public void stampa() {
        System.out.println("Faccia: " + this.faccia);
    }
}
