/*
Website: https://matt05.ml
GitHub: @Matt0550

3. Dati in input la base e l'altezza di un rettangolo calcola l'area e visualizza il risultato.
*/

#include <iostream>

using namespace std;

int main()
{
    int base, altezza;
    cout<<"Inserisci la base ";
    cin>>base;
    
    cout<<"Inserisci l'altezza ";
    cin>>altezza;
    
    int area = base * altezza;
    
    cout<<"L'area del rettangolo è uguale a " << area;


    return 0;
}
