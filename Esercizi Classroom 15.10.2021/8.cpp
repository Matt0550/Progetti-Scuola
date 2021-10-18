/*
Website: https://matt05.ml
GitHub: @Matt0550
8. Determinare se la potenza an è un numero pari (senza effettuare l'operazione).
*/

#include <iostream>

using namespace std;

string calcolo_parita(int base, int esponente) { 
    if(base == 0 and esponente == 0) {
        return "impossibile";
        
    } else if(base == 0) {
        return "pari (il risultato è 0)";
        
    } else if(esponente == 0) {
        return "dispari";
        
    } else if(base%2 == 0) {
        return "pari";
        
    } else {
        return "dispari";
    }
}

int main()
{
    int base,esponente;

    cout << "Inserire la base: ";
    cin >> base;
    
    cout << "Inserire l'esponente: ";
    cin >> esponente;
    
    
    cout << "La potenza è " << calcolo_parita(base, esponente);
    return 0;
}
