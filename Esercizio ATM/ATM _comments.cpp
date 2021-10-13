/*
Website: https://matt05.ml
GitHub: @Matt0550
Realizzare un programma che permetta di simulare la gestione di un ATM (Automated Teller Machine).
L'ATM ha una disponibilità iniziale di 6000€;
L'utente può effettuare sia prelievi che versamenti;
Il limite giornaliero di prelievo è 250€;
Per ogni transazione è necessario indicare il pin;
*/

#include <iostream> // Includo la libreria di base per cout e cin
#include <limits> // Includo la libreria per verificare la correttezza dei numeri inseriti

using namespace std;
string AllowUsername[] = {"Matteo", "Test", "Ciro"}; // Array contentente gli username che possono accedere all'atm
string AllowPassword[] = {"ciao", "gg", "test"}; // Array contentente le password degli username
string AllowPIN[] = {"123F", "124G", "125H"}; // Array contentente i pin degli account
int UserMoney[] = {8276, 1346, 1000}; // Array contentente i soldi dell'account
int UserTransactionLimit[] = {2500, 250, 250}; // Array contentente il limite di transazione dell'account
int ATMLimit = 6000; // Limite soldi atm
int LoginAttempts = 3; // Limite tentativi login


void ClearScreen() {
    #ifdef _WIN32 // Verifica piattaforma windows
    system("CLS"); // Windows os (comando per cancellare la console)
    #else
    system("clear"); // Linux or Mac Windows (comando per cancellare la console)
    #endif
}

// Class taken from my GitHub profile created by me
string CustomSeparatorWithText(string symbol, string text, int length = 10) { // Funzione con parametri e parametri predefiniti
    string center, text1, text2, text3, lati, sym; // Inizializzo variabili
    int length2; // Inizializzo variabili

    sym = symbol;

    int tex = text.length(); // Salvo in una variabile la lunghezza del testo

    for (int i = 1; i < tex+2 + length; i++) {
        symbol = symbol + sym; // Salvo in una variabile i simboli 
    }

    text1 = symbol + "\n";
    length2 = length/2-0; // Divido la lunghezza del testo

    for (int i = 0; i < length2; i++) {
        lati = lati + sym; // Simbolo laterale
    }

    text3 = symbol + "\n" + lati + " " + text + " " + lati + "\n" + symbol + "\n"; // Salvo il tutto in una variabile
    return text3;
}

class Security { // Classe contenente funzioni di login e verifica
    public:
    string username, password; // Creao variabili

    void AskLogin() { // Crea funzione void che non ritorna un valore
        cout<<"Eseguire il login\n";
        cout<<"Username: ";
        cin >> username; // Richiedo username
        
        cout<<"Password: ";
        cin >> password; // Richiedo password
    }
    
    bool VerifyLogin(string username, string password, string check1, string check2) { // Funzione booleana di verifica username e password (true|false)
        if (username == check1 && password == check2) {
            return true;
        } else {
            
            return false;
        }
    }
    
    bool VerifyCode(string code, int i) { // Funzione booleana per verificare la correttezza del PIN
        const char AlphabetUpper[26] = {
             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z'
        }; // Array contenente tutte le lettere dell'alfabeto in maiuscolo. Ogni lettere è associata ad un numero (index)
        
        int sum = 0;
        char letter;
        for (char ch : code) { // Separo il codice in caratteri singoli fornito dal parametro della funzione
            if (isdigit(ch)) { // Verifico che il carattere sia un numero (digit)
                sum += ch - 48; // Converto il numero in intero (48 è un valore della tabella ascii) e lo aggiungo alla variabile
            } else {
                letter = ch; // Salvo la sola lettere in una variabile
            }
        }

        int PINLen = sizeof(AllowPIN)/sizeof(AllowPIN[0]); // Calcolo la lungezza dell'array contenenti i PIN

        
        if (letter == AlphabetUpper[sum-1] && code == AllowPIN[i] && code.length() == 4) { // Algoritmo per la verifica del PIN. Verifica che la lettera del codice equivale alla lettera dell'alfabeto.
                                                                                           // Inoltre verifica che il PIN sia uguale a quello dell'account (AllowPIN) e che la sua lunghezza sia di 4 caratteri.
            return true;
            
        } else {
            return false;
        }
        
        return false;
    }

};


class ATM { // Creo una nuova classe contenente il programma principale
    public:
    void Deposita(int i) { // Creao una nuova funzione (void = nessun return) con parametri (index dell'account)
        Security securityATM; // Inizializzo la classe
        cout << CustomSeparatorWithText("=", "Deposita") << endl; // Richiamo la funzione per scrivere il testo centrato
        
        cout << "Nel tuo conto ci sono " << UserMoney[i] << "€" << endl;
        cout<<"Il tuo limite per transazione è di "<<UserTransactionLimit[i]<<"€"<<endl<<endl;
        
        int attempt;
        
        while(true) {
            string PIN;
            cout << "\nInserire il PIN di sicurezza (digitare 'back' per tornare indietro): ";
            cin >> PIN;
            if (securityATM.VerifyCode(PIN, i)) { // Verifica la correttezza del PIN. Ritorna true se il PIN è corretto
                int soldi;
                cout<<"\nQuanto vuoi depositare (digitare '0' per annullare)? ";
                cin>>soldi;
                
                if (!cin) { // Verifico la correttezza dell'input
                    cout << "Input non valido! " << endl; // Sono stati inseriti caratteri non validi (es. lettere)
                    cin.clear(); // Cancello l'input
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignoro tutti i caratteri che non siano numeri (numeric_limits<streamsize>::max() viene usata per prendere tutti i caratteri dell'input)
                    
                } else {
                    if (soldi > UserTransactionLimit[i]) { // Verifico che la transizione non superi i 250€
                        cout<<"\nNon puoi depositare quella cifra!";
                        
                    } else if (soldi == 0) { // Se inserisco 0 il programma ritorna alla home
                        ClearScreen(); // Cancello la console di debug (schermo)
                        ATM::welcome(i); // Vado alla home
                    
                    } else if (soldi < 0) { // Verifico che i valori inseriti non siano negativi
                        cout<<"\nNon puoi inserire valori negativi!";
                        
                    } else {
                        UserMoney[i] = UserMoney[i] + soldi; // Aggiunge ai soldi dell'utente i soldi inseriti
                        ATMLimit = ATMLimit + soldi;
                        
                        cout<<"\nTransazione eseguita!"<<endl;
                        cout<<"\nTi rimangono "<<UserMoney[i]<<"€"<<endl<<endl;
                        
                    }
                }

            } else if (PIN == "back") { // Se il PIN è back il programma ritorna alla home
                ClearScreen(); // Cancello la console di debug (schermo)
                ATM::welcome(i); // Vado alla home
                
            } else {
                cout<<"\nPIN di sicurezza errato!"<<endl;
            }
        }
    }
    
    void Preleva(int i) {
        Security securityATM;
        
        cout << CustomSeparatorWithText("=", "Preleva") << endl; // Richiamo la funzione per scrivere il testo centrato
        
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
                    cin.clear(); // Cancello l'input
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignoro i caratteri non validi
                    
                } else {
                    if (soldi > UserMoney[i]) { // Verifico che l'utente abbia abbastanza soldi per prelevare
                        cout<<"\nNon hai abbastanza soldi per poter prelevare!";
                        
                    } else if (soldi > UserTransactionLimit[i]) {
                        cout<<"\nNon puoi prelevare quella cifra!";
                        
                    } else if (soldi > ATMLimit) { // Verifico che l'ATM abbia abbastanza soldi da dare all'utente (parte da 6000€)
                        cout<<"\nL'ATM non può soddisfare questa richiesta!";
                        
                    } else if (soldi < 0) {
                        cout<<"\nNon puoi inserire valori negativi!";
                        
                    } else if (soldi == 0) { // Se scrivo 0 il programma torna alla home
                        ClearScreen(); // Cancello la console di debug (schermo)
                        ATM::welcome(i); // Vado alla home
                    
                    } else {
                        UserMoney[i] = UserMoney[i] - soldi; // Rimuovo i soldi dall'account
                        ATMLimit = ATMLimit - soldi; // Rimuovo i soldi dall'ATM
                        
                        cout<<"\nTransazione eseguita!"<<endl;
                        cout<<"\nTi rimangono "<<UserMoney[i]<<"€"<<endl<<endl;
                    }
                }
            
            } else if (PIN == "back") { // Se il PIN è back il programma ritorna alla home
                ClearScreen(); // Cancello la console di debug (schermo)
                ATM::welcome(i); // Vado alla home
                
            } else {
                cout<<"\nPIN di sicurezza errato!"<<endl;
            }
        }
    }
    
    void Info(int i) { // Creo funzione con parametri
        while(true) {
            cout << CustomSeparatorWithText("=", "ATM Info") << endl; // Richiamo la funzione per scrivere il testo centrato
            cout << "Conto: " << UserMoney[i] << "€" << endl;
            cout << "Limite per transazione: " << UserTransactionLimit[i] << "€" << endl;
            cout << "ATM: " << ATMLimit << "€" << endl;
            
            string scelta;
            cout << "\nCosa vuoi fare (digitare 'back' per tornare indietro)? ";
            cin >> scelta;
            ClearScreen(); // Cancello la console di debug (schermo)
            ATM::welcome(i); // Vado alla home

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
                ClearScreen(); // Cancello la console di debug (schermo)
                ATM::welcome_text(i); // Richiamo la funzione per far vedere i testi della home
                cout <<"Scelta non valida!"<<endl<<endl;
                cin.clear(); // Cancello l'input
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignoro i caratteri non validi

            } else {
                if (scelta == 1) {
                    ClearScreen();
                    Deposita(i); // Richiamo la funzione passando come parametri l'index dell'account (indice)
                    break;
                    
                } else if (scelta == 2) {
                    ClearScreen();
                    Preleva(i); // Richiamo la funzione passando come parametri l'index dell'account (indice)
                    break;
                    
                } else if (scelta == 3) {
                    ClearScreen();
                    Info(i); // Richiamo la funzione passando come parametri l'index dell'account (indice)
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
        ClearScreen(); // Cancello la console di debug (schermo)
        welcome_text(i); // Richiamo la funzione
        menu(i); // Richiamo la funzione
    };
    
};

int main()
{
    Security securityATM; // initialize class
    ATM atm; // initialize class
    
    int UsernameLen = sizeof(AllowUsername)/sizeof(AllowUsername[0]); // Calcolo quanti account ci sono (array)
    int attempt;
    
    while (++attempt <= LoginAttempts) { // Eseguo un while finche finchè i tentativi saranno minori o uguali a 3
        securityATM.AskLogin();

        for(int i = 0; i < UsernameLen; i++) {
            
            if (securityATM.VerifyLogin(securityATM.username, securityATM.password, AllowUsername[i], AllowPassword[i])) { // Richiamo la funzione booleana (true|false). 
                                                                                                                           // Il primo parametro (securityATM.username ) deve essere uguale al secondo (AllowUsername[i])
                                                                                                                           // Il secondo parametro (securityATM.password ) deve essere uguale al secondo (AllowPassword[i])
                atm.welcome(i); // Richiamo la funzione che mi porta alla home
                break;
                
            } else {
                continue;
            }
        }
        cout<<"Username o password errati!\n"; 
        cout<<"Tentativi rimasti: " << LoginAttempts-attempt << endl << endl; 
    }
    cout<<"Tentativi esauriti!"; // Se i tentativi sono uguali o maggiori a 3 il programma si chiude

    return 0;
}