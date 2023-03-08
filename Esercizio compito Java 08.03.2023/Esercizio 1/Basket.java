public class Basket extends Sport {
    public Basket(int numGiocatori) {
        super(numGiocatori);
    }

    public void gioca() {
        System.out.println("Stai giocando a basket con " + super.numGiocatori + " giocatori!");
    }
}