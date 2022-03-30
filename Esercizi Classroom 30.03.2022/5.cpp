/*
Website: https://matt05.ml
GitHub: @Matt0550

5. Creare un programma che dato un carattere in ingresso verifica se è maiuscolo (Suggerimento: controllare la tabella ASCII)
*/
#include <iostream>

using namespace std;

bool verificaCarattere(char lettera) {
    return (lettera >= 'A' && lettera<= 'Z') ? true : false;
}

int main()
{
    int risultato = verificaCarattere('V');
    if(risultato == 1) {
        cout<<"Il carattere è maiuscolo.";
    } else {
        cout<<"Il carattere è minuscolo.";
    }
    return 0;
}