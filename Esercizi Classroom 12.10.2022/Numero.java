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

    public double incrementa() {
        return numero++;
    }

    public double decrementa() {
        return numero--;
    }

    public String equazione(double a, double b, double c) {
        double delta;
        double sol1, sol2;

        delta=b*b-4*a*c;

        if( delta==0 ) {
            sol1=(-b - Math.sqrt( b*b -4*a*c ))/(2*a);
            sol2=sol1;
            return "Soluzioni coincidenti: " + sol1;
        }

        if( delta>0 ) {
            sol1=(-b - Math.sqrt( b*b -4*a*c ))/(2*a);
            sol2=(-b + Math.sqrt( b*b -4*a*c ))/(2*a);
            return "Soluzioni reali: " + sol1 + " " + sol2;
        }

        if( delta<0 ) {
            return "Delta negativo";
        }
        return "Errore";
    }

}