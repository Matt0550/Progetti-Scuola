package volume;

/**
 * Cilindro
 */
public class Cilindro extends Volume {
    private double raggio;
    private double altezza;

    public Cilindro(double raggio, double altezza) {
        this.raggio = raggio;
        this.altezza = altezza;
    }

    public double calcolaVolume() {
        return Math.PI * Math.pow(raggio, 2) * altezza;
    }

    public void stampaVolume() {
        System.out.println("Volume del cilindro: " + calcolaVolume());
    }

}