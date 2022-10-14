import java.lang.Math;

public class Numero {
    private double numero;

    public Numero(double numero) {
        this.numero = numero;
    }

    public double getNumero() {
        return numero;
    }

    public void setNumero(double n) {
        numero = n;
    }

    public double getQuadrato() {
        return numero*numero;
    }

    public double getRadice() {
        return Math.sqrt(numero);
    }

    public int getFattoriale() {
        int fattoriale = 1;
        for(int i = 1; i <= numero; i++) {
            fattoriale*=i;
        }
        return fattoriale;
    }

    public double getNegativo() {
        return numero*-1;
    }

    public String toBinary() {
        return Integer.toBinaryString((int)numero);
    }

    public String toHex() {
        return Integer.toHexString((int)numero);
    }

}