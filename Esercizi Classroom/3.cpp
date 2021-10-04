/*
Website: https://matt05.ml
GitHub: @Matt0550
20. Calcolare il quadrato del successivo del doppio di un numero.
*/

#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Inserire un valore ";
    cin >> a;
    int b = a*2+1;
    int totale = b*b;

    cout << "Il quadrato del successivo del doppio del numero è " << totale;
    return 0;
}