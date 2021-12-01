/*
Website: https://matt05.ml
GitHub: @Matt0550
13. Determinare quanti numeri multipli di K sono compresi nell'intervallo [A..B] (estremi compresi).
*/

#include <iostream>

using namespace std;

int main()
{
    int k, a, b;
    int multipli = 0;
    int tot_multipli = 0;
    
    cout<<"Inserisci K per determinare i multipli: ";
    cin>>k;
    
    cout<<"Inserisci l'intervallo A: ";
    cin>>a;
    
    cout<<"Inserisci l'intervallo B: ";
    cin>>b;
    
    
    for(int i = 1; multipli <= b; i++) {
        if(multipli >= a) {
            tot_multipli++;
        }
        multipli = k*i;
    }
    cout<<"Nel range tra "<<a<<" e "<<b<<", ci sono "<<tot_multipli<<" multipli";
    return 0;
}