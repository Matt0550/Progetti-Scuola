/*
Website: https://matt05.ml
GitHub: @Matt0550
3. Caricare un vettore di N posizioni, stampando la somma dei suoi elementi. 
*/

import java.util.Scanner;
public class Esercizio3 {
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
		
		int somma = 0;
		for(var i = 0; i < arr.length; i++) {
		    somma += arr[i];
		}
		
        System.out.println(somma);
	}
}