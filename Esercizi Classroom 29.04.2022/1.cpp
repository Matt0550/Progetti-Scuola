/*
Website: https://matt05.ml
GitHub: @Matt0550
1. Implementare una funzione per determinare se un triangolo è equilatero, isoscele o scaleno.
*/

#include <iostream>

using namespace std;

string determina_triangolo(int a, int b, int c) {
    if (a == b && b == c)
		return "equilatero";
	else if (a == b || b == c || a == c)
		return "isoscele";
	else
		return "scaleno";
}

int main()
{
    cout<<"Il triangolo è "<<determina_triangolo(1,2,3);

    return 0;
}