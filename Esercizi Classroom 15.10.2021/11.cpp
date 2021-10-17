/*
Website: https://matt05.ml
GitHub: @Matt0550
11. Data la base e l'esponente intero di una potenza, stabilire senza effettuare il calcolo, il segno di tale potenza.
*/

#include <iostream>

using namespace std;

string calcolo_segno(int base, int esponente) { 
    if(esponente == 0) {
        return "positivo";
        
    } else if(base < 0){
        if(esponente%2 == 0) {
            return "positivo";
            
        } else {
            return "negativo";
        }
        
    } else {
        return "positivo"; 
        
    }
}

int main()
{
    int base,esponente;

    cout << "Inserire la base della potenza: ";
    cin >> base;
    
    cout << "Inserire l'esponente della potenza: ";
    cin >> esponente;
    
    
    cout << "Il segno della potenza è " << calcolo_segno(base, esponente);
    return 0;
}