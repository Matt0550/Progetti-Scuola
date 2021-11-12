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
#include <ctime>

using namespace std;

// Global variable

string FlightCompany = "Rapisardi AirLines";

string AirportDepartures[] = {"Catania Fontanarossa"};
string AirportDeparturesCode[] = {"CTA"};

string Destinations[] = {"Roma Fiumicino", "Praga", "New York John Fitzgerald Kennedy International"};
string DestinationsCode[] = {"FCO", "PRG", "JFK"};

int DestinationsPrice[] = {30, 55, 400};
string DestinationsZone[] = {"europee", "europee", "intercontinentali"};

int DestinationsPriceEurope = 10;
int DestinationsPriceIntercontinental = 17;
int BagPriceEurope = 20;
int BagPriceIntercontinental = 55;


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

string GetDate() {
    time_t ttime = time(0); // Initialize time
    tm *local_time = localtime(&ttime); // Get local time
    
    string day, month, year;
    
    day = local_time->tm_mday + "/"; // Get day
    month = 1 + local_time->tm_mon+"/"; // Get month
    year = 1900 + local_time->tm_year; // Get year. 1900 default year
    
    return day+month+year;

}

class Flight {
    public:
    int CalculatePrice(int passengers, int checkinBag, string departure, string destination) {
        int AirportDeparturesLen = sizeof(AirportDepartures)/sizeof(AirportDepartures[0]);

        for (int i = 0; i<AirportDeparturesLen; i++) {
            cout<<departure<<AirportDepartures[i];
            if (departure == AirportDepartures[i] && DestinationsZone[i] == "europee") {
                int sale;
                sale = DestinationsPrice[i]-DestinationsPrice[i]*(DestinationsPriceEurope/100);
                
                return sale;
                
            }
        }
        return 0;
 
    }
    
    void ChooseFlight(string departure, string destination) {
        ClearScreen();
        int passengers, checkinBag;
        string departureDate;
        
        cout<<CustomSeparatorWithText("=", "Prenotazione");
        cout<<"Data attuale: "<<GetDate()<<endl<<endl;
        cout<<"Aereoporto di partenza: "<<departure<<endl;
        cout<<"Aereoporto di arrivo: "<<destination<<endl<<endl;
        
        cout<<"Numero di passegeri: ";
        cin>>passengers;
        
        cout<<"Numero di bagagli da stiva: ";
        cin>>checkinBag;
        
        cout<<"Data di partenza: ";
        cin>>departureDate;
        
        cout<<CalculatePrice(passengers, checkinBag, departure, destination);
    
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
            cout<<"\nSelezionare l'aereoporto di partenza: ";
            cin>>choose;
            for (int i = 0; i<AirportDeparturesLen; i++) {
    
                if (choose == AirportDeparturesCode[i] or choose == AirportDepartures[i]) {
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
                                for (int x = 0; x<AirportDeparturesLen; x++) {
                                    flight.ChooseFlight(AirportDepartures[x], Destinations[i]);
                                    break;  
                                }
      
                            }
                        }
                    }
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


