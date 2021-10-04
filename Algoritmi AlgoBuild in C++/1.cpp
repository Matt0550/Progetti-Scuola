/*
Website: https://matt05.ml
GitHub: @Matt0550

1. Dati due numeri in input e assegnati alle variabili A e B calcola il prodotto dei due 
numeri e assegnalo alla variabile C. Visualizza il contenuto della variabile C.
*/

#include <iostream>

using namespace std;

int main()
{
    int a;
    cout<<"Inserisci il primo numero ";
    cin>>a;
    
    int b;
    cout<<"Inserisci il secondo numero ";
    cin>>b;
    
    cout<<"La moltiplicazione è uguale a ";
    int somma = a*b;
    cout<<somma;

    return 0;
}
