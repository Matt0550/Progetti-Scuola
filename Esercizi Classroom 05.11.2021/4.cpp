/*
Website: https://matt05.ml
GitHub: @Matt0550
4. Stampare multipli di A minori di N.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;
    int a = 0;
    
    cout<<"Inserisci un numero intero (N): ";
    cin>>n;
    
    cout<<"Inserisci un numero intero (A): ";
    cin>>a;


    while(a*i < n && a>0) {
        int prodotto = a*i;
        cout<<prodotto<<endl;
        i++;     
    }
    
    cout<<"Uscita...";
    return 0;
}
