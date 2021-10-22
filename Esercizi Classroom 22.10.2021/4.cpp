/*
Website: https://matt05.ml
GitHub: @Matt0550
4. A scelta dell'utente, calcola la somma di 10 numeri interi inseriti da tastiera o eleva un numero per un esponente inserito da tastiera
*/

#include <iostream>

using namespace std;

int main()
{
    int numeri[10] = {};
    int numeri_len = sizeof(numeri)/sizeof(numeri[0]);
    int scelta;
    cout<<"1. Somma\n2. Potenza\n\nCosa vuoi fare? ";
    cin >> scelta;
    if(scelta == 1) {
        for(int i = 0; i< numeri_len; i++){
            cout << to_string(i+1) + ". Inserire 10 numeri interi (premi invio ad ogni numero): ";
            cin>>numeri[i];
            if (numeri[i] == 0) {
                break;
            }
        }
        
        int somma = 0;
        for(int i = 0; i < numeri_len; i++){
            somma+=numeri[i];
        }
        cout<<"La somma è uguale a: "<<somma;
        
    } else if (scelta == 2) {
        int numero, potenza;
        int tot = 1;
        cout<<"Inserisci un numero intero: ";
        cin>>numero;
        
        cout<<"Inserisci l'esponente: ";
        cin>>potenza;
        
        for(int i = 0; i < potenza; i++) {
            tot = tot*numero;
        }
    
        cout<<"Il totale è: " << tot;
        
    } else {
        cout<<"\n\nScelta non valida\n";
        main();
    }
    

    
    return 0;
}