/*
Website: https://matt05.ml
GitHub: @Matt0550

4. Creare poi un programma che si faccia passare due quantità di tempo e verifichi quale è maggiore
*/
#include <iostream>

using namespace std;

bool timeToSeconds(int ore, int minuti, int secondi, int ore2, int minuti2, int secondi2) {
    ore *= 3600;
    minuti *= 60;
    ore2 *= 3600;
    minuti2 *= 60;
    int tot1 = ore+minuti+secondi;
    int tot2 = ore2+minuti2+secondi2;
    
    return (tot1>tot2) ?  true : false;
}

int main()
{
    int risultato = timeToSeconds(11, 34, 20, 12, 34, 20);
    if(risultato == 1) {
        cout<<"Il primo tempo è maggiore rispetto al secondo.";
    } else {
        cout<<"Il secondo tempo è maggiore rispetto al primo";
    }
    return 0;
}