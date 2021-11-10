/*
Website: https://matt05.ml
GitHub: @Matt0550
18. Dati N numeri determinare il valore più piccolo tra quelli incontrati, indicandone il numero d'ordine.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int numeri = 0;
    int i = 1;
    int min;
    int num_ord = 0;
    
    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;

        if (n<min) {
            num_ord = i;
            min = n;
        }

        i++;
    }
    
    cout<<endl<<"Il numero più piccolo è: "<<min<<endl;
    cout<<"Il numero si trova alla posizione: "<<num_ord<<endl;

    cout<<"Uscita...";
    return 0;
}
