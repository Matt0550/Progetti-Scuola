package dado;

public class Moneta {
    private int faccia;

    public Moneta() {
        this.faccia = 0;
    }

    public void lancia() {
        this.faccia = (int) (Math.random() * 2);
    }

    public void stampa() {
        if (this.faccia == 0) {
            System.out.println("Croce");
        } else {
            System.out.println("Testa");
        }
    }
}
