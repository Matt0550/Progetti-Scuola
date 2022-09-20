/*
Website: https://matt05.ml
GitHub: @Matt0550
3.Scrivere un programma che stampi le tabellina del numero dato come argomento
*/

import java.util.Scanner;

public class Esercizio3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Inserisci un numero:");
		
		Integer num = scanner.nextInt();
		scanner.close();
		
		for (int i = 1; i <= 10; i++) {
			System.out.println(num*i);
		
		}

	}

}
