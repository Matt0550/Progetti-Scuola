/*
Website: https://matt05.ml
GitHub: @Matt0550
1. Dato un numero intero N, stabilire se è pari o dispari.
*/

#include <iostream>

using namespace std;

string calcolo_pari_dispari(int numero) { // Funzione per determinare se il numero è pari o dispari
    if (numero%2 == 0) {
        return "pari";
    } else {
        return "dispari";
    }
}

int main()
{
    int N;

    cout << "Inserire un numero intero ";
    cin >> N;

    cout << "Il numero è " << calcolo_pari_dispari(N);
    return 0;
}