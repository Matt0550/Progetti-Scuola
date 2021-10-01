/*
Website: https://matt05.ml
GitHub: @Matt0550

5. Conoscendo il prezzo di un
oggetto (prezzo) e i soldi a disposizione nel
portafoglio, determinare se è possibile acquistare o no l'oggetto. Inoltre, se è
possibile, verificare see quanti soldi rimangono nel portafoglio dopo l'acquisto.
*/

#include <iostream>

using namespace std;

int main()
{
    int prezzo, soldi;
    cout<<"Inserisci il costo dell'oggetto ";
    cin>>prezzo;
    cout<<"Inserisci il totale dei tuoi soldi ";
    cin>>soldi;
    
    int portafoglio = soldi-prezzo;
    if (prezzo < soldi) {
        cout<<"Acquisto riuscito, ti rimangono " << portafoglio << "€";
    } else {
        cout<<"Non hai abbastanza soldi per acquistare quell'oggetto. Nel tuo portafoglio ci sono " << soldi << "€";

    }
    return 0;
}
