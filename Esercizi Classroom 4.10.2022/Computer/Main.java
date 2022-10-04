/*
Website: https://matt05.ml
GitHub: @Matt0550
5. Implementare una classe che rappresenti le caratteristiche e le funzionalità di un computer.
Di questa classe implementare due metodi, uno che stampi le caratteristiche dell'oggetto e l'altro per il potenziamento della RAM: 
dato in ingresso il numero di Gigabyte aggiuntivi ne registri l'incremento sull'oggetto. Implementare, inoltre, all'interno del metodo main più oggetti,
cioè più computer con caratteristiche diverse e per ogni caso richiamare i metodi.
*/

public class Main {
	public static void main(String[] args) {
		// Create a new Computer object
		Computer pc = new Computer("Intel Core i7-9700K", "MSI Z390-A PRO", "Noctua NH-D15", "Corsair RM850x", 16, 1500, 0, 1000);
		// Print the computer's specs
		pc.print();
		// Increase the RAM by 8GB
		pc.increaseRAM(8);
		// Print the computer's specs
		pc.print();

		// Create a new Computer object
		Computer pc2 = new Computer("AMD Ryzen 5 3600", "MSI B450M PRO-VDH MAX", "Noctua NH-U12S", "Corsair CX550M", 8, 0, 500, 600);
		// Print the computer's specs
		pc2.print();
		// Increase the hdd by 500GB
		pc2.increaseHDD(500);
		// Print the computer's specs
		pc2.print();
	}
}