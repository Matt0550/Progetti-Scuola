/**
 * Triangolo
 */
public class Triangolo extends Forma {
    private double base;
    private double altezza;

    public Triangolo(String nome, double base, double altezza, double lato2, double lato3) {
        super(nome);
        this.base = base;
        this.altezza = altezza;
        this.lato2 = lato2;
        this.lato3 = lato3;
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
        return base + lato2 + lato3;
    }
}
