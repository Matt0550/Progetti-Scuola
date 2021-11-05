/*
Website: https://matt05.ml
GitHub: @Matt0550
10. Dati N numeri contare quanti sono i multipli di 3.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;
    int numeri = 0;
    int multipli = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        if(n%3 == 0) {
            multipli++;
        }

        i++;
    }
    cout<<"\nCi sono:"<<endl;
    cout<<multipli<<" multipli di 3"<<endl;

    
    cout<<"Uscita...";
    return 0;
}
