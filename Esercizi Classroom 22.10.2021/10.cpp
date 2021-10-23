/*
Website: https://matt05.ml
GitHub: @Matt0550
10. Restituisce il maggiore e il minore di una serie di numeri inseriti da tastiera
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
    }
    
    int max = 0;
    int min;
    for(int i = 0; i < numeri_len; i++){
        if (numeri[i] > max) {
            max=numeri[i];
        }
        if (numeri[i] < min) {
            min=numeri[i];
        }
        
    }
    cout<<"\nIl numero più grande è: " << max<<endl;
    cout<<"Il numero più piccolo è: " << min<<endl;
    
    
    return 0;
}