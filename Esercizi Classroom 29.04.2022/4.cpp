/*
Website: https://matt05.ml
GitHub: @Matt0550
4. Scrivere una funzione che calcoli la somma dei primi n numeri interi positivi utilizzando la ricorsione
*/

#include <iostream>

using namespace std;

int somma(int n) {
    if (n == 0) {
		return n;
	}
	return n + somma(n-1);
}

int main()
{
    cout<<"5: "<<somma(5);

    return 0;
}