/*
Website: https://matt05.ml
GitHub: @Matt0550

Realizzare un programma che permetta di caricare in 4 vettori paralleli il
cognome, nome, tipo abbonamento, e importo abbonamento.
Dopo aver effettuato il caricaemnto effettuare le seguenti operazioni:
1) Visualizzare l'importo totale degli abbonamenti ad un determinato servizio dato in input.
2) Dato in input il cognome di un'abbonato modificare l'importo dell'abbonamento.
3) Trasportare in un'altro vettore i cognomi degli abbonati invertento l'ordine.
*/

#include <iostream>

using namespace std;

string greenColorCode = "\033[92m";
string redColorCode = "\033[91m";
string cyanColorCode = "\033[96m";
string orangeColorCode = "\033[93m";
string boldColorCode = "\033[1m";
string resetColorCode = "\033[0m";

string nomi[] = {"Test1", "Test2", "Test3", "Test4", "Test5", "Test6"};
string cognomi[] = {"Cognome1", "Cognome2", "Cognome3", "Cognome4", "Cognome5", "Cognome6"};
string abbonamenti[] = {"Pesi", "Zumba", "Pesi", "Crossfit", "Pesi", "Zumba"};
string importo_abb[] = {"10", "20", "30", "40", "50", "60"};


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
    void information() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Informazioni")<<resetColorCode;
        cout<<"Abbonamenti attivi: "<<endl;
        int arrayLen = sizeof(nomi)/sizeof(nomi[0]);
        
        int totale_abbonamenti = 0;
        int totale_abbonamenti_euro = 0;
        for(int i = 0; i < arrayLen; i++) {
            cout<<nomi[i]<<" "<<cognomi[i]<<" - "<<abbonamenti[i]<<" "<<importo_abb[i]<<"€"<<endl;
            totale_abbonamenti++;
            totale_abbonamenti_euro += stoi(importo_abb[i]);
        }
        cout<<endl<<cyanColorCode<<"Abbonamenti attivi: "<<resetColorCode<<greenColorCode<<totale_abbonamenti<<resetColorCode<<endl;
        cout<<cyanColorCode<<"Totale: "<<resetColorCode<<greenColorCode<<totale_abbonamenti_euro<<"€"<<resetColorCode<<endl;
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        while(choose != 3) {
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            if(choose == 1) {
                home();
            } else if (choose == 2) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
                exit(0);
            } else {
                cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            }
        }
    }
    
    void information_service() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Informazioni categoria")<<resetColorCode;
        int arrayLen = sizeof(nomi)/sizeof(nomi[0]);

        string abbonamento;
        cout<<"Inserisci un servizio: "<<greenColorCode;
        cin>>abbonamento;
        cout<<resetColorCode;
        int totale_abbonamenti = 0;
        int totale_abbonamenti_euro = 0;
        for(int i = 0; i < arrayLen; i++) {
            if(abbonamento == abbonamenti[i]) {
                cout<<nomi[i]<<" "<<cognomi[i]<<" - "<<abbonamenti[i]<<" "<<importo_abb[i]<<"€"<<endl;
                totale_abbonamenti++;
                totale_abbonamenti_euro += stoi(importo_abb[i]);
            }
        }
        
        cout<<endl<<cyanColorCode<<"Abbonamenti attivi: "<<resetColorCode<<greenColorCode<<totale_abbonamenti<<resetColorCode<<endl;
        cout<<cyanColorCode<<"Totale: "<<resetColorCode<<greenColorCode<<totale_abbonamenti_euro<<"€"<<resetColorCode<<endl;
        
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        while(choose != 2) {
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            if(choose == 1) {
                home();
            } else if (choose == 2) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
                exit(0);
            } else {
                cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            }
        }
    }
    
    void cognomi_invertiti() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Cognomi invertiti")<<resetColorCode;
        cout<<"Cognomi invertiti:"<<endl;
        
        int cognomiLen = sizeof(cognomi)/sizeof(cognomi[0]);
        
        string cognomi_invertiti[cognomiLen] = {};

        for(int i = 0; i<cognomiLen; i++) {
            cognomi_invertiti[i] = cognomi[cognomiLen-i-1];
            cout<<cognomi_invertiti[i]<<endl;
        } 
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        while(choose != 2) {
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            if(choose == 1) {
                home();
            } else if (choose == 2) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
                exit(0);
            } else {
                cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            }
        }   
    }
    
    void modifica_abbonamento() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Modifica abbonamento")<<resetColorCode;
        string cognome;
        cout<<"Inserisci il cognome dell'utente: "<<greenColorCode;
        cin>>cognome;
        cout<<resetColorCode;
        
        int cognomiLen = sizeof(cognomi)/sizeof(cognomi[0]);
        for(int i = 0; i<cognomiLen; i++) {
            if(cognome == cognomi[i]) {
                cout<<"Prezzo abbonamento attuale: "<<cyanColorCode<<importo_abb[i]<<resetColorCode<<endl;
                int costo = ChooseWhileINT(costo, "Inserisci il nuovo prezzo dell'abbonamento: ");
                importo_abb[i] = to_string(costo);
                cout<<greenColorCode<<"Abbonamento modificato!"<<resetColorCode<<endl;
                cout<<"Prezzo nuovo abbonamento: "<<cyanColorCode<<importo_abb[i]<<resetColorCode<<endl;
                break;
            }
        }
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        while(choose != 2) {
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            if(choose == 1) {
                home();
            } else if (choose == 2) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
                exit(0);
            } else {
                cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            }
        }   
    }
    
    void home() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Menu")<<resetColorCode;
        cout<<"Benvenuto "<<endl<<endl;
        cout<<"1. Informazioni abbonamenti"<<endl;
        cout<<"2. Informazioni abbonamenti da categoria"<<endl;
        cout<<"3. Modifica abbonamento"<<endl;
        cout<<"4. Cognomi invertiti"<<endl<<endl;

        cout<<"5. Esci"<<endl<<endl;

        int choose = 0;
        while(choose != 4) {
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            if(choose == 1) {
                information();
            } else if (choose == 2) {
                information_service();
            } else if (choose == 3) {
                modifica_abbonamento();
            } else if (choose == 4) {
                cognomi_invertiti();
            } else if (choose == 5) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
                exit(0);
            } else {
                cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            }
        }
    }
};

int main()
{
    Program program;
    program.home();

    return 0;
}