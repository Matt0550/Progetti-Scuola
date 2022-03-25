/*
Website: https://matt05.ml
GitHub: @Matt0550

L'azienda Rapisardi Corporation dopo una lunga riunione del consiglio d'amministrazione
ha deciso che per ottimizzare i processi aziendali necessita di un software gestionale per catalogare
i prodotti in magazzino hanno dunque deciso che il software in questione dovrà avere un menù con le seguenti
funzionalità:
1. Inserimento prodotto
2. Ricerca di un prodotto
3. Cancellazione di un prodotto
4. Somma del valore del totale dei prodotti
5. Somma del valore dei prodotti della stessa tipologia
6. Salvatagio dei dati su file
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> // Sort
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string CompanyName = "Rapisardi Corporation";
string fileName = "prodottiMagazzino.csv";

const string greenColorCode = "\033[92m";
const string redColorCode = "\033[91m";
const string cyanColorCode = "\033[96m";
const string orangeColorCode = "\033[93m";
const string purpleColorCode = "\033[95m";
const string boldColorCode = "\033[1m";
const string resetColorCode = "\033[0m";

int codice[1000] = {};
string tipologia[1000] = {};
int quantita[1000] = {};
string nome[1000] = {};
int prezzo[1000] = {};

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

string get_right_of_delim(string const& str, string const& delim){
  return str.substr(str.find(delim) + delim.size());
}

string get_left_of_delim(string const &str, string const &delim) {
    return str.substr(0, str.find(delim));
}

class Array {
    public:
    int arr_size = sizeof(codice)/sizeof(codice[0]);
    void initArrays() { // Set all arrays to -1
        for(int i = 0; i < arr_size; i++) {
            codice[i] = -1;
            tipologia[i] = "-1";
            quantita[i] = -1;
            nome[i] = "-1";
        }
    }
    
    int generateProductCode() { // Get the next number of product code.
        if(codice[0] == -1) {
            return 0;
        }
        for(int i = 0; i < arr_size; i++) {
            if(codice[i + 1] == -1) {
                return i + 1;
            }
        }
        return -1;
    }
    
    void loadDataByFile() {
        string line;
        ifstream myfile(fileName);
        
        if (myfile.is_open()) {
            while(getline(myfile, line)) {
                string productCode = get_left_of_delim(line, ";");
                string productName = get_left_of_delim(get_right_of_delim(line, ";"), ";");
                string productType = get_left_of_delim(get_right_of_delim(get_right_of_delim(line, ";"), ";"), ";");
                string productQuantity = get_left_of_delim(get_right_of_delim(get_right_of_delim(get_right_of_delim(line, ";"), ";"), ";"), ";");
                string productPrice = get_left_of_delim(get_right_of_delim(get_right_of_delim(get_right_of_delim(get_right_of_delim(line, ";"), ";"), ";"), ";"), ";");

                codice[stoi(productCode)] = stoi(productCode);
                nome[stoi(productCode)] = productName;
                tipologia[stoi(productCode)] = productType;
                quantita[stoi(productCode)] = stoi(productQuantity);
                prezzo[stoi(productCode)] = stoi(productPrice);
                
            }
        } else {
            cout<<redColorCode<<"Errore nell'aprire il file "<<boldColorCode<<fileName<<resetColorCode<<endl;
        }
    }
};

class Program {
    public:
    Array array;
    void addProduct() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Inserimento prodotto")<<resetColorCode<<endl;
        int productCode, productQuantity, productPrice;
        string productType, productName;
        
        cout<<"Nome prodotto: "<<greenColorCode;
        getline(cin, productName,'\n');
        cout<<resetColorCode;
        
        if(productName != "") {
            cout<<"Tipologia prodotto: "<<greenColorCode;
            getline(cin, productType,'\n');
            cout<<resetColorCode;
            
            cout<<"Quantità prodotto: "<<greenColorCode;
            cin>>productQuantity;
            cout<<resetColorCode;
            
            cout<<"Prezzo prodotto: "<<greenColorCode;
            cin>>productPrice;
            cout<<resetColorCode;
     
            productCode = array.generateProductCode();
            codice[productCode] = productCode;
            tipologia[productCode] = productType;
            quantita[productCode] = productQuantity;
            prezzo[productCode] = productPrice;
            nome[productCode] = productName;
            
            cout<<endl<<greenColorCode<<"Prodotto aggiunto con successo!"<<resetColorCode<<endl;
            sleep(1);
            home();
        }
    }
    
    void productList() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Lista prodotti")<<resetColorCode<<endl;
        int arr_size = sizeof(codice)/sizeof(codice[0]);

        for(int i = 0; i < arr_size && codice[i] !=-1; i++) {
            cout<<"["<<codice[i]<<"] "<<nome[i]<<" - "<<tipologia[i]<<" - quantity: "<<quantita[i]<<" - price: "<<prezzo[i]<<"€"<<endl;
        }
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        while(choose != 0) {
            switch(choose) {
                case 1:
                    home();
                    break;
                case 2:
                    cout<<endl<<redColorCode<<"Uscita..."<<resetColorCode<<endl;
                    exit(0);
                    break;
                default:
                    cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                    break;
            }
        }
    }
    
    void productListSum() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Somma prodotti")<<resetColorCode<<endl;
        
        int arr_size = sizeof(codice)/sizeof(codice[0]);
        int product = 0;
        int product2 = 0;
        int totalPrice = 0;
        for(int i = 0; i < arr_size && codice[i] !=-1; i++) {
            product++;
            product2 += quantita[i];
            totalPrice += prezzo[i];
        }
        
        cout<<"Nel magazzino sono presenti "<< product2<<" prodotti"<<endl;
        cout<<"Prodotti: "<<product<<"/"<<arr_size<<endl;
        cout<<"Totale: "<<totalPrice<<"€"<<endl;
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        while(choose != 0) {
            switch(choose) {
                case 1:
                    home();
                    break;
                case 2:
                    cout<<endl<<redColorCode<<"Uscita..."<<resetColorCode<<endl;
                    exit(0);
                    break;
                default:
                    cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                    break;
            }
        }
    }
    
    void productListSameCategorySum() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Lista prodotti")<<resetColorCode<<endl;
        cout<<"Seleziona una categoria"<<endl;
        
        int arr_size = sizeof(codice)/sizeof(codice[0]);

        sort(tipologia,tipologia+arr_size, greater<string>()); //Use the start and end like this
        
        cout<<"[0] "<<tipologia[0]<<endl;

        for(int i = 1; i < arr_size && codice[i-1] !=-1 && codice[i] != -1; i++) {
            if(tipologia[i] != tipologia[i - 1]) {
                cout<<"["<<i<<"] "<<tipologia[i]<<endl;
            }
        }
        
        int category = 0;
        int product = 0;
        int product2 = 0;
        int totalPrice = 0;
        category = ChooseWhileINT(category, "Categoria: ");
        for(int i = 0; i<arr_size && codice[i] != -1; i++) {
            if(tipologia[category] == tipologia[i]) {
                product++;
                product2+=quantita[i];
                totalPrice+=prezzo[i];
            }
        }
        cout<<endl<<"Nella categoria "<<boldColorCode<<tipologia[category]<<resetColorCode<<" sono presenti:"<<endl;
        cout<<product<<"/"<<arr_size<<" prodotti, per un totale di"<<endl;
        cout<<product2<<" prodotti in magazzino"<<endl;
        cout<<"Per un totale di "<<totalPrice<<"€";

        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        while(choose != 0) {
            switch(choose) {
                case 1:
                    home();
                    break;
                case 2:
                    cout<<endl<<redColorCode<<"Uscita..."<<resetColorCode<<endl;
                    exit(0);
                    break;
                default:
                    cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                    break;
            }
        }
    }
    
    
    void searchProduct() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Cerca prodotto")<<resetColorCode<<endl;
        int productCode;
        cout<<"Inserisci il codice prodotto: "<<greenColorCode;
        cin>>productCode;
        cout<<resetColorCode<<endl;
        
        int arr_size = sizeof(codice)/sizeof(codice[0]);

        for(int i = 0; i < arr_size && codice[i] != -1; i++) {
            if(codice[i] == productCode) {
                cout<<"["<<codice[i]<<"] "<<nome[i]<<" - "<<tipologia[i]<<" - quantity: "<<quantita[i]<<" - price: "<<prezzo[i]<<"€"<<endl;
            }
        }
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl<<endl;

        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        while(choose != 0) {
            switch(choose) {
                case 1:
                    home();
                    break;
                case 2:
                    cout<<endl<<redColorCode<<"Uscita..."<<resetColorCode<<endl;
                    exit(0);
                    break;
                default:
                    cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                    break;
            }
        }
    }
    
    void deleteProduct() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Elimina prodotto")<<resetColorCode<<endl;
        int productCode;
        cout<<"Inserisci il codice prodotto: "<<greenColorCode;
        cin>>productCode;
        cout<<resetColorCode<<endl;
        
        int arr_size = sizeof(codice)/sizeof(codice[0]);
        int indice = 0;

        for(int i = 0; i < arr_size && codice[i] != -1; i++) {
            if(codice[i] == productCode && codice[i] != -1) {
                cout<<"["<<codice[i]<<"] "<<nome[i]<<" - "<<tipologia[i]<<" - quantity: "<<quantita[i]<<" - price: "<<prezzo[i]<<"€"<<endl;
                indice = i;
            }
        }
        cout<<endl<<"1. Elimina"<<endl;
        cout<<"2. Indietro"<<endl;
        cout<<"3. Esci"<<endl<<endl;

        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        while(choose != 0) {
            switch(choose) {
                case 1:
                    for(int i = indice; codice[i] != -1; i++) {
                        codice[i] = codice[i + 1];
                        nome[i] = nome[i + 1];
                        tipologia[i] = tipologia[i + 1];
                        quantita[i] = quantita[i + 1];
                        prezzo[i] = prezzo[i + 1];
                        if(codice[i] != -1) {
                            codice[i] -= 1;  
                        }
                    }
                    
                    cout<<endl<<redColorCode<<"Eliminato!"<<resetColorCode<<endl;
                    sleep(1);
                    home();
                    break;
                case 2:
                    home();
                    break;
                case 3:
                    cout<<endl<<redColorCode<<"Uscita..."<<resetColorCode<<endl;
                    exit(0);
                    break;
                default:
                    cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                    break;
            }
        }
    }
    
    void saveProductListToFile() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Salva su file")<<resetColorCode<<endl;
        
        int arr_size = sizeof(codice)/sizeof(codice[0]);
        int totalProduct = 0;
        ofstream myfile;
        myfile.open(fileName);
        if (myfile.is_open()) {
            for(int i = 0; i < arr_size && codice[i] !=-1; i++) {
                myfile<<codice[i]<<";"<<nome[i]<<";"<<tipologia[i]<<";"<<quantita[i]<<";"<<prezzo[i]<<"\n";
                totalProduct++;
            }
            myfile.close();
            cout<<"Salvati/o "<<totalProduct<<" prodotti!"<<endl;
            cout<<greenColorCode<<"File salvato correttamente!"<<resetColorCode<<endl<<"Ritorno alla home..."<<endl;
            sleep(1);
            home();
        } else {
            cout<<redColorCode<<"Errore nell'aprire il file "<<boldColorCode<<fileName<<resetColorCode<<endl;
        }
    }
    
    void home() {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", CompanyName)<<resetColorCode<<endl;
        cout<<"1. Lista di tutti i prodotti"<<endl;
        cout<<"2. Inserimento prodotto"<<endl;
        cout<<"3. Ricerca di un prodotto"<<endl;
        cout<<"4. Cancellazione di un prodotto"<<endl;
        cout<<"5. Somma del valore del totale dei prodotti"<<endl;
        cout<<"6. Somma del valore dei prodotti della stessa tipologia"<<endl;
        cout<<"7. Salvatagio dei dati su file"<<endl<<endl;

        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        while(choose != 0) {
            switch(choose) {
                case 1:
                    productList();
                    break;
                case 2:
                    addProduct();
                    break;
                case 3:
                    searchProduct();
                    break;
                case 4:
                    deleteProduct();
                    break;
                case 5:
                    productListSum();
                    break;
                case 6:
                    productListSameCategorySum();
                    break;
                case 7:
                    saveProductListToFile();
                    break;
                default:
                    break;
            }
        }
    }
};

int main() {
    Program program;
    Array array;
    array.initArrays();
    array.loadDataByFile();
    program.home();
    return 0;
}