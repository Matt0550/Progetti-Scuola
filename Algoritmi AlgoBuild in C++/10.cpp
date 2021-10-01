/*
Website: https://matt05.ml
GitHub: @Matt0550

10. Realizzare un algoritmo che calcoli il totale degli incassi di un museo fino a quando
il valore inserito da tastiera sarà 99.
*/

#include <iostream>

using namespace std;

int main()
{
    int somma = 0;
    int i = 0;

    while (i!=99) {
        cout << "Inserisci un valore ";
        cin>>i;
        somma = i + somma;
        cout<<"Totale: "<<somma<<"\n";
    }
    cout<<"\nIl numero è uguale a 99";
    
    return 0;
}
