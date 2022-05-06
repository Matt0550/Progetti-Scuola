/*
Website: https://matt05.ml
GitHub: @Matt0550
1. Sottrarre due variabili tramite puntatori
*/
#include <iostream>

using namespace std;

int main()
{
    int n1 = 10;
    int n2 = 15;
    int *a = &n1;
    int *b = &n2;
    int sottrazione = *a - *b;

    cout<<sottrazione;
    return 0;
}