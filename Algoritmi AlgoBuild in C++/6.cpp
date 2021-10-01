/*
Website: https://matt05.ml
GitHub: @Matt0550

6. Un'agenzia noleggia auto ai propri clienti a 30€ al giorno. Sei giorni di noleggio
sono maggiori di 6 si applica uno sconto del 10% sul totale. Calcolare il prezzo da pagare.
*/

#include <iostream>

using namespace std;

int main()
{
    int giorni;
    int prezzo = 30; //Prezzo al giorno
    
    cout<<"Inserisci i giorni di noleggio ";
    cin>>giorni;

    if (giorni > 6) {
        int preventivo = giorni*prezzo;
        int sconto = (preventivo*10)/100;
        int totale = preventivo-sconto;
        cout<<"Ti è stato applicato uno sconto del 10%\nPagherai "<<totale<<"€";
    } else {
        int totale = giorni*prezzo;
        cout<<"Pagherai "<<totale<<"€";

    }
    return 0;
}
