/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Inserendo 10 numeri interi, calcola quanti numeri pari sono stati inseriti
*/

#include <iostream>

using namespace std;

int main()
{
    int numeri[10] = {};
    int numeri_len = sizeof(numeri)/sizeof(numeri[0]);
    int pari = 0;
    int dispari = 0;
    for(int i = 0; i< numeri_len; i++){
        cout << to_string(i+1) + ". Inserire 10 numeri interi (premi invio ad ogni numero): ";
        cin>>numeri[i];
        if (numeri[i]%2 == 0) {
            pari++;
        } else {
            dispari++;
        }
    }
    
    cout<<"I numeri pari sono: "<<pari<<"\nI numeri dispari sono: "<<dispari;
    
    
    return 0;
}