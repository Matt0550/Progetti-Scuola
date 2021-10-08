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
