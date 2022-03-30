/*
Website: https://matt05.ml
GitHub: @Matt0550

9. Creare una funzione che dice se un carattere è una vocale.
*/
#include <iostream>

using namespace std;

bool verificaVocali(char lettera) {
    return (lettera == 'A' || lettera == 'E' || lettera == 'I' || lettera == 'O' || lettera == 'U') ? true : false;
}

int main()
{
    int risultato = verificaVocali('A');
    if(risultato == 1) {
        cout<<"Il carattere è una vocale.";
    } else {
        cout<<"Il carattere non è una vocale";
    }
    return 0;
}