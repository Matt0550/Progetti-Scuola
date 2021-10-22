/*
Website: https://matt05.ml
GitHub: @Matt0550
5. Calcola il fattoriale di un numero
*/

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero intero: ";
    cin>>N;
    
    int tot = N;
    for (int i = 1; i < N; i++) {
        tot = tot * (N-i);
    }
    
    cout<<tot;
    return 0;
}
