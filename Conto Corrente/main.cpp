/*
Website: https://matt05.ml
GitHub: @Matt0550
Implementare un programma che rappresenti un conto corrente bancario.
Il conto corrente in questione conserva i seguenti dati:
- Nome e cognome dell'intestatario
- Data di nascita
- Saldo sul conto
- Data di apertura del conto
- Nome della banca
- Codice fiscale
Il conto ha le seguenti funzionalità:
- Visualizza informazioni conto
- Versamento
- Preleva
Il programma è dotato di un menu che consente all'utente di scegliere una delle precedenti opzioni
*/

#include <iostream>
#include <vector> 
#include <algorithm>
#include <ctime>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string BankName = "Rapisardi Bank";
string greenColorCode = "\033[92m";
string redColorCode = "\033[91m";
string cyanColorCode = "\033[96m";
string orangeColorCode = "\033[93m";
string boldColorCode = "\033[1m";
string resetColorCode = "\033[0m";

int indice;

vector<vector<string>>conti_correnti = {
    {"Matt05", "1234", "Test", "Ciao", "17/12/2005", "CRBNGA05R65D969E", "24/12/2003", "10000", "IT60X0542811101000000123456", "2000"},
    {"gino", "1234", "agf", "GGGGGG", "13/12/1992", "IT", "22/13/1993", "10000", "IT17X0331713401000001234567", "2000"},

    // Username, Password, Nome, Cognome, Data di nascita, Codice fiscale, Data di apertura conto, Saldo sul conto, IBAN, limite prelievo
};

vector<string>vec_lista_movimenti;

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

string thousandSeparator(int n)
{
    string ans = "";
    // Convert the given integer
    // to equivalent string
    string num = to_string(n);
    // Initialise count
    int count = 0;
    // Traverse the string in reverse
    for (int i = num.size() - 1;
         i >= 0; i--) {
        count++;
        ans.push_back(num[i]);
        // If three characters
        // are traversed
        if (count == 3) {
            ans.push_back('.');
            count = 0;
        }
    }
    // Reverse the string to get
    // the desired output
    reverse(ans.begin(), ans.end());
    // If the given string is
    // less than 1000
    if (ans.size() % 4 == 0) {
        // Remove ','
        ans.erase(ans.begin());
    }
    return ans;
}

class Date {
    public:
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
            
        }
        if ((month < 1) || (month > 12)) {
            return false; // Il mese è minore di 1 o maggiore di 12
        }
        
        return true;
        
    }
    
    string check_date(string date) {
        char* str = const_cast<char*>(date.c_str());

        char *day = strtok(str, "/");
        char *month = strtok(NULL, "/");
        char *year = strtok(NULL, "/");

        string var;

        var = string(day) + "/" + string(month) + "/" + string(year);
        
        if(stoi(day) < 10) {
            var = "0" + string(day) + "/" + string(month) + "/" + string(year);    
        }
        if (stoi(month) < 10) {
            var = string(day) + "/" + "0" + string(month) + "/" + string(year);
        }
        if(stoi(day) < 10 && stoi(month) < 10) {
            var = "0" + string(day) + "/" + "0" + string(month) + "/" + string(year);
        }
        
        if(!VerifyDateFormat(stoi(day), stoi(month), stoi(year))) {
            return var + " " + redColorCode + "(Invalida)" + resetColorCode;
        } 

        return var;
    }
    
    string GetDate() {
        time_t ttime = time(0); // Initialize time
        tm *local_time = localtime(&ttime); // Get local time
        
        int day, month, year;
        
        day = local_time->tm_mday; // Get day
        month = 1 + local_time->tm_mon; // Get month
        year = 1900 + local_time->tm_year; // Get year. 1900 default year
  
        return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
    }

};

bool check_codfisc(string code) {
    if(code.length() != 16) { // Check only lenght and chars
        return false;
    } else {
        int uppercase = 0;
        int lowercase = 0;
        int digit = 0;
        int special_character = 0;
        for (int i = 0; i < code.length(); i++) {
            if (code[i] >= 'A' && code[i] <= 'Z'){
                uppercase++;
            } else if(code[i] >= 'a' && code[i] <= 'z') {
                lowercase++;
            } else if(code[i]>= '0' && code[i]<= '9') {
                digit++;
            } else {
                special_character++;
            }
        }
        
        if(uppercase <= 0) {
            return false;
        } else if(lowercase > 0) {
            return false;
        } else if(special_character > 0) {
            return false;
        } else if(uppercase == 9 && digit == 7) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

class OpenAccount {
    public:
    Date date;
    
    bool verify_password(string nome, string cognome, string username, string password, string password_confirm) {
        if(password != password_confirm) {
            cout<<redColorCode<<"Le due password sono diverse!"<<resetColorCode<<endl;
            return false;
        }
        if (password.find(nome) != string::npos or password.find(cognome) != string::npos or password.find(username) != string::npos) {
            cout<<redColorCode<<"La password non può contenere il tuo nome, cognome o username!"<<resetColorCode<<endl;
            return false;
        }
        if (password.length() < 8 && password.length() > 0) {
            cout<<redColorCode<<"La password è troppo corta!"<<resetColorCode<<endl;
            return false;
        } else if (password.length() > 64) {
            cout<<redColorCode<<"La password è troppo lunga!"<<resetColorCode<<endl;
            return false;
        }
        
        int uppercase = 0;
        int lowercase = 0;
        int digit = 0;
        int special_character = 0;
        for (int i = 0; i < password.length(); i++) {
            if (password[i] >= 'A' && password[i] <= 'Z'){
                uppercase++;
            } else if(password[i] >= 'a' && password[i] <= 'z') {
                lowercase++;
            } else if(password[i]>= '0' && password[i]<= '9') {
                digit++;
            } else {
                special_character++;
            }
        }
        
        if(uppercase > 0 && lowercase > 0 && digit > 0 && special_character > 0) {
            return true;
        } else {
            cout<<redColorCode<<"La password deve contenere almeno una lettera maiuscola, una lettera minuscola, un numero e un carattere speciale!"<<resetColorCode<<endl;
            return false;
        }
        
    }
    
    string generateIBAN() {
        string numbers = "123456789";
        string capitals = "ABCDEFGHIJKLMNPQRSTUVWXYZ";

        string num1, num2, lettera;
    
        srand(time(NULL)); // Inizializziamo numeri casuali 
        
        for (int i = 0; i < 2; ++i) {
            num1 += numbers[rand() % numbers.length()];
        }
        
        for (int i = 0; i < 21; ++i) {
            num2 += numbers[rand() % numbers.length()];
        }
        
        lettera += capitals[rand() % capitals.length()];
        return "IT"+num1+lettera+"0"+num2;
    }

    void createAccount() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Apri un conto")<<resetColorCode<<endl;
        cout<<"Benvenuto nella procedura guidata per aprire un nuovo conto corrente.\nInserisci i seguenti dati:"<<endl;
        string nome, cognome, luogo_nascita, provincia, sesso, data_nascita, codice_fiscale, username, password, password_confirm, datefull;

        cout<<"Nome dell'intestatario: "<<greenColorCode;
        cin>>nome;
        cout<<resetColorCode;
        nome[0] = toupper(nome[0]);

        cout<<"Cognome dell'intestatario: "<<greenColorCode;
        cin>>cognome;
        cout<<resetColorCode;
        cognome[0] = toupper(cognome[0]);
        
        cout<<"Luogo di nascita: "<<greenColorCode;
        cin>>luogo_nascita;
        cout<<resetColorCode;
        luogo_nascita[0] = toupper(luogo_nascita[0]);
        
        cout<<"Provincia (SIGLA): "<<greenColorCode;
        cin>>provincia;
        cout<<resetColorCode;
        transform(provincia.begin(), provincia.end(), provincia.begin(), ::toupper);

        while(true) {
            cout<<"Sesso (M/F): "<<greenColorCode;
            cin>>sesso;
            cout<<resetColorCode;
            if(sesso == "M" or sesso == "F" or sesso == "m" or sesso == "f") {
                break;
            } else {
                cout<<redColorCode<<"Sesso non valido!"<<resetColorCode<<endl;
            }
        }
        
        transform(sesso.begin(), sesso.end(), sesso.begin(), ::toupper);
        int d, m, y;
        while(!date.VerifyDateFormat(d,m,y)) {
            cout<< "Data di nascita dell'intestatario (gg/mm/aaaa): " << greenColorCode;
    
            int d = date.ChooseWhileINTDate(d, "Data di nascita dell'intestatario (gg/mm/aaaa): ", "Inserisci il mese: ");
            int m = date.ChooseWhileINTDate(m, "Data di nascita dell'intestatario (gg/mm/aaaa): ", "Inserisci l'anno: ");
            int y = date.ChooseWhileINTDate(y, "Data di nascita dell'intestatario (gg/mm/aaaa): ", "");
            if(!date.VerifyDateFormat(d,m,y)) {
                cout<<redColorCode<<"Data non valida!"<<resetColorCode<<endl;
            } else {
                datefull = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
                data_nascita = date.check_date(datefull);
                break;
            }
        }

        while(!check_codfisc(codice_fiscale)) {
            cout<<"Codice fiscale dell'intestatario: "<<greenColorCode;
            cin>>codice_fiscale;
            cout<<resetColorCode;
            transform(codice_fiscale.begin(), codice_fiscale.end(), codice_fiscale.begin(), ::toupper);
            if(!check_codfisc(codice_fiscale)) {
                cout<<redColorCode<<"Codice fiscale non valido!"<<resetColorCode<<endl;
            }

        }
        
        while(true) {
            cout<<"Username dell'account: "<<greenColorCode;
            cin>>username;
            cout<<resetColorCode;
            bool esci = false;
            for(int i = 0; i < conti_correnti.size(); i++) {
                if(username == conti_correnti[i][0]) {
                    esci = false;
                    cout<<redColorCode<<"Username già in uso!"<<resetColorCode<<endl;
                    break;
                } else {
                    esci = true;
                    break;
                }
            }
            if(esci) {
                break;
            }
        }
        
        while(!verify_password(nome, cognome, username, password, password_confirm)) {
            cout<<"Password dell'account: "<<greenColorCode;
            cin>>password;
            cout<<resetColorCode;
            
            cout<<"Conferma password: "<<greenColorCode;
            cin>>password_confirm;
            cout<<resetColorCode;
        }
        
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Riepilogo dati")<<resetColorCode<<endl;
        cout<<"Rileggi attentamente i dati e conferma l'apertura del conto corrente."<<endl;
        
        cout<<"Nome: "<<greenColorCode<<nome<<resetColorCode<<endl;
        cout<<"Cognome: "<<greenColorCode<<cognome<<resetColorCode<<endl;
        cout<<"Luogo di nascita: "<<greenColorCode<<luogo_nascita<<resetColorCode<<endl;
        cout<<"Provincia: "<<greenColorCode<<provincia<<resetColorCode<<endl;
        cout<<"Sesso: "<<greenColorCode<<sesso<<resetColorCode<<endl;
        cout<<"Data di nascita: "<<greenColorCode<<data_nascita<<resetColorCode<<endl;
        cout<<"Codice fiscale: "<<greenColorCode<<codice_fiscale<<resetColorCode<<endl<<endl;
        cout<<"Username: "<<greenColorCode<<username<<resetColorCode<<endl;
        cout<<"Password: "<<greenColorCode<<password<<resetColorCode<<endl<<endl;
        
        cout<<orangeColorCode<<"In caso di dati errati, sarà necessario eseguire nuovamente la registrazione!"<<resetColorCode<<endl;
        string choose;
        while(choose != "back") {
            cout<<"I dati sono corretti (si/no)? "<<greenColorCode;
            cin>>choose;
            cout<<resetColorCode;
            
            if(choose=="si" or choose=="Si" or choose=="SI" or choose=="iS") {
                conti_correnti.push_back({username, password, nome, cognome, datefull, codice_fiscale, date.GetDate(), "0", generateIBAN(), "2000"});
                ClearScreen();
                cout<<greenColorCode<<"Registrazione avvenuta con successo!"<<resetColorCode<<endl;
                cout<<cyanColorCode<<CustomSeparatorWithText("=", BankName)<<resetColorCode<<endl;
                cout<<"Benvenuto, cosa vuoi fare?"<<endl;
                cout<<"1. Accedi ad un conto corrente\n2. Apri un conto corrente\n\n3. Esci\n\n";
                break;
            } else {
                createAccount();
            }
        }
    }  
};

class Program {
    public:
    bool verify_login(string username, string password) {
        for(int i = 0; i < conti_correnti.size(); i++){
            if(username == conti_correnti[i][0] && password == conti_correnti[i][1]) {
                indice = i;
                return true;
            }
        }
        return false;
    }
    
    bool check_money(string username, string password, int money, int choose) {
        if(verify_login(username, password)) {
            if(money <= 0) {
                return false;
            } else {
                if(username == conti_correnti[indice][0]) {
                    if(money > 1000) {
                        if(!check_account(username, password)) {
                            cout<<orangeColorCode<<"\nA causa di dati errati presenti nell'account, le transizioni che superano i 1.000€ non possono essere eseguite!"<<resetColorCode<<endl;
                            cout<<"\n1. Indietro\n2. Esci"<<endl<<endl;
                            int choose = 1;
                            while(choose != 0) {
                                choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                                if(choose == 1) {
                                    menu(username, password);
                                    
                                } else if(choose == 2) {
                                    cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode;
                                    exit(0);
                                }
                            }
                        }
                        string password_verify, codice_fiscale_verify;
                        cout<<"Per transizioni superiori a 1.000€ è necessario verificare la propria identità."<<endl;
                        cout<<"Inserisci la tua password: "<<greenColorCode;
                        cin>>password_verify;
                        cout<<resetColorCode;
                        
                        cout<<"Inserisci il tuo codice fiscale: "<<greenColorCode;
                        cin>>codice_fiscale_verify;
                        cout<<resetColorCode;
                        if(password != password_verify && codice_fiscale_verify != conti_correnti[indice][5]) {
                            return false;
                        }
                    }
                    
                    if(choose == 2) {
                        return true;
                        
                    } else if(choose == 3) {
                        if(money > stoi(conti_correnti[indice][7])) {
                            return false;
                        } else {
                            return true;
                        }
                        
                    } else if(choose == 4) {
                        if(money > stoi(conti_correnti[indice][7])) {
                            return false;
                        } else {
                            return true;
                        }
                    }
                    
                }
            }
            return false;
            
        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
        return false;
    }
    
    bool check_iban(string username, string password, string iban) {
        if(verify_login(username, password)) {
            if(iban.length() < 15) {
                return false;
            } else {
                int uppercase = 0;
                int lowercase = 0;
                int digit = 0;
                int special_character = 0;
                for (int i = 0; i < iban.length(); i++) {
                    if (iban[i] >= 'A' && iban[i] <= 'Z'){
                        uppercase++;
                    } else if(iban[i] >= 'a' && iban[i] <= 'z') {
                        lowercase++;
                    } else if(iban[i]>= '0' && iban[i]<= '9') {
                        digit++;
                    } else {
                        special_character++;
                    }
                }
                
                if(uppercase <= 0) {
                    return false;
                } else if(lowercase > 0) {
                    return false;
                } else if(special_character > 0) {
                    return false;
                } else if(uppercase > 0 && digit > 0) {
                    if(iban.substr(0,2) == "IT") {
                        if(iban.length() != 27) {
                            return false;
                        }
                    }
                    for(int a = 0; a < conti_correnti.size(); a++) {
                        if(iban == conti_correnti[a][8] && iban != conti_correnti[indice][8]) {
                            return true;
                        }
                    }
                }
            }
  
        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
        return false;
    }

    Date date;
    bool check_account(string username, string password) {
        if(verify_login(username, password)) {
            if(username == conti_correnti[indice][0]) {
                string codice_fiscale, data_nascita, data_creazione;
                if(!check_codfisc(conti_correnti[indice][5])) {
                    codice_fiscale = conti_correnti[indice][5] + " "+ redColorCode + "(Invalido)" + resetColorCode;
                } else {
                    codice_fiscale = conti_correnti[indice][5];
                }
                
                data_nascita = date.check_date(conti_correnti[indice][4]);
                data_creazione = date.check_date(conti_correnti[indice][6]);
                
                if(data_nascita != date.check_date(conti_correnti[indice][4]) or data_creazione != date.check_date(conti_correnti[indice][6]) or codice_fiscale != conti_correnti[indice][5]) {
                    return false;
                } else {
                    return true;
                }
            }
            
        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
        return false;
    }
    
    void send_money(string username, string password) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Bonifico bancario")<<resetColorCode<<endl;
        if(verify_login(username, password)) {
            if(username == conti_correnti[indice][0]) {
                string iban;
                while(!check_iban(username, password, iban)) {
                    cout<<"Inserisci l'IBAN del destinatario (back. Indietro): "<<greenColorCode;
                    cin>>iban;
                    cout<<resetColorCode;
                    
                    if(!check_iban(username, password, iban)) {
                        cout<<redColorCode<<"IBAN non valido o non trovato!"<<resetColorCode<<endl;
                    } else {
                        cout<<"L'IBAN " << boldColorCode << iban << resetColorCode << " è corretto? (si/no) "<< greenColorCode;
                        string choose;
                        cin>>choose;
                        cout<<resetColorCode;
                        
                        if (choose=="no" or choose=="No" or choose=="NO" or choose=="nO") {
                            send_money(username, password);
                        }
                    }
                    
                    if(iban == "back" or iban == "0") {
                        menu(username, password);
                    }
                }
                
                int money = 1;
                while(money != 0) {
                    money = ChooseWhileINT(money, "Quanto vuoi inviare (0. Indietro)? €");
                    if(money == 0) {
                        menu(username, password);
                    }
                    
                    if(check_money(username, password, money, 4)) {
                        string causale;
                        cout<<"Inserisci la causale del bonifico (back. Indietro): "<<greenColorCode;
                        cin>>causale;
                        cout<<resetColorCode;
                        if(causale == "back") {
                            send_money(username, password);
                        }
                        
                        for(int x = 0; x < conti_correnti.size(); x++) {
                            if(iban == conti_correnti[x][8]) {
                                string nome;
                                cout<<"Inserisci il nome del destinatario (back. Indietro): "<<greenColorCode;
                                cin>>nome;
                                cout<<resetColorCode;
                            
                                string cognome;
                                cout<<"Inserisci il cognome del destinatario (back. Indietro): "<<greenColorCode;
                                cin>>cognome;
                                cout<<resetColorCode;

                                if(nome == "back" or nome == "0" or cognome == "back" or cognome == "0") {
                                    menu(username, password);
                                }
                                
                                nome[0] = toupper(nome[0]);
                                cognome[0] = toupper(cognome[0]);
                                
                                if(nome == conti_correnti[x][2] && cognome == conti_correnti[x][3]) {
                                    int money_start2 = stoi(conti_correnti[indice][7]);
                           
                                    int money_deposita2 = money_start2-money;
                                    
                                    conti_correnti[indice][7] = to_string(money_deposita2);
                                    
                                    cout<<"Saldo sul tuo conto aggiornato: "<<greenColorCode<<thousandSeparator(stoi(conti_correnti[indice][7]))<<"€"<<resetColorCode<<endl<<endl;
                                    
                                    vec_lista_movimenti.push_back("Bonifico bancario di " + thousandSeparator(money) + "€" + " da IBAN " + conti_correnti[indice][8] + " verso IBAN " + iban + " - causale: " + causale + "\n");
                
                                    int money_start = stoi(conti_correnti[x][7]);
                            
                                    int money_deposita = money_start+money;
                                    
                                    conti_correnti[x][7] = to_string(money_deposita);
                                    
                                    cout<<"Destinatario: "<<greenColorCode<<conti_correnti[x][3]<<" "<<conti_correnti[x][2]<<resetColorCode<<endl;
                                    cout<<"IBAN destinatario: "<<greenColorCode<<iban<<resetColorCode<<endl;
                                    cout<<"Causale: "<<greenColorCode<<causale<<resetColorCode<<endl;
        
                                    cout<<"\n1. Indietro\n2. Esci"<<endl<<endl;
                                    int choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                                    if(choose == 1) {
                                        menu(username, password);
                                        
                                    } else if(choose == 2) {
                                        cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode;
                                        exit(0);
                                    }  
                                } else {
                                   cout<<endl<<redColorCode<<"Il nome o il cognome non corrispondono al destinatario!\n"<<resetColorCode;
                                }
                            }
                        }
                    } else {
                        cout<<redColorCode<<"Fondi insufficienti!"<<resetColorCode<<endl;
                    }
                }
            }
            
        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
    }
    
    void lista_movimenti(string username, string password) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Lista movimenti")<<resetColorCode<<endl;
        if(verify_login(username, password)) {
            if(vec_lista_movimenti.size() == 0) {
                cout<<orangeColorCode<<"Nessun dato disponibile!"<<resetColorCode<<endl;

            } else {
                for(int i = 0; i < vec_lista_movimenti.size(); i++) {
                    cout<<vec_lista_movimenti[i];
                }
            }
            
            int choose = 0;
            cout<<"\n1. Indietro\n2. Esci"<<endl<<endl;
            while(choose != 3) {
                int choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                if(choose == 1) {
                    menu(username, password);
                } else if(choose == 2) {
                    cout<<endl<<redColorCode<<"Uscita in corso..."<<redColorCode;
                    exit(0);
                } else {
                    cout<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                }
            }
        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
    }
    
    void deposita(string username, string password) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Versamento")<<resetColorCode<<endl;
        
        if(verify_login(username, password)) {
            if(username == conti_correnti[indice][0]) {
                cout<<"Saldo attuale: "<<greenColorCode<<thousandSeparator(stoi(conti_correnti[indice][7]))<<"€"<<resetColorCode<<endl<<endl;
                int money = 0;
                while(money != 3) {
                    int money = ChooseWhileINT(money, "Quanto vuoi depositare (0. Indietro)? €");
                    if(money == 0) {
                        menu(username, password);
                    }
                    if(check_money(username, password, money, 2)) {
    
                        int money_start = stoi(conti_correnti[indice][7]);
                        
                        int money_deposita = money_start+money;
                        
                        conti_correnti[indice][7] = to_string(money_deposita);
                        
                        cout<<"Saldo sul conto: "<<greenColorCode<<thousandSeparator(stoi(conti_correnti[indice][7]))<<"€"<<resetColorCode<<endl;
                        
                        vec_lista_movimenti.push_back("Versamento di " + thousandSeparator(money) + "€ - Nuovo saldo: " + thousandSeparator(stoi(conti_correnti[indice][7])) + "€\n");
                        
                        cout<<"\n1. Indietro\n2. Versamento\n\n3. Esci"<<endl<<endl;
                        int choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                        if(choose == 1) {
                            menu(username, password);
                        } else if(choose == 2) {
                            deposita(username, password);
                        } else if(choose == 2) {
                            cout<<endl<<redColorCode<<"Uscita in corso..."<<redColorCode;
                            exit(0);
                        }
                    } else {
                        cout<<redColorCode<<"Limite per transazione raggiunto!"<<resetColorCode<<endl;
                    }
                }
            }

        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
    }
    
    void preleva(string username, string password) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Preleva")<<resetColorCode<<endl;
        
        if(verify_login(username, password)) {
            if(username == conti_correnti[indice][0]) {
                cout<<"Saldo attuale: "<<greenColorCode<<thousandSeparator(stoi(conti_correnti[indice][7]))<<"€"<<resetColorCode<<endl<<endl;
                int money = 0;
                while(money != 3) {
                    money = ChooseWhileINT(money, "Quanto vuoi prelevare (0. Indietro)? €");
                    if(money == 0) {
                        menu(username, password);
                    }
                    if(check_money(username, password, money, 3)) { // 3 is menu option
                        int money_start = stoi(conti_correnti[indice][7]);
                    
                        int money_deposita = money_start-money;
                        
                        conti_correnti[indice][7] = to_string(money_deposita);
                        
                        cout<<"Saldo sul conto: "<<greenColorCode<<thousandSeparator(stoi(conti_correnti[indice][7]))<<"€"<<resetColorCode<<endl;
                        
                        vec_lista_movimenti.push_back("Prelievo di " + thousandSeparator(money) + "€ - Nuovo saldo: " + thousandSeparator(stoi(conti_correnti[indice][7])) + "€\n");
                        
                        cout<<"\n1. Indietro\n2. Preleva\n\n3. Esci"<<endl<<endl;
                        int choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                        if(choose == 1) {
                            menu(username, password);
                        } else if(choose == 2) {
                            preleva(username, password);
                        } else if (choose == 3) {
                            cout<<endl<<redColorCode<<"Uscita in corso..."<<redColorCode;
                            exit(0);
                        } else {
                            cout<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                        }
                    } else {
                        cout<<redColorCode<<"Fondi insufficienti o limite per transazione raggiunto!"<<resetColorCode<<endl;
                    }
                }
                
            }

        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
    }
    
    void information(string username, string password) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Informazioni conto")<<resetColorCode<<endl;
        
        if(verify_login(username, password)) {
            if(username == conti_correnti[indice][0]) {
                string codice_fiscale, data_nascita, data_creazione;
                if(!check_codfisc(conti_correnti[indice][5])) {
                    codice_fiscale = conti_correnti[indice][5] + " "+ redColorCode + "(Invalido)" + resetColorCode;
                } else {
                    codice_fiscale = conti_correnti[indice][5];
                }
                cout<<conti_correnti[indice][4]<<endl<<conti_correnti[indice][6];
                data_nascita = date.check_date(conti_correnti[indice][4]);
                data_creazione = date.check_date(conti_correnti[indice][6]);

                cout<<"Account username: "<<greenColorCode<<conti_correnti[indice][0]<<resetColorCode<<endl;
                cout<<"Nome intestatario: "<<greenColorCode<<conti_correnti[indice][2]<<resetColorCode<<endl;
                cout<<"Cognome intestatario: "<<greenColorCode<<conti_correnti[indice][3]<<resetColorCode<<endl;
                cout<<"Data di nascita intestatario: "<<greenColorCode<<data_nascita<<resetColorCode<<endl;
                cout<<"Codice fiscale intestatario: "<<greenColorCode<<codice_fiscale<<resetColorCode<<endl;
                cout<<"Data di apertura conto: "<<greenColorCode<<data_creazione<<resetColorCode<<endl<<endl;
                cout<<"IBAN conto corrente: "<<greenColorCode<<conti_correnti[indice][8]<<resetColorCode<<endl<<endl;
                cout<<"Saldo sul conto: "<<greenColorCode<<thousandSeparator(stoi(conti_correnti[indice][7]))<<"€"<<resetColorCode<<endl;
                
                if(!check_account(username, password)) {
                    cout<<orangeColorCode<<"\nAlcuni dati dell'account sono errati! Delle operazioni potrebbero essere non disponibili!"<<resetColorCode<<endl;
                }

                int choose = 0;
                cout<<"\n1. Indietro\n2. Lista movimenti\n3. Esci"<<endl<<endl;
                while(choose != 3) {
                    int choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                    if(choose == 1) {
                        menu(username, password);
                    } else if(choose == 2) {
                        lista_movimenti(username, password);  
                    } else if(choose == 3) {
                        cout<<endl<<redColorCode<<"Uscita in corso..."<<redColorCode;
                        exit(0);
                    } else {
                        cout<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                    }
                }
            }

        } else {
            cout<<redColorCode<<"Autenticazione fallita!"<<resetColorCode<<endl;
            home();
        }
    }
    
    void menu(string username, string password) {
        if(verify_login(username, password)) {
            ClearScreen();
            cout<<cyanColorCode<<CustomSeparatorWithText("=", "Menu")<<resetColorCode;
            cout<<"Benvenuto "<<username<<endl<<endl;
            cout<<"1. Informazioni conto corrente"<<endl;
            cout<<"2. Versamento"<<endl;
            cout<<"3. Preleva"<<endl;
            cout<<"4. Bonifico bancario"<<endl<<endl;
            

            cout<<"5. Cambia account"<<endl;
            cout<<"6. Esci"<<endl<<endl;

            int choose = 0;
            while(choose != 6) {
                choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
                if(choose == 1) {
                    information(username, password);
                } else if (choose == 2) {
                    deposita(username, password);
                } else if (choose == 3) {
                    preleva(username, password);
                } else if (choose == 4) {
                    send_money(username, password);
                } else if (choose == 5) {
                    vec_lista_movimenti.clear(); // Cancello tutto il contenuto del vettore lista movimenti
                    ClearScreen();
                    home();
                } else if (choose == 6) {
                    cout<<endl<<redColorCode<<"Uscita in corso..."<<redColorCode;
                    exit(0);
                } else {
                    cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                }
            }

        } else {
            cout<<redColorCode<<"Autenticazione non eseguita."<<resetColorCode<<endl;
            home();
        }
    }
    
    void home() {
        cout<<cyanColorCode<<CustomSeparatorWithText("=", BankName)<<resetColorCode<<endl;
        
        cout<<"Benvenuto, cosa vuoi fare?"<<endl;
        cout<<"1. Accedi ad un conto corrente\n2. Apri un conto corrente\n\n3. Esci\n\n";
        int choose = 1;
        while(choose != 3) {
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            
            if(choose == 1) {
                string username;
                string password;
                int tentativi = 3;
                while(username != "exit" or password != "exit") {
                    cout<<"Username: "<<greenColorCode;
                    cin>>username;
                    cout<<resetColorCode<<"Password: "<<greenColorCode;
                    cin>>password;
                    cout<<resetColorCode;
                    
                    if(verify_login(username, password) && tentativi > 0) {
                        menu(username, password); // Show menu. Pass username and password and re-verify user.
                        break;
                    } else {
                        if(tentativi <= 1) {
                            cout<<redColorCode<<"Errore. tentativi esauriti!"<<resetColorCode<<endl<<endl;
                            sleep(3);
                            exit(0);
                        } else {
                            tentativi--;
                            cout<<redColorCode<<"Errore. Username o password errati!"<<resetColorCode<<endl;
                            cout<<redColorCode<<"Tentativi rimasti: "<<tentativi<<resetColorCode<<endl<<endl;             
                        }
                    }  
                }
            } else if (choose == 2) {
                OpenAccount openaccount;
                openaccount.createAccount();
            } else if (choose == 3) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode;
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
