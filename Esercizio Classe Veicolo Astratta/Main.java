/**
 * Main
 * Creare una classe astratta chiamata "Veicolo" con i seguenti attributi: numero di ruote, velocità massima, colore. Includere i metodi getter e setter per ogni attributo e un metodo astratto chiamato "accelera()".

Creare una classe chiamata "Auto" che eredita da "Veicolo" e sovrascrive il metodo "accelera()" per stampare "L'auto sta accelerando."

Creare una classe chiamata "Bicicletta" che eredita da "Veicolo" e sovrascrive il metodo "accelera()" per stampare "La bicicletta sta pedalando più velocemente."

Creare una classe chiamata "Main" con un metodo "main" che crea istanze di "Auto" e "Bicicletta", imposta i loro attributi e chiama il metodo "accelera()" su ciascuno di essi.

Eseguire il programma e verificare che l'accelerazione stampata sia corretta per ogni veicolo.
 */
public class Main {
    public static void main(String[] args) {
        //Create an instance of Auto
        Auto auto = new Auto(4, 200, "Rosso");
        //Create an instance of Bicicletta
        Bicicletta bicicletta = new Bicicletta(2, 20, "Blu");
        //Call the accelerate method on the Auto instance
        auto.accelera();
        //Call the accelerate method on the Bicicletta instance
        bicicletta.accelera();
    }
    
}