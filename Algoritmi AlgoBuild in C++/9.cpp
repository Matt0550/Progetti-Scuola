/*
Website: https://matt05.ml
GitHub: @Matt0550

9. Realizziamo un algoritmo che permetta di calcolare la somma dei numeri inseriti
dalla tastiera fino a quando la somma sarà maggiore di 30.
*/

#include <iostream>

using namespace std;

int main()
{
    int somma = 0;

    while (somma <= 30) {
        int i;
        cout << "Inserisci un valore ";
        cin>>i;
        somma = i + somma;
        cout<<"Totale: "<<somma<<"\n";
    }
    cout<<"\nLa somma ha superato il numero 30";
    
    return 0;
}
