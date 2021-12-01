/*
Website: https://matt05.ml
GitHub: @Matt0550
14. Dati N numeri stampare la somma di quelli pari e di quelli dispari.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int numeri = 0;
    int pari = 0;
    int dispari = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    for(int i = 1; i <= numeri; i++) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        if(n%2 == 0) {
            pari+=n;
        } else {
            dispari+=n;
        }
    }
    
    cout<<endl<<"La somma dei numeri pari è: "<<pari<<endl;
    cout<<"La somma dei numeri dispari è: "<<dispari<<endl;
    
    cout<<"Uscita...";
    return 0;
}