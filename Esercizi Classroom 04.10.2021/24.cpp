/*
Website: https://matt05.ml
GitHub: @Matt0550
24. Una merce subisce un certo aumento in percentuale. Il negoziante però pratica ai
clienti abituali uno sconto pari all'aumento. Calcolate la differenza tra il nuovo prezzo
scontato e il vecchio prezzo.
*/

#include <iostream>

using namespace std;

int main()
{
    int prezzo;
    int sconto;
    cout << "Inserire una percentuale di sconto ";
    cin >> sconto;
    
    cout << "Inserire il prezzo non scontato ";
    cin >> prezzo;
    
    double totale = (prezzo+(prezzo/100)*sconto)-(prezzo-(prezzo/100)*sconto);

    cout << "La differenza è di " << totale << "€";
    return 0;
}