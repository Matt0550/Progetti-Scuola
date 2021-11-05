/*
Website: https://matt05.ml
GitHub: @Matt0550
11. Dati N numeri contare quanti sono i multipli di A.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;
    int numeri = 0;
    int multipli = 0;
    int a = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;
    
    cout<<"Inserisci il multiplo da verificare: ";
    cin>>a;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        if(n%a == 0) {
            multipli++;
        }

        i++;
    }
    cout<<"\nCi sono:"<<endl;
    cout<<multipli<<" multipli di "<<a<<endl;

    
    cout<<"Uscita...";
    return 0;
}
