/**
 * Triangolo
 */
public class Triangolo extends Forma {
    private double base;
    private double altezza;

    public Triangolo(String nome, double base, double altezza) {
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
        return (base * altezza) / 2;
    }

    public double perimetro() {
        return base + altezza + Math.sqrt(Math.pow(base, 2) + Math.pow(altezza, 2));
    }
}