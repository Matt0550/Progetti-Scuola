/*
Website: https://matt05.ml
GitHub: @Matt0550
6. Selezionando un giorno della settimana, comunica l'orario scolastico delle lezioni di quel giorno
*/

#include <iostream>

using namespace std;

int main()
{
    string giorni[] = {"lunedì", "martedì", "mercoledì", "giovedì", "venerdì"};
    string compiti[] = {"- Matematica\n- Italiano", "- Italiano", "- Inglese", "- Informatica\n- Inglese", "- Storia"};
    
    int scelta;
    cout<<"1. Lunedì\n2. Martedì\n3. Mercoledì\n4. Giovedì\n5. Venerdì\n\nCosa vuoi fare? ";
    cin>>scelta;
    
    int giorniLen = sizeof(giorni)/sizeof(giorni[0]);
    
    for(int i=0; i <= giorniLen; i++) {
        if (scelta == i) {
            cout<<"Per " + giorni[i-1] + " ci sono:\n"+compiti[i-1];
        }
        
    }
    return 0;
}
