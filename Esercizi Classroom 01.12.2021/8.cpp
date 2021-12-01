/*
Website: https://matt05.ml
GitHub: @Matt0550
8. Dati N numeri effettuarne la somma.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int numeri = 0;
    int somma = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    for(int i = 1; i <= numeri; i++) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        somma = somma + n;
    }
    
    cout<<somma<<endl;
    
    cout<<"Uscita...";
    return 0;
}