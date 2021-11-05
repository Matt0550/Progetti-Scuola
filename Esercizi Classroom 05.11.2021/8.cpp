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
    int i = 1;
    int somma = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        somma = somma + n;

        i++;
    }
    cout<<somma<<endl;
    
    cout<<"Uscita...";
    return 0;
}
