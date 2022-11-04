/*
    COMPITO DI INFORMATICA
        MATTEO SILLITTI
          04.11.2022
            4C INF
*/

// Creiamo la classe Libro
public class Libro {
    // Creiamo gli attributi che la classe deve possedere
    private String tipologiaLibro;
    private int numeroPagine;
    private String nomeLibro;
    private int totParole;

    // Utilizziamo il privare in modo da non rendere accessibile all'esterno la variabile
    // in questo modo evitiamo che qualcno modifichi senza il nostro consenso il valore della variabile
    // Oltre il private esiste anche il public per renderla accessibile ovunque
    // oppure il protected per rendere accessibile solo per le classi della stessa libreria (file)

    // Dichiariamo il costruttore dell'oggetto in modo tale da passargli dei parametri accessibili solo
    // dallo stesso oggetto. Il costruttore si attiverà una sola volta quando lo creiamo
    Libro(String tipologiaLibro, int numeroPagine, String nomeLibro, int totParole) {
        // In questo caso, siccome è richiesta una verifica dei valori, per evitare una 
        // duplicazione di codice, creo i metodi che si occuperanno di impostare il valore
        // della variabile
        setTipologiaLibro(tipologiaLibro);
        setNumeroPagine(numeroPagine);
        setNomeLibro(nomeLibro);
        // Utilizzo this perché siccome le variabili si chiamano in modo uguale, devo specificare a Java
        // di prendere e modificare la variabile (attributo) dichiarato all'inizio del codice
        this.totParole = totParole;
    }

    // Creo un metodo per impostare la tipologia del libro.
    // Come parametro gli passo una stringa e verifico che sia
    // uguale o a brossura, o a rilegato o a formato digitale
    public boolean setTipologiaLibro(String tipologia) {
        if(tipologia.equals("brossura") || tipologia.equals("rilegato") || tipologia.equals("formato digitale")) {
            // Se corrisponde imposto il valore dell'attributo sul valore passato nella funzione
            // In questo caso siccome si chiamano le variabili in modo diverso posso omettere il this
            tipologiaLibro = tipologia;
            return true;
        } else {
            System.out.println("Tipologia non valida!");
            return false;
        }
    }

    // Creo un altro metodo set che ci permette di modificare una variabile
    // In Java utilizziamo spesso i metodi set e get. Il primo serve
    // per modificare il valore di un attributo, mentre il secondo server
    // per prendere o stampare a schermo il valore di una variabile
    public boolean setNumeroPagine(int nPagine) {
        if(nPagine >= 30 && nPagine <= 500) {
            numeroPagine = nPagine;
            return true;
        } else {
            System.out.println("Numero di pagine non valide!");
            return false;
        }
    }
    // Creo il metodo per impostare il nome del libro
    public void setNomeLibro(String nomeLibro) {
        this.nomeLibro = nomeLibro;
    }
    
    // Creo il metodo per il calcolo del numero di parole per pagina
    public int calcoloNumeroDiParolePerPagine(int nParole) {
        return nParole/numeroPagine;
    }
    // Creo il metodi get per prendere i valori delle variabili essendo private
    public String getTipologiaLibro() {
        return tipologiaLibro;
    }

    public int getNumeroPagine() {
        return numeroPagine;
    }

    public String getNomeLibro() {
        return nomeLibro;
    }

    // Creo il metodo per la stampa a schermo.
    public void stampaLibro() {
        System.out.println("Nome del libro: " + getNomeLibro());
        System.out.println("Tipologia del libro: " + getTipologiaLibro());
        System.out.println("Pagine del libro: " + getNumeroPagine());
        System.out.println("Parole per pagina: " + calcoloNumeroDiParolePerPagine(totParole));
    }
}