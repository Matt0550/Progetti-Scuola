/*
Website: https://matt05.ml
GitHub: @Matt0550
39. Dato un numero intero, trovare il suo valore assoluto.
*/

#include <iostream>

using namespace std;

int assoluto(int numero) { // Funzione per il calcolo del valore assoluto
    if (numero >=0) {
        return numero;
    } else {
        return -numero;
    }
}

int main()
{
    int intero;

    cout << "Inserire un numero intero ";
    cin >> intero;
    
    cout << "Il valore assoluto è " << assoluto(intero);
    return 0;
}

