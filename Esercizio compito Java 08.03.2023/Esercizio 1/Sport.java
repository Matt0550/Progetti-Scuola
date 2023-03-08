/*
 Realizzo una classe astratta chiamata sport dove gli inserisco
 un attributo che verrà passato tramite il costruttore.
 Una classe astratta, permette di dichiarare un metodo senza doverlo
 implementare direttamente nella classe genitore, ma bisognerà obbligatoriamente
 implementarlo in una classe figlia.

 Le classi figlie sono delle classi che ereditano determinati attributi e metodi
 direttamente dalla classe genitore. In questo caso, la classe figlia Calcio, 
 avrà tutti i metodi e attributi della classe genitore Sport. Questi metodi e attributi
 possono essere ottenuti utilizando la keyword super.
 Se tale keyword è sola, significa che si sta inizializzando il costruttore della
 classe genitore (per esempio super("test", 2)).
 Se invece dopo super troviamo il nome di un metodo o attributo, stiamo richiamando
 l'attributo o metodo desiderato (per esempio super.gioca() o super.numGiocatori).
 */

public abstract class Sport {
    protected int numGiocatori;

    public Sport(int numGiocatori) {
        this.numGiocatori = numGiocatori;
    }

    public abstract void gioca(); // Creo un metodo astratto che implementerò nella classe figlia
    // Tale metodo dovrà per forza essere void visto che non ha nessuna implementazione.
}