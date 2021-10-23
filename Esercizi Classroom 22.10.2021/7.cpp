/*
Website: https://matt05.ml
GitHub: @Matt0550
7. Inserendo il proprio giorno e mese di nascita, comunica il segno zodiacale corrispondente alla data inserita
*/

#include <iostream>

using namespace std;

int main()
{
    string mesi[] = {"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
    
    int giorno, mese;
    string segno;

    cout<<"Inserisci il GIORNO del mese di quando sei nato (numero): ";
    cin>>giorno;
    
    cout<<"Inserisci il MESE di quando sei nato (numero): ";
    cin>>mese;

    int mesiLen = sizeof(mesi)/sizeof(mesi[0]);

    for(int i=0; i <= mesiLen; i++) {
        if (mese == i) {
            if (giorno < 31 and giorno > 0) {
                cout<<"Giorno: "<<giorno<<endl;
                cout<<"Mese: "<<mesi[i-1]<<endl<<endl;
                
                switch (mese) {
                    case 1: // Gennaio
                        if(giorno < 22) {
                            segno = "CAPRICORNO"; // 22 dicembre – 20 gennaio
                        } else {
                            segno = "ACQUARIO"; // 21 gennaio – 19 febbraio
                        }
                        break;
                        
                    case 2: // Febbraio
                        if (giorno < 20) {
                            segno = "ACQUARIO"; // 21 gennaio – 19 febbraio
                        } else {
                            segno = "PESCI"; // 20 febbraio – 20 marzo
                        }
                        break;
                        
                    case 3: // Marzo 
                        if (giorno < 21) {
                            segno = "PESCI"; // 20 febbraio – 20 marzo
                        } else {
                            segno = "ARIETE"; // 21 marzo – 20 aprile
                        }
                        break;
                        
                    case 4: // Aprile 
                        if (giorno < 21) {
                            segno = "ARIETE"; // 21 marzo – 20 aprile
                        } else {
                            segno = "TORO"; // 21 aprile – 21 maggio
                        }
                        break;
                        
                    case 5: // Maggio 
                        if (giorno < 22) {
                            segno = "TORO"; // 21 aprile – 21 maggio
                        } else {
                            segno = "GEMELLI"; // 22 maggio – 21 giugno
                        }
                        break;
                        
                    case 6: // Giugno 
                        if (giorno < 22) {
                            segno = "GEMELLI"; // 22 maggio – 21 giugno
                        } else {
                            segno = "CANCRO"; // 22 giugno – 23 luglio
                        }
                        break;
                        
                    case 7: // Luglio 
                        if (giorno < 23) {
                            segno = "CANCRO"; // 22 giugno – 23 luglio
                        } else {
                            segno = "LEONE"; // 23 luglio – 23 agosto
                        }
                        break;
                        
                    case 8: // Agosto 
                        if (giorno < 23) {
                            segno = "LEONE"; // 23 luglio – 23 agosto
                        } else {
                            segno = "VERGINE"; // 24 agosto – 23 settembre
                        }
                        break;
                        
                    case 9: // Settembre 
                        if (giorno < 23) {
                            segno = "VERGINE"; // 24 agosto – 23 settembre
                        } else {
                            segno = "BILANCIA"; // 24 settembre – 23 ottobre
                        }
                        break;
                        
                    case 10: // Ottobre 
                        if (giorno < 23) {
                            segno = "BILANCIA"; // 24 settembre – 23 ottobre
                        } else {
                            segno = "SCORPIONE"; // 24 ottobre – 22 novembre
                        }
                        break;
                        
                    case 11: // Novembre 
                        if (giorno < 22) {
                            segno = "SCORPIONE"; // 24 ottobre – 22 novembre
                        } else {
                            segno = "SAGITTARIO"; // 23 novembre – 21 dicembre
                        }
                        break;
                        
                    case 12: // Dicembre 
                        if (giorno < 22) {
                            segno = "SAGITTARIO"; // 23 novembre – 21 dicembre
                        } else {
                            segno = "CAPRICORNO"; // 22 dicembre – 20 gennaio
                        }
                        break;
                }
                cout << "Il tuo segno zodiacale è " << segno<<endl;
                break;
            } else {
                cout<<"Giorno o mese non validi!\n\n";
                main();
            }
        }
    }
    return 0;
}
