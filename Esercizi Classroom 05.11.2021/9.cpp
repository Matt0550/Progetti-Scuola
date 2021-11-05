/*
Website: https://matt05.ml
GitHub: @Matt0550
9. Dati N numeri contare quanti sono i valori pari e quelli dispari.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;
    int numeri = 0;
    int pari = 0;
    int dispari = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        if(n%2==0) {
            pari++;
        } else {
            dispari++;
        }

        i++;
    }
    cout<<"\nCi sono:"<<endl;
    cout<<pari<<" numeri pari"<<endl;
    cout<<dispari<<" numeri dispari"<<endl;

    
    cout<<"Uscita...";
    return 0;
}
