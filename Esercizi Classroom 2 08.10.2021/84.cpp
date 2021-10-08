/*
Website: https://matt05.ml
GitHub: @Matt0550
84. Dati due numeri naturali A e B, con A diverso da B, aggiungere al più piccolo la somma dei due numeri. 
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B;
    
    cout << "Inserire il valore di A: ";
    cin >> A;
    
    cout << "Inserire il valore di B: ";
    cin >> B;
    
    if (A!=B) {
        if (A<B) {
            int somma = A+A+B;
            cout << "Il numero più piccolo sommato alla somma dei due numeri è: " << somma;
        } else {
            int somma = B+B+A;
            cout << "Il numero più piccolo sommato alla somma dei due numeri è: " << somma;

        }
    } else {
        cout << "I due numeri sono uguali!";
    }
    return 0;
}