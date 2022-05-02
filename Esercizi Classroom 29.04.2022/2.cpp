/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Calcola l'elevamento a potenza utilizzando le funzioni.
*/

#include <iostream>

using namespace std;

double potenza(double base, int esp) {
    int risultato = 1;
	for (int i = 0; i < esp; i++) {
		risultato *= base;
	}
	return risultato;
}

int main()
{
    cout<<"La potenza è "<<potenza(5, 2);

    return 0;
}