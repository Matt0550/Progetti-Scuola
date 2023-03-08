public class Main {

    public static void main(String[] args) {
        Calcio calcio = new Calcio(10);
        calcio.gioca();
        calcio.toString(1, 2, 1);

        // Creo l'oggetto calcio che a sua volta richiama la classe genitore Sport

        Basket basket = new Basket(8);
        basket.gioca();
        
    }
}