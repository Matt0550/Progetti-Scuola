/*
Website: https://matt05.ml
GitHub: @Matt0550
3. Stampare i numeri pari minori di N in ordine decrescente.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout<<"Inserisci un numero intero: ";
    cin>>n;

    for(int i = n; i >= 0; i--) {
        if (i%2 == 0) {
            cout<<i<<endl;
        }
    }

    return 0;
}