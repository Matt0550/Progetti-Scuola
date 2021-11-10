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
    int i = 0;
    int tot_multipli = 0;
    
    cout<<"Inserisci K per determinare i multipli: ";
    cin>>k;
    
    cout<<"Inserisci l'intervallo A: ";
    cin>>a;
    
    cout<<"Inserisci l'intervallo B: ";
    cin>>b;
    
    
    while(multipli <= b) {
        if(multipli >= a) {
            tot_multipli++;
        }
        i++;
        multipli = k*i;
    }
    cout<<"Nel range tra "<<a<<" e "<<b<<", ci sono "<<tot_multipli<<" multipli";
    return 0;
}
