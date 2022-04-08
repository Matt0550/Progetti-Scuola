/*
Website: https://matt05.ml
GitHub: @Matt0550
6.Creare una funzione che riceve tre numeri interi e restituisce la differenza tra il più grande e il più piccolo.
*/
#include <iostream>

using namespace std;

int differenzaNumeri(int n1, int n2, int n3) {
    int numeri[3] = {n1, n2, n3};
    int maggiore = numeri[0];
    int minore = numeri[0];
    for(int i = 1; i < 3; i++){
        if(numeri[i] > maggiore) maggiore = numeri[i];
        if(numeri[i] < minore) minore = numeri[i];
    }
    return maggiore-minore;
}

int main()
{
    int risultato = differenzaNumeri(5, 10, 20);
    cout<<"La differenza tra il più grande e il più piccolo è: "<<risultato;
    return 0;
}
