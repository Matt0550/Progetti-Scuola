/*
Website: https://matt05.ml
GitHub: @Matt0550
Il supermercato Rapisardi Shop necessita di un software per le registrazioni di cassa e per stampare gli scontrini sui prodotti venduti.
Considerando che nel periodo di Natale (tutto il mese di dicembre) lo shop effettua il 20 % di sconto sui prodotti e che hai clienti con la carta fedeltà è concesso un ulteriore 5% di sconto il programma, prima di operare dovrà essere inizializzato inserendo la data attuale.
Successivamente per ogni operazione il programma dovrà chiedere se il cliente ha la carta o meno.
I prodotti sono individuati tramite il codice a barre e per ogni operazione dovrà essere effettuata la somma dei prodotti acquistati dal cliente per la stampa dello scontrino.
Ogni volta che il codice a barre di un prodotto viene passato sul lettore (simulate questa operazione semplicemente inserendo il codice a barre da tastiera), la quantità totale di quei prodotti nello store dovrà essere scalata di uno.
*/

#include <iostream>
#include <ctime> // Date
#include <algorithm> // begin, end
#include <vector> 
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
vector<vector<string>>carteFedelta = {
    {"Mattia Samuel", "0280094658"}
};

vector<vector<string>>prodotti = {
    {"Cioccolato", "6263574002", "20", "5"},
    {"Cioccolato", "3984701918", "20", "100"},
    {"Cioccolato", "7253102109", "20", "100"},
    {"Cioccolato", "7051784294", "20", "100"},
    {"Cioccolato", "3514450419", "20", "100"},
    {"Cioccolato", "7128355145", "20", "100"},
    {"Cioccolato", "2623087825", "20", "100"},
    {"Cioccolato", "9100260178", "20", "100"},
    {"Cioccolato", "9120007998", "20", "100"},
    {"Cioccolato", "7291436575", "20", "100"},
    {"Cioccolato", "2497724907", "20", "100"},
    {"Cioccolato", "3442243248", "20", "100"},
    {"Cioccolato", "6268046005", "20", "100"},
    {"Cioccolato", "8809777120", "20", "100"},
    {"Cioccolato", "1942066039", "20", "100"},

    // Prdotto, codice, prezzo, quantità
};
vector<string>carrello;
// Global variable

string ShopCompany = "Rapisardi Shop";
string greenColorCode = "\033[92m";
string boldColorCode = "\033[1m";
string resetColorCode = "\033[0m";


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

class Process {
    public:
    void RetriveProductInformation(string code, int i) {
        ClearScreen();
        cout<<CustomSeparatorWithText("=", "Cassa");
        cout<<"Prodotto: "<<prodotti[i][0]<<endl;
        cout<<"Codice: "<<prodotti[i][1]<<endl;
        cout<<"Prezzo: "<<prodotti[i][2]<<endl;
        cout<<"Quantità in magazzino: "<<prodotti[i][3]<<endl;
        string choose;
        cout<<"Vuoi aggiungere l'articolo al carello? "<<greenColorCode;
        cin>>choose;
        cout<<resetColorCode;
        if(choose == "si" or choose == "Si" or choose == "sI" or choose == "SI") {
            if (stoi(prodotti[i][3]) == 0) {
                cout<<"Il prodotto "<<boldColorCode<<prodotti[i][0]<<resetColorCode<<" non è disponibile!"<<endl;
                cout<<"Codice: "<<prodotti[i][1]<<endl;
                cout<<"Prezzo: "<<prodotti[i][2]<<endl;
                cout<<"Quantità in magazzino: "<<prodotti[i][3]<<endl;
                
            } else {
                carrello.push_back(prodotti[i][1]);
                prodotti[i][3] = to_string(stoi(prodotti[i][3])-1);
                cout<<"Il prodotto "<<boldColorCode<<prodotti[i][0]<<resetColorCode<<" è stato aggiunto al carrello!"<<endl;
                cout<<"Quantità in magazzino: "<<prodotti[i][3]<<endl;
                cin.clear();
                sleep(1.5);
                ClearScreen();
                cout<<CustomSeparatorWithText("=", ShopCompany);
                cout<<"Benvenuto in "<<ShopCompany<<endl;
            }
        }
    }
};

class Welcome {
    Process process;
    public:
    void viewCart() {
        ClearScreen();
        cout<<CustomSeparatorWithText("=", "Carrello");
        for(int i = 0; i < carrello.size(); i++) {
            cout<<carrello[i];
        }
    }
    void informazioni() {
        ClearScreen(),
        cout<<CustomSeparatorWithText("=", "Informazioni prodotto");
        string choose;
        while(choose != "exit") {
            cout<<"Inserisci il codice prodotto: "+greenColorCode;
            cin>>choose;
            cout<<resetColorCode;
            if(choose == "exit"){
                exit(0);
            }
            for(int i = 0; i < prodotti.size(); i++){
                if(choose == prodotti[i][1]) {
                    process.RetriveProductInformation(choose, i);
                    break;
                }
            }
            cout<<"\nCodice prodotto non valido! "<<endl;    
        }
    }

    void home() {
        cout<<CustomSeparatorWithText("=", ShopCompany);
        cout<<"Benvenuto in "<<ShopCompany<<endl<<endl;
        cout<<"1. Informazioni prodotto"<<endl;
        cout<<"2. Visualizza carrello"<<endl;
        string choose;

        while(choose!="exit") {
            cout<<"Cosa vuoi fare? ";
            cin>>choose;
            if(stoi(choose)==1) {
                informazioni();
            } else if(stoi(choose) == 2) {
                viewCart();
            } else {
                cout<<"Scelta non valida!"<<endl;
            }
        }
    }
};


int main() {
    Welcome welcome;
    welcome.home();
}