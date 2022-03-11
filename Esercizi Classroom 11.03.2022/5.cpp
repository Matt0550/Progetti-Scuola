/*
Website: https://matt05.ml
GitHub: @Matt0550

Si scriva un programma in linguaggio C che permetta di stabilire la stagione corrispondente al mese inserito come intero dall’utente.
Esempio: se l’utente digita 1 (Gennaio) il programma deve stampare Inverno
Qualora il mese sia Marzo, Giugno, Settembre e Dicembre, tutti mesi a cavallo di due stagioni, si richieda all’utente di specificare 
anche il giorno. Se il giorno e’ compreso tra 1 e 20 si considera la stagione precedente altrimenti quella successiva.
*/

#include <iostream>

using namespace std;

int main()
{
    cout<<"Inserisci il mese: ";
    int mese, giorno;
    cin>>mese;
    switch(mese) {
        case 3:
        case 6:
        case 9:
        case 12:
            cout<<"Inserisci il giorno: ";
            cin>>giorno;
    }
    
    if(giorno > 0 && giorno <= 20) {
        switch(mese) {
            case 3:
                cout<<"Inverno\n";
                break;
            case 6:
                cout<<"Primavera\n";
                break;
            case 9:
                cout<<"Estate";
                break;
            case 12:
                cout<<"Autunno";
                break;
        }
    } else {
        switch(mese) {
            case 1:
            case 2:
                cout<<"Inverno\n";
                break;
            case 3:
                cout<<"Primavera";
                break;
                
            case 4:
            case 5:
                cout<<"Primavera";
                break;
            case 6:
                cout<<"Estate";
                break;
                
            case 7:
            case 8:
                cout<<"Estate";
                break;
            case 9:
                cout<<"Autunno";
                break;
                
            case 10:
            case 11:
                cout<<"Autunno";
                break;
            case 12:
               cout<<"Inverno";
               break; 
        }
    }

    return 0;
}
