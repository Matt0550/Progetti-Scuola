/**
 * Implementare la classe math con l’overloading dei seguenti metodi: somma, sottrazione, divisione, moltiplicazione e radice di una somma e altri metodi a piacere
 */

// Include math library
import java.lang.Math;

public class Math2 {
    public static int somma(int a, int b) {
        return a + b;
    }
    public static int somma(int a, int b, int c) {
        return a + b + c;
    }
    public static int somma(int a, int b, int c, int d) {
        return a + b + c + d;
    }

    public static int sottrazione(int a, int b) {
        return a - b;
    }
    public static int sottrazione(int a, int b, int c) {
        return a - b - c;
    }
    public static int sottrazione(int a, int b, int c, int d) {
        return a - b - c - d;
    }
    
    public static int divisione(int a, int b) {
        return a / b;
    }
    public static int divisione(int a, int b, int c) {
        return a / b / c;
    }
    public static int divisione(int a, int b, int c, int d) {
        return a / b / c / d;
    }

    public static int moltiplicazione(int a, int b) {
        return a * b;
    }
    public static int moltiplicazione(int a, int b, int c) {
        return a * b * c;
    }
    public static int moltiplicazione(int a, int b, int c, int d) {
        return a * b * c * d;
    }

    public static int radiceDiUnaSomma(int a, int b) {
        return (int) Math.sqrt(a + b);
    }
    public static int radiceDiUnaSomma(int a, int b, int c) {
        return (int) Math.sqrt(a + b + c);
    }
    public static int radiceDiUnaSomma(int a, int b, int c, int d) {
        return (int) Math.sqrt(a + b + c + d);
    }
}