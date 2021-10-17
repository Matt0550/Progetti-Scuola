/*
Website: https://matt05.ml
GitHub: @Matt0550
8. Determinare se la potenza an è un numero pari (senza effettuare l'operazione).
*/

#include <iostream>

using namespace std;

string calcolo_parita(int a, int n) { 
    if(a == 0 and n == 0) {
        return "impossibile.";
        
    } else if(a == 0) {
        return "pari (il risultato è 0).";
        
    } else if(n == 0) {
        return "dispari";
        
    } else if(a%2 == 0) {
        return "pari.";
        
    } else {
        return "dispari";
    }
}

int main()
{
    int a,n;

    cout << "Inserire la base: ";
    cin >> a;
    
    cout << "Inserire l'esponente: ";
    cin >> n;
    
    
    cout << "La potenza è " << calcolo_parita(a, n);
    return 0;
}