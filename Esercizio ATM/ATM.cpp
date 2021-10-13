/*
Website: https://matt05.ml
GitHub: @Matt0550
Realizzare un programma che permetta di simulare la gestione di un ATM (Automated Teller Machine).
L'ATM ha una disponibilità iniziale di 6000€;
L'utente può effettuare sia prelievi che versamenti;
Il limite giornaliero di prelievo è 250€;
Per ogni transazione è necessario indicare il pin;
*/

#include <iostream>
#include <limits>

using namespace std;
string AllowUsername[] = {"Matteo", "Test", "Ciro"};
string AllowPassword[] = {"ciao", "gg", "test"};
string AllowPIN[] = {"123F", "124G", "125H"};
int UserMoney[] = {8276, 1346, 1000};
int UserTransactionLimit[] = {2500, 250, 250};
int ATMLimit = 6000;
int LoginAttempts = 3;


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

class Security {
    public:
    string username, password;

    void AskLogin() {
        cout<<"Eseguire il login\n";
        cout<<"Username: ";
        cin >> username;
        
        cout<<"Password: ";
        cin >> password;
    }
    
    bool VerifyLogin(string username, string password, string check1, string check2) {
        if (username == check1 && password == check2) {
            return true;
        } else {
            
            return false;
        }
    }
    
    bool VerifyCode(string code, int i) {
        const char AlphabetUpper[26] = {
             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z'
        };
        
        int sum = 0;
        char letter;
        for (char ch : code) { // for arrays
            if (isdigit(ch)) {
                sum += ch - 48; // Convert to number. 48 is 0 in ascii table
            } else {
                letter = ch;
            }
        }

        int PINLen = sizeof(AllowPIN)/sizeof(AllowPIN[0]);

        
        if (letter == AlphabetUpper[sum-1] && code == AllowPIN[i] && code.length() == 4) {
            return true;
            
        } else {
            return false;
        }
        
    
        return false;
    }

};


class ATM {
    public:
    void Deposita(int i) {
        Security securityATM;
        cout << CustomSeparatorWithText("=", "Deposita") << endl;
        
        cout << "Nel tuo conto ci sono " << UserMoney[i] << "€" << endl;
        cout<<"Il tuo limite per transazione è di "<<UserTransactionLimit[i]<<"€"<<endl<<endl;
        
        int attempt;
        
        while(true) {
            string PIN;
            cout << "\nInserire il PIN di sicurezza (digitare 'back' per tornare indietro): ";
            cin >> PIN;
            if (securityATM.VerifyCode(PIN, i)) {
                int soldi;
                cout<<"\nQuanto vuoi depositare (digitare '0' per annullare)? ";
                cin>>soldi;
                
                if (!cin) {
                    cout << "Input non valido! " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignora le stringhe
                    
                } else {
                    if (soldi > UserTransactionLimit[i]) {
                        cout<<"\nNon puoi depositare quella cifra!";
                        
                    } else if (soldi == 0) {
                        ClearScreen();
                        ATM::welcome(i);
                    
                    } else if (soldi < 0) {
                        cout<<"\nNon puoi inserire valori negativi!";
                        
                    } else {
                        UserMoney[i] = UserMoney[i] + soldi;
                        ATMLimit = ATMLimit + soldi;
                        
                        cout<<"\nTransazione eseguita!"<<endl;
                        cout<<"\nTi rimangono "<<UserMoney[i]<<"€"<<endl<<endl;
                        
                    }
                }

            } else if (PIN == "back") {
                ClearScreen();
                ATM::welcome(i);
                
            } else {
                cout<<"\nPIN di sicurezza errato!"<<endl;
            }
        }
    }
    
    void Preleva(int i) {
        Security securityATM;
        
        cout << CustomSeparatorWithText("=", "Preleva") << endl;
        
        cout << "Nel tuo conto ci sono " << UserMoney[i] << "€" << endl;
        cout<<"Il tuo limite per transazione è di "<<UserTransactionLimit[i]<<"€"<<endl<<endl;
        
        while(true) {
            string PIN;
            cout << "\nInserire il PIN di sicurezza (digitare 'back' per tornare indietro): ";
            cin >> PIN;
            
            if (securityATM.VerifyCode(PIN, i)) {
                int soldi;
                cout<<"\nQuanto vuoi prelevare (digitare '0' per annullare)? ";
                cin>>soldi;
                
                if (!cin) {
                    cout << "Input non valido! " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignora le stringhe
                    
                } else {
                    if (soldi > UserMoney[i]) {
                        cout<<"\nNon hai abbastanza soldi per poter prelevare!";
                        
                    } else if (soldi > UserTransactionLimit[i]) {
                        cout<<"\nNon puoi prelevare quella cifra!";
                        
                    } else if (soldi > ATMLimit) {
                        cout<<"\nL'ATM non può soddisfare questa richiesta!";
                        
                    } else if (soldi < 0) {
                        cout<<"\nNon puoi inserire valori negativi!";
                        
                    } else if (soldi == 0) {
                        ClearScreen();
                        ATM::welcome(i);
                    
                    } else {
                        UserMoney[i] = UserMoney[i] - soldi;
                        ATMLimit = ATMLimit - soldi;
                        
                        cout<<"\nTransazione eseguita!"<<endl;
                        cout<<"\nTi rimangono "<<UserMoney[i]<<"€"<<endl<<endl;
                    }
                }
            
            } else if (PIN == "back") {
                ClearScreen();
                ATM::welcome(i);
                
            } else {
                cout<<"\nPIN di sicurezza errato!"<<endl;
            }
        }
    }
    
    void Info(int i) {
        while(true) {
            cout << CustomSeparatorWithText("=", "ATM Info") << endl;
            cout << "Conto: " << UserMoney[i] << "€" << endl;
            cout << "Limite per transazione: " << UserTransactionLimit[i] << "€" << endl;
            cout << "ATM: " << ATMLimit << "€" << endl;
            
            string scelta;
            cout << "\nCosa vuoi fare (digitare 'back' per tornare indietro)? ";
            cin >> scelta;
            ClearScreen();
            ATM::welcome(i);

        }
    }
    
    void menu(int i) {
        while(true) {
            cout<<"1. Deposita"<<endl;
            cout<<"2. Preleva"<<endl;
            cout<<"3. ATM Info"<<endl<<endl;
            cout<<"4. Esci"<<endl;
            int scelta;
            cout << endl << "Cosa vuoi fare? ";
            cin >> scelta;
            if (!cin) {
                ClearScreen();
                ATM::welcome_text(i);
                cout <<"Scelta non valida!"<<endl<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignora le stringhe

            } else {
                if (scelta == 1) {
                    ClearScreen();
                    Deposita(i);
                    break;
                    
                } else if (scelta == 2) {
                    ClearScreen();
                    Preleva(i);
                    break;
                    
                } else if (scelta == 3) {
                    ClearScreen();
                    Info(i);
                    break;
                    
                } else if (scelta == 4) {
                    cout << "\n\nArrivederci!";
                    exit(0);
                }
            }
        }
    }
    
    void welcome_text(int i) {
        cout<<"Benvenuto "<<AllowUsername[i]<<endl;
        cout<<"Nel tuo conto ci sono "<<UserMoney[i]<<"€"<<endl;
        cout<<"Il tuo limite per transazione è di "<<UserTransactionLimit[i]<<"€"<<endl<<endl;
    }
    
    void welcome(int i) {
        ClearScreen();
        welcome_text(i);
        menu(i);
    
    };
    
};

int main()
{
    Security securityATM; // initialize class
    ATM atm; // initialize class
    
    int UsernameLen = sizeof(AllowUsername)/sizeof(AllowUsername[0]);
    int attempt;
    
    while (++attempt <= LoginAttempts) {
        securityATM.AskLogin();

        for(int i = 0; i < UsernameLen; i++) {
            
            if (securityATM.VerifyLogin(securityATM.username, securityATM.password, AllowUsername[i], AllowPassword[i])) {
                atm.welcome(i);
                break;
                
            } else {
                continue;
            }
        }
        cout<<"Username o password errati!\n";
        cout<<"Tentativi rimasti: " << LoginAttempts-attempt << endl << endl;
    }
    cout<<"Tentativi esauriti!";

    return 0;
}