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
    int i = 1;
    int a = 0;
    
    cout<<"Inserisci un numero intero (N): ";
    cin>>n;
    
    cout<<"Inserisci un numero intero (A): ";
    cin>>a;

    while(i < n && a>0) {
        cout<<a*i<<endl;
        i++;     
    }
    
    cout<<"Uscita...";
    return 0;
}
