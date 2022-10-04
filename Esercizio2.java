/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Costruire un vettore di N posizioni, inserendo in ogni elemento il valore del suo indice. 
*/

import java.util.Scanner;
public class Esercizio2 {
	public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);
	    System.out.println("Inserire il numero di elementi dell'array:");
		int num = scanner.nextInt();
	    scanner.close();

		int arr[] = new int[num];
		
		for(var i = 0; i < num; i++) {
		    arr[i] = i;
		}
		
		System.out.println("Contenuto dell'array:");
		
		for(var i = 0; i < arr.length; i++) {
		    System.out.println(arr[i]);
		}
	}
}
