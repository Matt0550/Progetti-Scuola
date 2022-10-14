/*
Website: https://matt05.ml
GitHub: @Matt0550

Implementare la classe Numero che memorizzi un numero intero. La classe dovrà avere i seguenti metodi:
- quadrato, che restituisca il quadrato del numero;
- radice, che ne restituisca la radice;
- fattoriale, che ne restituisca il fattoriale, esempio: !5 = 5*4*3*2*1
- negazione, che inverta il segno di Numero
- binario ed esadecimale, che restituisca rispettivamente il corrispondente in binario ed esadecimale.
- Incrementa (di uno)
- Decrementa (di uno)
- Metodo che ritorna il calcolo della seguente formula x^2 + x + 1
*/

public class Main {
    public static void main(String[] args) {
        Numero num = new Numero(10);
        System.out.println("Fattoriale: " + num.getFattoriale());
        System.out.println("Negativo: " + num.getNegativo());
        System.out.println("Quadrato: " + num.getQuadrato());
        System.out.println("Radice: " + num.getRadice());
        System.out.println("Binario: " + num.toBinary());
        System.out.println("Esadecimale: " + num.toHex());
        System.out.println("Incrementa: " + num.incrementa());
        System.out.println("Decrementa: " + num.decrementa());
        System.out.println("Equazione: " + num.equazione(1, 4, 2));
    }   
}
