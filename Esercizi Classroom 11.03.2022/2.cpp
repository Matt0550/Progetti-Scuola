/*
Website: https://matt05.ml
GitHub: @Matt0550

Scrivere un programma che riceve in ingresso un mese (numero intero) e stampa quanti giorni ha quel mese.
*/

#include <iostream>

using namespace std;

int main()
{
    int mese, mese_giorni;
    cout<<"Inserisci il mese a numero: ";
    cin>>mese;
    switch (mese) {
        case 1:
            mese_giorni = 31;
            break;
        case 2:
            mese_giorni = 28;
            break;
        case 3:
            mese_giorni = 31;
            break;
        case 4:
            mese_giorni = 30;
            break;
        case 5:
            mese_giorni = 31;
            break;
        case 6:
            mese_giorni = 30;
            break;
        case 7:
            mese_giorni = 31;
            break;
        case 8:
            mese_giorni = 31;
            break;
        case 9:
            mese_giorni = 30;
            break;
        case 10:
            mese_giorni = 31;
            break;
        case 11:
            mese_giorni = 30;
            break;
        case 12:
            mese_giorni = 31;
            break;
        default:
            mese_giorni = 0;
            cout<<"Mese non valido...\n";
            main();
            break;
    }
    
    cout<<"\nIl mese "<<mese<<" ha "<<mese_giorni<<" giorni";

    return 0;
}
