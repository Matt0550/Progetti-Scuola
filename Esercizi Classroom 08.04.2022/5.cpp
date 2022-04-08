/*
Website: https://matt05.ml
GitHub: @Matt0550
5. Definite 3 variabili sulla funzione main, ordinarle in ordine crescente tramite una funzione esterna.
*/
#include <iostream>

using namespace std;

int ordinaNumeri(int &n1, int &n2, int &n3) {
    int tmp;
    if (n1>n2) {
        // Swap tra n1 e n2
        tmp = n1;
        n1=n2;
        n2=tmp;
    }
    if (n1>n3) {
        // Swap tra n1 e n3
        tmp = n1;
        n1=n3;
        n3=tmp;
    }
    if (n2>n3) {
        // Swap tra n2 e n3
        tmp = n2;
        n2=n3;
        n3=tmp;
    }
    return 1;

}

int main()
{
    int n1, n2, n3;
    cout<<"Inserisci il primo numero: ";
    cin>>n1;
    
    cout<<"Inserisci il secondo numero: ";
    cin>>n2;
    
    cout<<"Inserisci il terzo numero: ";
    cin>>n3;
    
    ordinaNumeri(n1, n2, n3);
    
    cout<<n1<<" - "<<n2<<" - "<<n3;
}