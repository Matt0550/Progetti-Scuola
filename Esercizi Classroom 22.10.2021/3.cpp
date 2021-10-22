/*
Website: https://matt05.ml
GitHub: @Matt0550
3. Eleva un numero intero per un esponente inserito da tastiera
*/

#include <iostream>

using namespace std;

int main()
{
    int numero, potenza;
    int tot = 1;
    cout<<"Inserisci un numero intero: ";
    cin>>numero;
    
    cout<<"Inserisci l'esponente: ";
    cin>>potenza;
    
    for(int i = 0; i < potenza; i++) {
        tot = tot*numero;
    }

    cout<<"Il totale è: " << tot;
    
    return 0;
}