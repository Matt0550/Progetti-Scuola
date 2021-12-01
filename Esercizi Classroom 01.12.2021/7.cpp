/*
Website: https://matt05.ml
GitHub: @Matt0550
7. Calcolare la somma dei primi N numeri naturali.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int somma = 0;

    cout<<"Inserisci un numero intero (N): ";
    cin>>n;


    for(int i = 1; i <= n; i++) {
        somma = somma + i;
    }
    cout<<somma<<endl;
    
    cout<<"Uscita...";
    return 0;
}