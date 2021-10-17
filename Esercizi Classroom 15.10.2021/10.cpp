/*
Website: https://matt05.ml
GitHub: @Matt0550
10. Dati due numeri interi, stabilire, senza effettuare il calcolo, se la loro somma è pari o dispari. 
*/

#include <iostream>

using namespace std;

string calcolo_parita(int n, int n2) { 
    if(n%2 == 0 and n2%2 == 0) {
        return "pari";
        
    } else if((n%2 == 0 and n2%2 != 0) or (n%2 != 0 and n2%2 == 0)) {
        return "dispari";
    } else {
        return "pari";
    }
}

int main()
{
    int n,n2;

    cout << "Inserire il primo numero intero: ";
    cin >> n;
    
    cout << "Inserire il secondo numero intero: ";
    cin >> n2;
    
    
    cout << "La loro somma è " << calcolo_parita(n, n2);
    return 0;
}