/*
Website: https://matt05.ml
GitHub: @Matt0550
Il supermercato Rapisardi Shop necessita di un software per le registrazioni di cassa e per stampare gli scontrini sui prodotti venduti.
Considerando che nel periodo di Natale (tutto il mese di dicembre) lo shop effettua il 20 % di sconto sui prodotti e che hai clienti con la carta fedeltà è concesso un ulteriore 5% di sconto il programma, 
prima di operare dovrà essere inizializzato inserendo la data attuale.
Successivamente per ogni operazione il programma dovrà chiedere se il cliente ha la carta o meno.
I prodotti sono individuati tramite il codice a barre e per ogni operazione dovrà essere effettuata la somma dei prodotti acquistati dal cliente per la stampa dello scontrino.
Ogni volta che il codice a barre di un prodotto viene passato sul lettore (simulate questa operazione semplicemente inserendo il codice a barre da tastiera), 
la quantità totale di quei prodotti nello store dovrà essere scalata di uno.
*/

#include <iostream>
#include <string>
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
    {"Mattia", "Canio", "0280094658"}
};

vector<vector<string>>prodotti = {
    {"Rio mare filod'olio Tonno all'Olio di Oliva 4 x 65 g", "6263574002", "5.29", "10"},
    {"Tre Marie il Panettone Tuttuvetta 1000 g", "3984701918", "11.90", "13"},
    {"Pan di Stelle Crema alle nocciole e cacao 330g", "7253102109", "3.65", "12"},
    {"Carrefour Bio 6 Uova Fresche di vario calibro Biologiche Categoria A 330 g", "7051784294", "1.99", "13"},
    {"Carrefour il Mercato Insalata 3 Gusti 250 g", "3514450419", "1.88", "16"},
    {"Aia Milanese Cotoletta di Pollo 0,280 kg", "7128355145", "3.83", "11"},
    {"NESCAFÉ DOLCE GUSTO ESPRESSO ARDENZA Caffè espresso 16 capsule", "2623087825", "5.59", "9"},
    {"Barilla Spaghetti n.5 1 kg", "9100260178", "1.75", "19"},
    {"Capitan Findus 12 Bastoncini 300 g", "9120007998", "3.95", "12"},
    {"Sofficini Findus 4 Sofficini Formaggi Più Mozzarella 266 g", "7291436575", "2.49", "13"},
    {"Nutella 450 g", "2497724907", "3.55", "16"},
    {"Kellogg's Coco pops Palline 450 g", "3442243248", "3.59", "10"},
    {"Galbani Santa Lucia Tris Mozzarella 3 x 125 g", "6268046005", "3.49", "12"},
    {"Pavesi Gocciole Chocolate 500g", "8809777120", "2.19", "19"},
    {"COCA-COLA Zero Zuccheri 1,5L", "1942066039", "1.55", "12"},

    // Prodotto, codice, prezzo, quantità
};
vector<string>carrello;

// Global variable

string ShopCompany = "Rapisardi Shop";
string greenColorCode = "\033[92m";
string redColorCode = "\033[91m";
string cyanColorCode = "\033[96m";
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

class Program {
    public:
    // Cart
    int cartaFedeltaI;
    bool verificaFedelta(string id) {
        for(int i = 0; i<carteFedelta.size(); i++) {
            if(id == carteFedelta[i][2]) {
                cartaFedeltaI = i;
                return true;
            }
            return false;
        }
        return false;
    }
    
    void scontrino() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Scontrino")<<resetColorCode<<endl;
        
        for(int i = 0; i < carrello.size(); i++) {
            for(int x = 0; x < prodotti.size(); x++) {
                if(carrello[i] == prodotti[x][1]) {
                    cout<<i+1<<". "<<carrello[i]<<": "<<prodotti[x][0]<<" - "<<boldColorCode<<prodotti[x][2]<<"€"<<resetColorCode<<endl;
                    
                }
            }
        }
        
        cout<<"Pagamento effettuato!\n";
        cout<<"Ritorno alla home...\n";
        sleep(1);
        carrello.clear();
        home();

    }
    
    void checkOut(double subTotal, int sale) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Check Out")<<resetColorCode<<endl;
        double total = subTotal - (subTotal*sale)/100;
        cout<<"Totale provvisorio: "<<subTotal<<"€"<<endl;
        cout<<"Totale da pagare: "<<total<<"€"<<endl;
        cout<<"Sconto applicato: "<<sale<<"%"<<endl<<endl;
        string choose;
        while(choose != "exit") {
            cout<<"Effettuare il pagamento? "<<greenColorCode;
            cin>>choose;
            cout<<resetColorCode;
            
            if(choose == "si" or choose == "Si" or choose == "sI" or choose == "SI") {
                scontrino();
                
            } else if (choose == "no" or choose == "No" or choose == "nO" or choose == "NO") {
                cout<<"Ritorno alla home...";
                carrello.clear();
                
            } else {
                cout<<"\nScelta non valida!\n";
            }   
        }
    }
    
    
    void viewCart() {
        ClearScreen();
        double subTotal;
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Carrello")<<resetColorCode<<endl;
        if(carrello.size() == 0) {
            cout<<"Il carrello è vuoto!\n";
            cout<<"Ritorno alla home...\n";
            sleep(2);
            ClearScreen();
            home();
        } else {
            for(int i = 0; i < carrello.size(); i++) {
                for(int x = 0; x < prodotti.size(); x++) {
                    if(carrello[i] == prodotti[x][1]) {
                        cout<<i+1<<". "<<carrello[i]<<": "<<prodotti[x][0]<<" - "<<boldColorCode<<prodotti[x][2]<<"€"<<resetColorCode<<endl;

                        subTotal = subTotal + stod(prodotti[x][2]);    
                    }
                }
            }
            cout<<"\nTotale Provvisiorio: " << subTotal << "€\n"; 

            cout<<"\n1. Rimuovi Prodotto\n2. Check-out\n\n3. Indietro\n";
    
            string choose;
            while(choose != "exit") {
                cout<<endl<<"Cosa vuoi fare? "<<greenColorCode;
                cin>>choose;
                cout<<resetColorCode;
                // Rimuovi prodotto
                if(choose == "1") {
                    string code;
                    while(code != "exit") {
                        cout<<"Digitare adesso il codice prodotto: "<<greenColorCode;
                        cin>>code;
                        cout<<resetColorCode;
                        
                        for(int i = 0; i < carrello.size(); i++){
                            if(code == carrello[i]) {
                                carrello.erase(remove(carrello.begin(), carrello.end(), code), carrello.end());
                                cout<<greenColorCode<<"\nIl prodotto è stato rimosso dal carrello!"<<resetColorCode<<endl;
                                sleep(1);
                                ClearScreen();
                                home();
                                break;
                            }
                        }
                        cout<<redColorCode<<"\nIl prodotto non è stato trovato nel carrello!"<<endl<<resetColorCode<<endl;
                    }
                    
                // Check-out
                
                } else if (choose == "2") {
                    string choose;
                    int sale = 0;
                    while(choose != "exit") {
                        cout<<"Hai la carta fedeltà? (si/no) "<<greenColorCode;
                        cin>>choose;
                        cout<<resetColorCode;
                        
                        if(choose == "si" or choose == "Si" or choose == "sI" or choose == "SI") {
                            string card;
                            while(card != "exit") {
                                cout<<"Inserisci l'id della carta fedeltà: "<<greenColorCode;
                                cin>>card;
                                cout<<resetColorCode;
                                if(verificaFedelta(card)) {
                                    sale += 5;
                                    cout<<"É stato applicato il 5% di sconto!"<<endl;
                                    checkOut(subTotal, sale);
                                    break;

                                } else {
                                    cout<<redColorCode<<"Carta fedeltà non trovata!"<<resetColorCode<<endl;
                                }
                            }
                            
                        } else if (choose == "no" or choose == "No" or choose == "nO" or choose == "NO") {
                            checkOut(subTotal, sale);
                            break;
                        } else {
                            cout<<"\nScelta non valida!\n";
                        }
                        if(GetDate("month") == "12") {
                            cout<<"Hai diritto allo sconto natalizio"<<endl;
                            sale += 20;
                        }
                    }
                    
                    
                } else if (choose == "3") {
                    ClearScreen();
                    home();
                }
            }
        }
    }
    
    // Product Information
    
    void RetriveProductInformation(string code, int i) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Cassa")<<resetColorCode<<endl;
        cout<<"Prodotto: "<<prodotti[i][0]<<endl;
        cout<<"Codice: "<<prodotti[i][1]<<endl;
        cout<<"Prezzo: "<<prodotti[i][2]<<"€"<<endl;
        cout<<"Quantità in magazzino: "<<prodotti[i][3]<<endl;
        string choose;
        while(choose != "exit") {
            cout<<endl<<"Vuoi aggiungere l'articolo al carello? "<<greenColorCode;
            cin>>choose;
            cout<<resetColorCode;
            if(choose == "si" or choose == "Si" or choose == "sI" or choose == "SI") {
                if (stoi(prodotti[i][3]) == 0) {
                    cout<<redColorCode<<"Il prodotto "<<boldColorCode<<prodotti[i][0]<<" non è disponibile!"<<resetColorCode<<endl;
                    cout<<"Codice: "<<prodotti[i][1]<<endl;
                    cout<<"Prezzo: "<<prodotti[i][2]<<"€"<<endl;
                    cout<<"Quantità in magazzino: "<<prodotti[i][3]<<endl;
                    
                } else {
                    carrello.push_back(prodotti[i][1]);
                    prodotti[i][3] = to_string(stoi(prodotti[i][3])-1);
                    cout<<greenColorCode<<"Il prodotto è stato aggiunto al carrello!"<<resetColorCode<<endl;
                    cout<<"Quantità in magazzino: "<<prodotti[i][3]<<endl;
                    cin.clear();
                    sleep(1);
                    ClearScreen();
                    home();
                }
            } else if (choose == "no" or choose == "No" or choose == "nO" or choose == "NO") {
                cin.clear();
                ClearScreen();
                home();
            } else {
                cout<<"\nScelta non valida!\n";
            }
        }

    }
    
    void informazioni() {
        ClearScreen(),
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Informazioni prodotto")<<resetColorCode;
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
                    RetriveProductInformation(choose, i);
                    break;
                }
            }
            cout<<"\nCodice prodotto non valido! "<<endl;    
        }
    }
    
    // Homepage

    void home() {
        cout<<cyanColorCode<<CustomSeparatorWithText("=", ShopCompany)<<resetColorCode;
        cout<<"Benvenuto in "<<ShopCompany<<endl<<endl;
        cout<<"1. Informazioni prodotto"<<endl;
        cout<<"2. Visualizza carrello"<<endl<<endl;
        cout<<"3. Esci"<<endl;
        string choose;

        while(choose!="exit") {
            cout<<"\nCosa vuoi fare? "<<greenColorCode;
            cin>>choose;
            cout<<resetColorCode;
            if(choose == "1") {
                informazioni();
            } else if(choose == "2") {
                viewCart();
            } else if(choose == "3") {
                cout<<"\nArrivederci!\n";
                exit(0);
            } else {
                cout<<"Scelta non valida!"<<endl;
            }
        }
    }
};


int main() {
    Program program;
    program.home();
}
