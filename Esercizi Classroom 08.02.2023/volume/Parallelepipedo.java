package volume;

/**
 * Parallelepipedo
 */
public class Parallelepipedo {

    private double base;
    private double altezza;
    private double profondita;

    public Parallelepipedo(double base, double altezza, double profondita) {
        this.base = base;
        this.altezza = altezza;
        this.profondita = profondita;
    }

    public double calcolaVolume() {
        return base * altezza * profondita;
    }

    public void stampaVolume() {
        System.out.println("Volume del parallelepipedo: " + calcolaVolume());
    }
}