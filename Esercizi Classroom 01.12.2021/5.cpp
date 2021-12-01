/*
Website: https://matt05.ml
GitHub: @Matt0550
5. Stampare i primi N multipli di un numero.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int a = 0;
    
    cout<<"Inserisci un numero intero (N): ";
    cin>>n;
    
    cout<<"Inserisci un numero intero (A): ";
    cin>>a;

    for(int i = 1; i < n && a>0; i++) {
        cout<<a*i<<endl;
    }
    
    cout<<"Uscita...";
    return 0;
}