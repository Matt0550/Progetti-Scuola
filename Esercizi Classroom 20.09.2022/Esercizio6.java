/*
Website: https://matt05.ml
GitHub: @Matt0550
6.
Stampare a video la seguente figura:
1      654321
12      54321
123      4321
1234      321
12345      21
123456      1
*/

public class Esercizio6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int i = 1; i <= 6; i++) {
			for (int x = 1; x <= i; x++) {
				System.out.print(x);

			}
			System.out.print("   ");
			for (int y = 6; y >= i; y--) {
				System.out.print(y - i + 1);
			}
			
			
			System.out.println("");
			
		}
	}

}
