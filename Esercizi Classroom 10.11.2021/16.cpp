/*
Website: https://matt05.ml
GitHub: @Matt0550
16. Dati N numeri calcolare la media aritmetica.
*/

#include <iostream>

using namespace std;

int main()
{
    double n = 0;
    double numeri = 0;
    int i = 1;
    double media = 0;
    double media_tot = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        media = media + n;
        media_tot = media/numeri;

        i++;
    }
    
    cout<<endl<<"La media è: "<<media_tot<<endl;

    cout<<"Uscita...";
    return 0;
}
