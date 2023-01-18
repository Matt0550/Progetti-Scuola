/**
 * Rettangolo
 */
public class Rettangolo extends Forma {
    private double base;
    private double altezza;

    public Rettangolo(String nome, double base, double altezza) {
        super(nome);
        this.base = base;
        this.altezza = altezza;
    }

    public void stampa() {
        System.out.println("Base: " + base);
        System.out.println("Altezza: " + altezza);
        System.out.println("Area: " + area());
        System.out.println("Perimetro: " + perimetro());
    }

    public double area() {
        return base * altezza;
    }

    public double perimetro() {
        return 2 * (base + altezza);
    }
}