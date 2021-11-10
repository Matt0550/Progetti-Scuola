/*
Website: https://matt05.ml
GitHub: @Matt0550
17. Dati N numeri calcolare la media aritmetica dei valori pari e quella dei valori dispari.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int numeri = 0;
    int i = 1;
    int media_pari = 0;
    int media_dispari = 0;
    int media_pari_tot = 0;
    int media_dispari_tot = 0;
    int numeri_pari = 0;
    int numeri_dispari = 0;


    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        if(n%2==0) {
            numeri_pari++;
            media_pari = media_pari + n;
            media_pari_tot = media_pari/numeri_pari;
        } else {
            numeri_dispari++;
            media_dispari = media_dispari + n;
            media_dispari_tot = media_dispari/numeri_dispari;
        }

        i++;
    }
    
    cout<<endl<<"La media dei numeri pari è: "<<media_pari_tot;
    cout<<endl<<"La media dei numeri dispari è: "<<media_dispari_tot<<endl;

    cout<<"Uscita...";
    return 0;
}
