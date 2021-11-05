/*
Website: https://matt05.ml
GitHub: @Matt0550
1. Stampare i primi N numeri interi.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 0;
    cout<<"Inserisci un numero intero: ";
    cin>>n;
    
    while(i <= n) {
        cout<<i<<endl;
        i++;
    }

    return 0;
}
