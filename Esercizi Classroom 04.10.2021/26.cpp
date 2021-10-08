/*
Website: https://matt05.ml
GitHub: @Matt0550
26. Un rappresentante di commercio guadagna un fisso mensile di lire 1.000.000 più lire
200.000 per ogni enciclopedia venduta. Quanto guadagna al mese, sapendo che gli
viene trattenuto il 18%?
*/

#include <iostream>

using namespace std;

int main()
{
    int mensile = 1000000;
    int trattenuto = 18; // 18%
    int enciclopedia = 200000;
    int enciclopedia_vendute;

    cout << "Quante enciclopedia hai venduto? ";
    cin >> enciclopedia_vendute;
    
    int totale = (enciclopedia_vendute*enciclopedia)+mensile;
    totale = totale - (totale/100)*trattenuto;

    cout << "Al mese guadagni " << totale << " lire";
    return 0;
}