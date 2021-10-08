/*
Website: https://matt05.ml
GitHub: @Matt0550
29. Dati importo lordo ed importo scontato, determinare la percentuale di sconto
*/

#include <iostream>

using namespace std;

int main()
{
    double importo_lordo, importo_scontato;

    cout << "Inserire l'importo lordo ";
    cin >> importo_lordo;
    
    cout << "Inserire l'importo scontato ";
    cin >> importo_scontato;
    
    double sconto = ((importo_lordo-importo_scontato)*100)/importo_lordo;

    cout << "La percentuale di sconto è di " << sconto << "%";
    return 0;
}