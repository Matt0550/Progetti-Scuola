/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Dato un numero intero N, stabilire se è divisibile per A. (Controllare il resto della divisione).  
*/

#include <iostream>

using namespace std;

string calcolo_divisore(int numero, int A) { // Funzione per determinare se il numero è pari o dispari
    if (numero%A == 0) {
        return "divisibile per " + to_string(A);
    } else {
        return "non è divisibile per " + to_string(A);
    }
}

int main()
{
    int N, A;

    cout << "Inserire un numero intero: ";
    cin >> N;
    
    cout << "Inserire un altro numero intero: ";
    cin >> A;

    cout << "Il numero è " << calcolo_divisore(N, A);
    return 0;
}