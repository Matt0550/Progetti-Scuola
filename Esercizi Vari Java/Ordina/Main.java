/*
Implementare la classe Ordine, per la gestione degli ordini di un ristorante.
L'ordine è caratterizzato dal numero di tavolo, dal nome del cliente, dal numero di coperti (persone) e dal totale da pagare.

La classe deve possedere i seguenti metodi:
- getTavolo
- getNomeCliente
- getNumeroPersone
- getTotale

- setTavolo
- setNomeCliente
- setNumeroPersone
- setTotale

- stampaOrdine
*/

public class Main {
    public static void main(String[] args) {
        // Creiamo l'oggetto di tipo Ordine
        Ordine ordine1 = new Ordine(10, "Luigi", 5, 430);
        // Stampiamo l'ordine
        ordine1.stampaOrdine();

        // Modifichiamo il nome del cliente
        ordine1.setNomeCliente("Alessandro");
        ordine1.setNumeroPersone(10);

        ordine1.stampaOrdine();
    }
}
