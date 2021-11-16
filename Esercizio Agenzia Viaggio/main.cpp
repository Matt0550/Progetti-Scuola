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

Todo:
- Optimize code
- Exit word


Example code:
CTA2211202111PRGF
CTA221120211110112021PRGU
*/

#include <iostream>
#include <ctime> // Date
#include <algorithm> // begin, end

using namespace std;

// Global variable

string FlightCompany = "Rapisardi AirLines";
string greenColorCode = "\033[92m";
string boldColorCode = "\033[1m";
string resetColorCode = "\033[0m";


string AirportDepartures[] = {"Catania Fontanarossa"};
    
string AirportDeparturesCode[] = {"CTA"};

string Destinations[] = {"Roma Fiumicino", "Praga", "New York John Fitzgerald Kennedy International"};
string DestinationsCode[] = {"FCO", "PRG", "JFK"};

int DestinationsPrice[] = {30, 55, 400};
string DestinationsZone[] = {"europee", "europee", "intercontinentali"};

int DestinationsPriceEurope = 10; // Tasse di imbarco destinazioni europee
int DestinationsPriceIntercontinental = 17; // Tasse di imbarco destinazioni intercontinentali

int BagPriceEurope = 20;
int BagPriceIntercontinental = 55;

int NovemberSale = 10; // 10%


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

string GetDate(string type = "all") {
    time_t ttime = time(0); // Initialize time
    tm *local_time = localtime(&ttime); // Get local time
    
    int day, month, year;
    
    day = local_time->tm_mday; // Get day
    month = 1 + local_time->tm_mon; // Get month
    year = 1900 + local_time->tm_year; // Get year. 1900 default year
    
    if (type == "all") {
        return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
        
    } else if (type == "day") {
        return to_string(day);
        
    } else if (type == "month") {
        return to_string(month);
        
    } else if (type == "year") {
        return to_string(year);
    }
    return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
}

int ChooseWhileINT(int choose, string text) {
    cout<< text << greenColorCode;
    cin>>choose;
    cout<<resetColorCode;
    
    while(!cin) {
        cout << text << greenColorCode; // Input verde
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choose;
        cout<<resetColorCode; // Reset colori
    }
    return choose;
}

int ChooseWhileINTDate(int choose, string text, string text2) {
    cin >> choose;
    cout<<resetColorCode; // Reset colori

    while(!cin) {
        cout<<text << greenColorCode; // Input verde
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choose;
        cout<<resetColorCode; // Reset colori
    }
    
    if (cin.get() != '/' ) // La funzione si assicura che tra il giorno e il mese ci sia uno /
    {
        cout<<text2 << greenColorCode; // Input verde
        cout<<resetColorCode; // Reset colori
    } 
    return choose;
}

bool VerifyDateFormat (int day, int month, int year) {
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day>31 || day<1)) {
        return false;
        
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day>30 || day<1)) {
        return false; // I giorni non corrispondono al mese
        
    } else if ((month == 2) && (year % 4 == 0) && (day>29 || day<1)) {
        return false; // I giorni non corrispondono al mese
        
    } else if ((month == 2) && (year % 4 != 0) && (day>28 || day<1) ) {
        return false; // I giorni non corrispondono al mese
        
    } else if ((year < 999) || (year > 10000)) {
        return false; // L'anno inserito non è valido
        
    } else if (year < stoi(GetDate("year"))) {
        return false; // L'anno è minore rispetto a quello attule
        
    } else if (month < stoi(GetDate("month")) && year < stoi(GetDate("year"))) {
        return false; // Il mese e l'anno sono minori rispetto la data attuale
        
    } else if (year > stoi(GetDate("year"))+1) {
        return false; // L'anno è pià grande dell'anno attuale + 1
    }
    if ((month < 1) || (month > 12)) {
        return false; // Il mese è minore di 1 o maggiore di 12
    }
    
    return true;
    
}

string VerifyDate(int day, int month, int year) {
    string var;
    var = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    
    if(day < 10) {
        var = "0" + to_string(day) + "/" + to_string(month) + "/" + to_string(year);    
    }
    if (month < 10) {
        var = to_string(day) + "/" + "0" + to_string(month) + "/" + to_string(year);
    }
    if(day < 10 && month < 10) {
        var = "0" + to_string(day) + "/" + "0" + to_string(month) + "/" + to_string(year);
    }
    return var;
}

class BookingNumber {
    public:
    const char AlphabetUpper[26] = {
        'H', 'Y', 'B', 'C', 'X', 'S', 'F', 'Z', 'U', 'K', 'L', 'N', 'O', 'G', 'T', 'R', 'W', 'D', 'J', 'A', 'I', 'Q', 'E', 'P', 'V', 'M'
    }; // Random alphabet
    
    char GenerateLetterControl(string code) {
        int sum = 0;
        int sum2 = 0;
        for (char ch : code) { // for arrays
            sum += ch;
            if(isdigit(ch)) {
                sum2 += ch - 48;
            }
        }
        //int letter = (sum/7)/sum2;
        int letter = sum%26;

        return AlphabetUpper[letter];
    }

    string GenerateBookingNumber(string departure, string destination, string departureDate, string returnDate, int passengers, int checkinBag) {
        departureDate.erase(remove(departureDate.begin(), departureDate.end(), '/'), departureDate.end()); // Rimuove gli / dall'inizio alla fine della stringa
        returnDate.erase(remove(returnDate.begin(), returnDate.end(), '/'), returnDate.end()); // Rimuove gli / dall'inizio alla fine della stringa
        string partialCode = departure+departureDate+to_string(passengers)+to_string(checkinBag)+returnDate+destination;
        
        string controlLetter;
        controlLetter = GenerateLetterControl(partialCode);
        string code = partialCode + controlLetter;
        
        return code;
    }
    
    bool CheckLetterControl(string bookingNumber) {
        string letter, controlLetter;
        
        if(bookingNumber.length() == 17) {
            controlLetter = bookingNumber.substr(16, 1);
            bookingNumber = bookingNumber.substr(0, 16);
            
        } else if (bookingNumber.length() == 25) {
            controlLetter = bookingNumber.substr(24, 1);
            bookingNumber = bookingNumber.substr(0, 24);
        }
        
        letter = GenerateLetterControl(bookingNumber);
        
        if(letter == controlLetter) {
            return true;
        }

        return false;
    }
    
    string RetriveBookingInformation(string bookingNumber) {
        if (bookingNumber.length() == 17) { // The last letter is of control
            string departureCode = bookingNumber.substr(0, 3);
            string date = bookingNumber.substr(3, 2) + "/" + bookingNumber.substr(5, 2) + "/" + bookingNumber.substr(7, 4);
            string passengers = bookingNumber.substr(11, 1);
            string checkinBag = bookingNumber.substr(12, 1);
            string destinationCode = bookingNumber.substr(13, 3);
            
            return "Partenza: " + departureCode + "\nData: " + date + "\nPassegeri: " + passengers + "\nBagagli: " + checkinBag + "\nDestinazione: " + destinationCode;
            
        } else if (bookingNumber.length() == 25) {
            string departureCode = bookingNumber.substr(0, 3);
            string date = bookingNumber.substr(3, 2) + "/" + bookingNumber.substr(5, 2) + "/" + bookingNumber.substr(7, 4);
            string passengers = bookingNumber.substr(11, 1);
            string checkinBag = bookingNumber.substr(12, 1);
            string returnDate = bookingNumber.substr(13, 2) + "/" + bookingNumber.substr(15, 2) + "/" + bookingNumber.substr(17, 4);
            string destinationCode = bookingNumber.substr(21, 3);
            
            return "Partenza: " + departureCode + "\nData: " + date + "\nPassegeri: " + passengers + "\nBagagli: " + checkinBag + "\nRitorno: " + returnDate +  "\nDestinazione: " + destinationCode;
            
        }
        return "";
        
    }
};

class Flight {
    public:
    void ReviewFlight(int taxes, int price, int priceBag, int subTotal, int total, int sale, int passengers, int checkinBag, string departureDate, string returnDate, int departureX, int destinatioI) {
        ClearScreen();
        cout<<CustomSeparatorWithText("=", "Verifica Prenotazione");
        cout<<"Data attuale: "<<GetDate("all")<<endl<<endl;
        cout<<"Aereoporto di partenza: "<<AirportDepartures[departureX]<<" ("<<AirportDeparturesCode[departureX]<<")"<<endl;
        cout<<"Aereoporto di arrivo: "<<Destinations[destinatioI]<<" ("<<DestinationsCode[destinatioI]<<")"<<endl<<endl;
        cout<<"Passegeri: "<<passengers<<endl;
        cout<<"Bagagli: "<<checkinBag<<endl;
        cout<<"Data di partenza: "<<departureDate<<endl;
        if (returnDate == "") {
            cout<<"Data di ritorno: "<<"Solo andata"<<endl<<endl;
        } else {
            cout<<"Data di ritorno: "<<returnDate<<endl<<endl;
        }

        cout<<"Imposte: "<<taxes<<"€"<<endl;
        cout<<"Volo: "<<"€"<<price<<endl;
        cout<<"Bagagli: "<<priceBag<<"€"<<endl;
        cout<<"Totale netto : "<<subTotal<<"€"<<endl<<endl;
                
        if(sale > 0) {
            cout<<"Sconto d'autunno applicato!\n";
        }
        
        cout<<"Sconto applicato: "<<sale<<"€"<<endl<<endl;
    
        cout<<boldColorCode<<"Totale da pagare: "<<total<<"€"<<resetColorCode<<endl<<endl;
        
        cout<<"Vuoi completare la prenotazione? (si/no) " << greenColorCode; // Input verde
        string choose;
        cin>>choose;
        cout<<resetColorCode; // Reset colori

        if (choose=="si" or choose=="Si" or choose=="SI" or choose=="sI") {
            if (checkinBag>0) {
                string var;
                if(checkinBag>1) {
                    var = "i bagagli";
                } else {
                    var = "il bagaglio";
                }
                cout<<"\nRecarsi allo sportello 8 per imbarcare " << var << "."<<endl;
            }
            BookingNumber bookingNumber;
            cout<<"\nPrenotazione completata!\n\nIl tuo codice di prenotazione:\n"<<boldColorCode<<bookingNumber.GenerateBookingNumber(AirportDeparturesCode[departureX], DestinationsCode[destinatioI], departureDate, returnDate, passengers, checkinBag)<<resetColorCode;
            exit(0);
        } else {
            cout<<"\nArrivederci!";
            exit(0);
        }
    }
    
    double CalculatePrice(int passengers, int checkinBag, string departure, string destination, string departureDate, string returnDate, int departureX, int destinatioI) {
        double taxes, price, priceBag, subTotal, total;
        double sale = 0;
        
        if (returnDate != "") {
            price = (DestinationsPrice[destinatioI]*passengers)*2;
            
            if (departure == AirportDepartures[departureX] && DestinationsZone[destinatioI] == "europee") {
                taxes = (((DestinationsPrice[destinatioI]*DestinationsPriceEurope)/100)*passengers)*2;
                priceBag = (BagPriceEurope*checkinBag)*2;
    
               
            } else if (departure == AirportDepartures[departureX] && DestinationsZone[destinatioI] == "intercontinentali") {
                taxes = (((DestinationsPrice[destinatioI]*DestinationsPriceIntercontinental)/100)*passengers)*2;
                priceBag = (BagPriceIntercontinental*checkinBag)*2;
            }
            
            subTotal =  price+priceBag;
            total =  taxes+subTotal;

            if (GetDate("month") == "11" && total >= 500) {
                sale = ((total*NovemberSale)/100)*2;
                total = (taxes+subTotal)-sale;
            }
            
        } else {
            price = DestinationsPrice[destinatioI]*passengers;

            if (departure == AirportDepartures[departureX] && DestinationsZone[destinatioI] == "europee") {
                taxes = ((DestinationsPrice[destinatioI]*DestinationsPriceEurope)/100)*passengers;
                priceBag = BagPriceEurope*checkinBag;
               
            } else if (departure == AirportDepartures[departureX] && DestinationsZone[destinatioI] == "intercontinentali") {
                taxes = ((DestinationsPrice[destinatioI]*DestinationsPriceIntercontinental)/100)*passengers;
                priceBag = BagPriceIntercontinental*checkinBag;
            }
            
            subTotal =  price+priceBag;
            total =  taxes+subTotal;
    
            if (stoi(GetDate("month")) == 11 && total >= 500) {
                sale = (total*NovemberSale)/100;
                total = (taxes+subTotal)-sale;
            }
        }
        
        ReviewFlight(taxes, price, priceBag, subTotal, total, sale, passengers, checkinBag, departureDate, returnDate, departureX, destinatioI);
        return total;
    }
    
    void CompleteFlight(string departure, string departureCode, int departureX, string destination, string destinationCode, int destinationI) {
        ClearScreen();
        string departureDate, returnDate;
        
        cout<<CustomSeparatorWithText("=", "Prenotazione");
        cout<<"Data attuale: "<<GetDate("all")<<endl<<endl;
        cout<<"Aereoporto di partenza: "<<departure<<" ("<<departureCode<<")"<<endl;
        cout<<"Aereoporto di arrivo: "<<destination<<" ("<<destinationCode<<")"<<endl<<endl;
        
        int passengers = ChooseWhileINT(passengers, "Numero di passegeri (max. 9): ");

    
        int checkinBag = ChooseWhileINT(checkinBag, "Numero di bagagli da stiva (max. 9): ");
    
        while(true) {
            cout<< "Data di partenza (gg/mm/aaaa): " << greenColorCode; // Input verde

            int d = ChooseWhileINTDate(d, "Data di partenza (gg/mm/aaaa): ", "Inserisci il mese: ");
            int m = ChooseWhileINTDate(m, "Data di partenza (gg/mm/aaaa): ", "Inserisci l'anno: ");
            int y = ChooseWhileINTDate(y, "Data di partenza (gg/mm/aaaa): ", "");
            
            departureDate = VerifyDate(d, m, y);
            if(VerifyDateFormat(d, m, y)) {
                break;
            } else {
                cout<<"Data non valida\n\n";
            }
        }
        
        string choose;
        
        cout<<"Vuoi acquistare anche il biglietto di ritorno? (si/no) " << greenColorCode; // Input verde
        cin>>choose;
        cout<<resetColorCode; // Reset colori
        
        if (choose=="si" or choose=="Si" or choose=="SI" or choose=="sI") {
            while(true) {
                cout<<"Data di ritorno (gg/mm/aaaa): " << greenColorCode; // Input verde
                
                int d = ChooseWhileINTDate(d, "Data di partenza (gg/mm/aaaa): ", "Inserisci il mese: ");
                int m = ChooseWhileINTDate(m, "Data di partenza (gg/mm/aaaa): ", "Inserisci l'anno: ");
                int y = ChooseWhileINTDate(y, "Data di partenza (gg/mm/aaaa): ", "");
                
                returnDate = VerifyDate(d, m, y);

                if(VerifyDateFormat(d, m, y)) {
                    break;
                } else {
                    cout<<"Data non valida\n\n";
                }
            }
            
            CalculatePrice(passengers, checkinBag, departure, destination, departureDate, returnDate, departureX, destinationI);

        } else {
            CalculatePrice(passengers, checkinBag, departure, destination, departureDate, returnDate = "", departureX, destinationI);
        }
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
            cout<<"\nSelezionare l'aereoporto di partenza: " << greenColorCode; // Input verde
            cin>>choose;
            cout<<resetColorCode; // Reset colori
            
            for (int i = 0; i<AirportDeparturesLen; i++) {
    
                if (choose == AirportDeparturesCode[i] or choose == AirportDepartures[i]) {
                    ClearScreen();
                    cout<<CustomSeparatorWithText("=", "Destinazioni");
                    cout<<"Selezionare adesso l'aereoporto di arrivo: "<<endl<<endl;
            
                    for (int i = 0; i<DestinationsLen; i++) {
                        cout<<DestinationsCode[i]<<": Aereoporto di "<<Destinations[i]<<endl;
                    }
                    
                    while (true) {
                        cout<<"\nSeleziona un aereoporto di arrivo: " << greenColorCode; // Input verde
                        cin>>choose;
                        cout<<resetColorCode; // Reset colori

                        for (int i = 0; i<DestinationsLen; i++) {
                            if (choose == DestinationsCode[i] or choose == Destinations[i]) {
                                for (int x = 0; x<AirportDeparturesLen; x++) {
                                    flight.CompleteFlight(AirportDepartures[x], AirportDeparturesCode[x], x, Destinations[i], DestinationsCode[i], i);
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
    BookingNumber bookingNumber;
    
    cout<<CustomSeparatorWithText("=", FlightCompany);
    cout<<"Benvenuto in "<<FlightCompany<<endl<<endl;
    cout<<"1. Prenota un volo"<<endl;
    cout<<"2. Ricevi informazioni sulla prenotazione"<<endl<<endl;
    
    while(true) {
        int choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        if (choose == 1) {
            ClearScreen();
            welcome.home();
            break;
            
        } else if (choose == 2) {
            ClearScreen();
            cout<<CustomSeparatorWithText("=", "Informazioni sulla prenotazione");
    
            while(true) {
                string booking;
                cout<<"\nDigita adesso il numero di prenotazione: "<<greenColorCode;
                cin>>booking;
                cout<<resetColorCode;
                
                if(booking.length() == 17 or booking.length() == 25) {
                    if (bookingNumber.CheckLetterControl(booking) == true) {
                        cout<<"Il numero di prenotazione " << boldColorCode << booking << resetColorCode << " è corretto? (si/no) "<< greenColorCode;
                        string choose;
                        cin>>choose;
                        cout<<resetColorCode;
                        
                        if (choose=="si" or choose=="Si" or choose=="SI" or choose=="sI") {
                            ClearScreen();
                            cout<<CustomSeparatorWithText("=", "Informazioni sulla prenotazione");
                            cout<<"Informazioni sulla prenotazione " << boldColorCode << booking << resetColorCode <<endl << endl;
                            cout<<bookingNumber.RetriveBookingInformation(booking);
                            break;
                        
                        }
                    } else {
                        cout<<"\nIl numero di prenotazione non è valido!\n";
                    }
    
                } else {
                    cout<<"\nIl numero di prenotazione non è valido!\n";
                }
            }
            break;
        } else {
            cout<<"Scelta non valida! \n\n";
        }
    }
    return 0;
}
