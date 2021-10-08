/*
Website: https://matt05.ml
GitHub: @Matt0550
83. Stabilire se un numero naturale qualsiasi, diverso da zero, è divisore di 36. 
*/

#include <iostream>

using namespace std;

int main()
{
    int numero;
    
    cout << "Inserire un numero: ";
    cin >> numero;
    
    if (numero != 0) {
        if (36%numero == 0) {
            cout << "Il numero è divisibile per 36";
        } else {
            cout << "Il numero non è divisibile per 36";
        }
    } else {
        cout << "Il numero non può essere 0";
    }
    
    return 0;
}