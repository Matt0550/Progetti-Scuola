/*
    COMPITO DI INFORMATICA
        MATTEO SILLITTI
          04.11.2022
            4C INF
*/

/*
Java:
Java è un linguaggio ad oggetti molto sicuro e robusto perché viene eseguto
su una JVM ovvero una macchina virtuale. Grazie a questa JVM, il codice
java è estremamente compatibile con varie piattaforme e non necessita
di essere ricompilato per essere eseguito.
Uno degli aspetti negativi di Java è la lentezza nell'esecuzione del codice
proprio perché viene eseguito su questa macchina virtuale
*/

// Creiamo la classe Main. Il nome è vincolato al nome del file ed è buona abitudine scriverlo
// con la prima lettera maiuscola
public class Main {
  // Creiamo il metodo main ovvero quella parte di codice che si avvierà di predefinito quando avviamo il programma
  // di metodi main se ne possono creare solo uno
	public static void main(String[] args) {
    // Scriviamo String[] args in modo che quando avviamo il codice da terminale
    // sarà possibile passargli degli argomenti che ci ritroveremo in questo array

    // Creiamo un nuovo oggetto di tipo Libro ed inizializziamo il costruttore
    Libro libro1 = new Libro("brossura", 50, "Test", 500);

    // Richiamiamo il metodo stampaLibro.
    libro1.stampaLibro();
	}
}