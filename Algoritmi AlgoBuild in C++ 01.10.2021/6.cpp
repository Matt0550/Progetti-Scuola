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
