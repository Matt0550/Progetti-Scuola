/*
Website: https://matt05.ml
GitHub: @Matt0550
1. Somma 10 numeri interi e comunica la somma quando viene inserito lo 0
*/

#include <iostream>

using namespace std;

int main()
{
    int numeri[10] = {};
    int numeri_len = sizeof(numeri)/sizeof(numeri[0]);
    
    for(int i = 0; i< numeri_len; i++){
        cout << to_string(i+1) + ". Inserire 10 numeri interi (premi invio ad ogni numero): ";
        cin>>numeri[i];
        if (numeri[i] == 0) {
            break;
        }
    }
    
    int somma = 0;
    for(int i = 0; i < numeri_len; i++){
        somma+=numeri[i];
    }
    cout<<"La somma è uguale a: "<<somma;
    
    
    return 0;
}