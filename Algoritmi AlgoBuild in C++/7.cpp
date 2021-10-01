/*
Website: https://matt05.ml
GitHub: @Matt0550

7. Data una temperatura T, visualizzare se si tratta di una temperatura: "sotto lo zero",
"uguale a zero" o "sopra lo zero". Visualizzare il messaggio in output.
*/

#include <iostream>

using namespace std;

int main()
{
    int temperatura;

    cout<<"Inserisci la temperatura attuale ";
    cin>>temperatura;

    if (temperatura < 0) {
        cout<<"La temperatura è sotto lo zero. Temperatura rilevata " << temperatura<<"°C";
        
    } else if (temperatura > 0) {
        cout<<"La temperatura è sopra lo zero. Temperatura rilevata " << temperatura<<"°C";
        
    } else if (temperatura == 0) {
        cout<<"La temperatura è uguale allo zero. Temperatura rilevata " << temperatura<<"°C";
        
    } else {
        cout<<"Errore " << temperatura;
    }
    return 0;
}
