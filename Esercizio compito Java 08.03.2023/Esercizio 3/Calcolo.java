public class Calcolo {
    // Creo un metodo statico che consente di eseguire il cubo di un numero
    /*
     I metodi statici, sono quei metodi che possono essere richiamati da un'altra
     classe senza dover inizializzare in costruttore. 
     Per esempio se volessi richiamare il metodo cubo mi basta fare
     Calcolo (che è il nome della classe).cubo(2) (che è il nome del metodo statico)
     */
    public static double cubo(double numero) {
        // Mi calcolo il cubo del numero
        return numero*numero*numero;
    }
    
}