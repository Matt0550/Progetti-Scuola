public class Calcio extends Sport {
    public Calcio(int numGiocatori) {
        super(numGiocatori);
        // Come detto in precedenza, tramite super richiamo il costruttore passandogli
        // come parametri il numero di giocatori.
    }

    public void gioca() {
        System.out.println("Stai giocando a calcio con " + super.numGiocatori + " giocatori!");
        // Stampo a schermo la frase concatenandola al numero dei giocatori che vado a prendere 
        // dalla classe genitore 
    }
    // Tramite la tecnica dell'overloading, realizzo due metodi che hanno lo stesso nome,
    // ma hanno parametri formali diversi. Infatti, su Java, è possibile creare più metodi con lo stesso nome
    // ma devono obbligatoriamente possedere dei parametri diversi. In questo caso, se è presente il parameteo campoZ,
    // verrà stamapato a schermo un testo, mentre se non c'è ne verrà stamapato uno diverso
    public String toString(int squadraX, int squadraY) {
        System.out.println("La squadra " + squadraX + " e la squadra " + squadraY + " stanno giocando la partita");
    }

    public String toString(int squadraX, int squadraY, int campoZ) {
        System.out.println("La squadra " + squadraX + " e la squadra " + squadraY + " stanno giocando la partita nel campo " + campoZ);
    }

}