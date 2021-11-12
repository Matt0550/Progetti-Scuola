/*
Website: https://matt05.ml
GitHub: @Matt0550
Un'agenzia di viaggi effettua per prenotazioni per i voli della compagnia Rapisardi AirLines che applica delle tariffe standard per le seguenti destinazioni: 
1: Catania - Roma 30€; 
2: Catania - Praga 55€; 
3: Catania - New York 400€; 
Al momento della prenotazione il cliente dovrà indicare il numero di passegeri da prenotare e l'eventuale supplemento del bagaglio in stiva che corrisponde a 20€ per le destinazioni europee e di 50€ per i voli intercontinentali per ogni passegero.
Nel mese di Novembre l'agenzia applica uno sconto del 10% se il costo della prenotazione è superiore a 500€.
Sul costo della prenotazione bisognerà calcolare le imposte di imbarco del 10% per destinazioni europee e e 17% per destinazioni intercontinentali.
Visualizzare:
- Il totale lordo della prenotazione (senza imposte)
- Le imposte di imbarco
- Lo sconto
- Il totale netto da pagare
- Il messaggio "sconto d'autunno" se è stato applicato lo sconto
Alla fine il programma dovrà prevedere il controllo dell'input in maniera tale che non possao essere inseriti codici di destinazione diversi da quelli prestabiliti.
Se il cliente ha bagagli in stiva visualizzare il messaggio "Recarsi per il check-in allo sportello 8"
*/

#include <iostream>

using namespace std;

// Global variable

string FlightCompany = "Rapisardi AirLines";

string AirportDepartures[] = {"Catania Fontanarossa"};
string AirportDeparturesCode[] = {"CTA"};

string Destinations[] = {"Roma Fiumicino", "Praga", "New York John Fitzgerald Kennedy International"};
string DestinationsCode[] = {"FCO", "PRG", "JFK"};

int DestinationsPrice[] = {30, 55, 400};


void ClearScreen() {
    #ifdef _WIN32 // Check OS
    system("CLS"); // Windows os
    #else
    system("clear"); // Linux or Mac Windows
    #endif
}

// Class taken from my GitHub profile created by me
string CustomSeparatorWithText(string symbol, string text, int length = 10) {
    string center, text1, text2, text3, lati, sym;
    int length2;

    sym = symbol;

    int tex = text.length();

    for (int i = 1; i < tex+2 + length; i++) {
        symbol = symbol + sym;
    }

    text1 = symbol + "\n";
    length2 = length/2-0;

    for (int i = 0; i < length2; i++) {
        lati = lati + sym;
    }

    text3 = symbol + "\n" + lati + " " + text + " " + lati + "\n" + symbol + "\n";
    return text3;
}

class Flight {
    public:
    void ChooseFlight(string departure, string destination) {
        
        
    }
};

class Welcome {
    public:
    Flight flight;
    void home() {
        int AirportDeparturesLen = sizeof(AirportDepartures)/sizeof(AirportDepartures[0]);
        int DestinationsLen = sizeof(Destinations)/sizeof(Destinations[0]);

        string choose;
        
        cout<<CustomSeparatorWithText("=", FlightCompany);
        cout<<"Benvenuto in "<<FlightCompany<<endl;
        cout<<"Per prenotare un viaggio, selezionare l'aereoporto di partenza: "<<endl<<endl;
        
        for (int i = 0; i<AirportDeparturesLen; i++) {
            cout<<AirportDeparturesCode[i]<<": Aereoporto di "<<AirportDepartures[i]<<endl;
        }
        while (true) {
            cout<<"\nSeleziona un aereoporto di partenza: ";
            cin>>choose;
            for (int i = 0; i<AirportDeparturesLen; i++) {
    
                if (choose == AirportDeparturesCode[i] or choose == AirportDepartures[i]) {
                    break;
                }
                break;
            }
           break;
        }
        
        ClearScreen();
        cout<<CustomSeparatorWithText("=", "Destinazioni");
        cout<<"Selezionare adesso l'aereoporto di arrivo: "<<endl<<endl;

        for (int i = 0; i<DestinationsLen; i++) {
            cout<<DestinationsCode[i]<<": Aereoporto di "<<Destinations[i]<<endl;
        }
        
        while (true) {
            cout<<"\nSeleziona un aereoporto di arrivo: ";
            cin>>choose;
            for (int i = 0; i<DestinationsLen; i++) {

                if (choose == DestinationsCode[i] or choose == Destinations[i]) {
                    ClearScreen();
                    cout<<CustomSeparatorWithText("=", FlightCompany);
                    flight.ChooseFlight(AirportDepartures[i], Destinations[i]);
                    cout<<"Attendere prego: "<<endl<<endl;
                }
            }
        }
    }
    
};


int main()
{
    Welcome welcome;
    welcome.home();
    return 0;
}
