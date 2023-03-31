/**
 * Calcola
 */
public class Calcola {
    protected double base;
    protected double altezza;

    public Calcola(double base, double altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    public double areaTriangolo() {
        return (base * altezza) / 2;
    }

    public double perimetroRettangolo() {
        return (base + altezza) * 2;
    }

    public double areaRettangolo() {
        return base * altezza;
    }

}