/*
Website: https://matt05.ml
GitHub: @Matt0550
4. Verificare se un numero dato in input è divisibile per 3 o per 7. 
*/

#include <iostream>

using namespace std;

string calcolo_divisore(int numero) { // Funzione per determinare se il numero è pari o dispari
    if (numero%3 == 0) {
        return "è divisibile per 3";
    } else if (numero%7 == 0) {
        return "è divisibile per 7 ";
    } else {
        return "non è divisibile per 3 o per 7";
    }
}

int main()
{
    int N;

    cout << "Inserire un numero intero: ";
    cin >> N;
    
    
    cout << "Il numero " << calcolo_divisore(N);
    return 0;
}