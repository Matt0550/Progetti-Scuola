/*
Website: https://matt05.ml
GitHub: @Matt0550

2. Creare una funzione che calcola e restituisce il valore assoluto di un numero intero.
*/
#include <iostream>

using namespace std;

int valoreAssoluto(int n) {
    return (n<0) ? -1*n : n;
}

int main()
{
    int risultato = valoreAssoluto(26);
    cout<<"Il valore assoluto è: "<<risultato;

    return 0;
}