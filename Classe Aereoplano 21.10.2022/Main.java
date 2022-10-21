/*
Implementare la classe aeroplano con i seguenti attributi: velocità massima, velocità di crociera, nome aereo,numero di motori. Implementare il metodo info
*/

public class Main {
	public static void main(String[] args) {
		Aereoplano easyJet = new Aereoplano(567, 250, 2, "EasyJet");
		System.out.println(easyJet.getAllInfo());
	    
	}
}