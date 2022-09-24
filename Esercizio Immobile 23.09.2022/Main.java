/*
Website: https://matt05.ml
GitHub: @Matt0550
Creare una classe immobile con i relativi attributi (come il numero di stanze) e con due metodi a vostra scelta. Implementare tre oggetti da esso.
*/

public class Main
{
	public static void main(String[] args) {
		Immobile immobile1 = new Immobile("trilocale", "Milano", "Via Roma, 115", 3, 1, 1, 300000);
		Immobile immobile2 = new Immobile("attico di lusso", "Milano", "Piazza del Duomo, 23", 12, 5, 7, 3500000);
		Immobile immobile3 = new Immobile("bilocale", "Catania", "Via Umberto I, 64", 2, 1, 1, 90000);

        System.out.println("---- ANNUNCI IMMOBILIARI ----");
	    immobile1.printData();
	    immobile2.printData();
	    immobile3.printData();
	}
}
