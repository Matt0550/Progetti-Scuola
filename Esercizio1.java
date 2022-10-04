/*
Website: https://matt05.ml
GitHub: @Matt0550
1. Costruire un vettore di N elementi con valori letti da tastiera e visualizzarli.
*/

import java.util.Scanner;
public class Esercizio1 {
	public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);
	    System.out.println("Quanti elementi vuoi inserire nell'array?");
		int num = scanner.nextInt();
		
		int arr[] = new int[num];
		
		for(var i = 0; i < num; i++) {
		    System.out.println(i + ") Inserisci un valore intero:");
		    arr[i] = scanner.nextInt();
		}
		
		scanner.close();
		
		System.out.println("Contenuto dell'array:");
		
		for(var i = 0; i < arr.length; i++) {
		    System.out.println(arr[i]);
		}
	}
}
