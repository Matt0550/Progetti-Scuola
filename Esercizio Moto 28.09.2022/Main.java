/*
Implementare una classe moto con le seguenti caratteristiche:
- Cilindrata
- Marca
- Modello
- Colore
- Prezzo

Implementare il metodo stampa che stampa tutte le caratteristiche della moto
e il metodo per ricavare il prezzo in dollari
*/

public class Main
{
	public static void main(String[] args) {
	    Moto moto1 = new Moto(125, "Yamaha Motor", "123H", "rosso", 90000);
	    System.out.print(moto1.getAllData());
	    
	}
}
