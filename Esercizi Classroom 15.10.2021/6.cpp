/*
Website: https://matt05.ml
GitHub: @Matt0550
6. Determinare se un numero A ha la stessa parità di un numero B. (Due numeri hanno la stessa parità se sono entrambi pari o entrambi dispari). 
*/

#include <iostream>

using namespace std;

string calcolo_parita(int A, int B) { // Funzione per determinare se il numero è pari o dispari
    if (A%2 == 0 && B%2 == 0) {
        return "I due numeri sono pari";
    } else if (A%2 != 0 && B%2 != 0) {
        return "I due numeri sono dispari";
    } else {
        return "Uno dei due numeri è dispari";
    }
}

int main()
{
    int A,B;

    cout << "Inserire un numero intero: ";
    cin >> A;
    
    cout << "Inserire un altro numero intero: ";
    cin >> B;
    
    
    cout << calcolo_parita(A, B);
    return 0;
}