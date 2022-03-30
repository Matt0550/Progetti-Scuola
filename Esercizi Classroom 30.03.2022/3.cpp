/*
Website: https://matt05.ml
GitHub: @Matt0550

3. Creare una funzione che riceve una quantità di tempo in formato ore, minuti e secondi e la restituisce espressa solamente in secondi.
*/
#include <iostream>

using namespace std;

int timeToSeconds(int ore, int minuti, int secondi) {
    ore *= 3600;
    minuti *= 60;
    return ore+minuti+secondi;
}

int main()
{
    int risultato = timeToSeconds(12, 34, 20);
    cout<<"Il tempo in secondi è: "<<risultato;

    return 0;
}