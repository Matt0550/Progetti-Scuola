/*
Website: https://matt05.ml
GitHub: @Matt0550

4. Inserito il prezzo in Kg e il peso delle mele acquistate, calcola e visualizza il totale da pagare.
*/

#include <iostream>

using namespace std;

int main()
{
    int costo, peso;
    cout<<"Inserisci il costo in kg ";
    cin>>costo;
    
    cout<<"Inserisci il peso delle mele acquistate ";
    cin>>peso;
    
    int totale = costo * peso;
    
    cout<<"Il totale da pagare è di " << totale << "€";


    return 0;
}
