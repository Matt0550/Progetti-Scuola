/*
Website: https://matt05.ml
GitHub: @Matt0550
21. Calcolare la differenza tra il quadrato di un numero e il numero stesso.
*/

#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Inserire un valore ";
    cin >> a;
    int b = a*a;
    int totale = b-a;

    cout << "La differenza tra il quadrato di un numero e il numero stesso è " << totale;
    return 0;
}