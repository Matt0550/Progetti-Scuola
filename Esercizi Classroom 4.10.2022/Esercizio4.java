/*
Website: https://matt05.ml
GitHub: @Matt0550
4. Dato un vettore di N elementi, determinare se ciascun elemento è pari o dispari.
*/

import java.util.Scanner;
public class Esercizio4 {
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
		    if(arr[i] %2 == 0) {
		        System.out.println(arr[i] + " - PARI");
		    } else {
		        System.out.println(arr[i] + " - DISPARI");
		    }
		}
	}
}