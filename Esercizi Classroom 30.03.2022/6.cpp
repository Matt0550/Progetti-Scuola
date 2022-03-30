/*
Website: https://matt05.ml
GitHub: @Matt0550

6.Creare una funzione che riceve tre numeri interi e restituisce la differenza tra il più grande e il più piccolo.
*/
#include <iostream>
#include <cmath>

using namespace std;

int differenzaNumeri(int n1, int n2, int n3) {
    return max(max(n2, n3), n1) - min(min(n2, n3), n1);
}

int main()
{
    int risultato = differenzaNumeri(5, 10, 20);
    cout<<"La differenza tra il più grande e il più piccolo è: "<<risultato;
    return 0;
}