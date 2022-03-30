/*
Website: https://matt05.ml
GitHub: @Matt0550

7. Creare una funzione che restituisce se un numero intero è naturale o meno
*/
#include <iostream>

using namespace std;

bool verificaNumeroNaturale(int n) {
    return (n>0) ? true : false;
}

int main()
{
    int risultato = verificaNumeroNaturale(4);
    if(risultato == 1) {
        cout<<"Il numero è naturale.";
    } else {
        cout<<"Il numero non è naturale.";
    }
    return 0;
}