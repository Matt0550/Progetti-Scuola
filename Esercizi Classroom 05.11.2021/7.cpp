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
    int i = 1;
    int somma = 0;

    cout<<"Inserisci un numero intero (N): ";
    cin>>n;


    while(i <= n) {
        somma = somma + i;
        i++;
    }
    cout<<somma<<endl;
    
    cout<<"Uscita...";
    return 0;
}
