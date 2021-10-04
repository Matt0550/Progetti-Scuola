/*
Website: https://matt05.ml
GitHub: @Matt0550
18. Un signore possiede 1,75$ ($ = dollaro) e 2,80£ (£ = sterline). Quanto ha, in totale, in
euro supposto che 1$ = 1,514€ e 1£ = 2,52€?
*/

#include <iostream>

using namespace std;

int main()
{
    double dollaro_valore_eur = 1.514; // In euro
    double streline_valore_eur = 2.52; // In euro
    double dollaro = 1.75; // Possiede 1,75$
    double sterline = 2.80; // Possiede 2,80£

    double totale = dollaro*dollaro_valore_eur + sterline*streline_valore_eur;
    cout << "In totale hai " << totale << "€"; 

    return 0;
}