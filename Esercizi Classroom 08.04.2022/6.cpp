/*
Website: https://matt05.ml
GitHub: @Matt0550
6. Definite 3 variabili sulla funzione main, implementare una funzione che ne calcoli i valori assoluti tramite il passaggio di parametri per riferimento.
*/
#include <iostream>

using namespace std;

void valoriAssoluti(int &n1, int &n2, int &n3) {
    if(n1<0) n1*=-1;
    if(n2<0) n2*=-1;
    if(n3<0) n3*=-1;
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
    
    valoriAssoluti(n1, n2, n3);
    
    cout<<n1<<" - "<<n2<<" - "<<n3;
}
