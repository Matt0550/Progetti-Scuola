/*
Website: https://matt05.ml
GitHub: @Matt0550
3. Implementare la funzione swap passandogli i valori tramite puntatori.
*/
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int n1 = 10;
    int n2 = 20;
    swap(n1, n2);
    cout<<n1<<endl<<n2;
    return 0;
}