/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Stampare i numeri pari minori di N.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout<<"Inserisci un numero intero: ";
    cin>>n;
    
    for(int i = 1; i <= n; i++) {
        if (i%2 == 0) {
            cout<<i<<endl;
        }
    }

    return 0;
}