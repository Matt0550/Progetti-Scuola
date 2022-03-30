/*
Website: https://matt05.ml
GitHub: @Matt0550

8. Creare una funzione che restituisce se un numero intero ha almeno 3 divisori.
*/
#include <iostream>

using namespace std;

bool verificaDivisori(int n) {
    int divisori = 0;
    for(int i = 1; i<=n; i++) {
        if(n%i == 0) {
            divisori++;
        }
    }
    return (divisori>3) ? true : false;
}

int main()
{
    int risultato = verificaDivisori(40);
    if(risultato == 1) {
        cout<<"Il numero ha almeno 3 divisori.";
    } else {
        cout<<"Il numero non ha almeno 3 divisori.";
    }
    return 0;
}