public class Main {
    public static void main(String[] args) {
        Palazzo palazzo1 = new Palazzo(5, 150, "Via Roma", 15, "Roma");
        Palazzo palazzo2 = new Palazzo(10, 100, "Via Milano", 20, "Milano");
        Palazzo palazzo3 = new Palazzo(7, 90, "Via Napoli", 25, "Napoli");
        palazzo1.stampa();
        palazzo2.stampa();
        palazzo3.stampa();
    }
}