/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Trovare il massimo tra due numeri tramite puntatori
*/
#include <iostream>

using namespace std;

int max(int *a, int *b) {
    if(*a > *b) {
        return *a;
    } else {
        return *b;
    }
}

int main()
{
    int n1 = 10;
    int n2 = 20;
    cout<<max(n1, n2);
    
    return 0;
}