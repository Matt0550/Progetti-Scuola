/*
Website: https://matt05.ml
GitHub: @Matt0550
19. Calcolare il successivo del doppio del quadrato di un numero.
*/

#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Inserire un valore ";
    cin >> a;
    int totale = (a*a)*2+1;
    
    cout << "Il successivo del doppo del quadrato è " << totale;

    return 0;
}