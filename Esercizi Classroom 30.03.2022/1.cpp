/*
Website: https://matt05.ml
GitHub: @Matt0550

1. Creare una funzione che calcola il cubo di un numero.
*/
#include <iostream>

using namespace std;

int calcoloCubo(int n) {
    return n*n*n;
}

int main()
{
    int risultato = calcoloCubo(26);
    cout<<"Il cubo è: "<<risultato;

    return 0;
}