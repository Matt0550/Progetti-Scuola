/*
Website: https://matt05.ml
GitHub: @Matt0550

In un albergo il prezzo della camera dipende dal piano in cui ci si trova secondo la seguente tabella.
piano 1 € 35
piano 2 € 45
piano 3 € 55
piano 4 € 65
Calcola il prezzo del conto sapendo il numero di giorni di soggiorno e il piano della camera.
*/

#include <iostream>

using namespace std;

int main()
{
    cout<<"Benvenuto, in che piano si trova la sua camera? ";
    int camera, costo, giorni;
    cin>>camera;
    
    switch (camera) {
        case 1:
            costo = 32;
            break;
        case 2:
        costo = 45;
            break;
        case 3:
            costo = 55;
            break;
        case 4:
            costo = 65;
            break;
        default:
	    costo = 0;
            cout<<"Non valido...\n";
            main();
            break;
    }
    
    cout<<"\nQuanti giorni soggiornate? ";
    cin>>giorni;
    cout<<"Iln costo del soggiorno è di €"<<costo*giorni;
    exit(0);

    return 0;
}
