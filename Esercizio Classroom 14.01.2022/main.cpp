/*
Website: https://matt05.ml
GitHub: @Matt0550

Realizzare un programma che ci permetta di calcolare il totale che serve pagare un'impresa per l'affitto
dei locali. Tenuto conto che:
1. L'affitto è pari a 15€ al metro quadrato
2. Se il totale è superiore a 600€ verrà applicato uno sconto del 10%, in caso contrario del 5€
3. Sul totale scontato calcolare imposta di registro pari al 2%.
Visualizzare:
1. L'importo dell'affitto
2. l'importo scontato
3. L'imposta di registro
*/

#include <iostream>

using namespace std;

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

int main()
{
    double metri = 0;
    double importo = 0;
    double sconto = 0;
    double imposte = 0;
    
    cout<<cyanColorCode<<CustomSeparatorWithText("=", "Affitta un locale")<<resetColorCode<<endl;
    metri = ChooseWhileINT(metri, "Inserisci i metri quadri del locale: ");

    while(metri != 0) {
        importo = metri*15;
        if(metri > 600) {
            sconto=(importo*10)/100;
            imposte=((importo-sconto)*2)/100;
        } else {
            sconto = (importo*5)/100;
            imposte=((importo-sconto)*2)/100;
        }
        ClearScreen();
        double totale = importo-sconto+imposte;
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Totale")<<resetColorCode;
        cout<<"\nTotale non scontato: "<<importo<<"€"<<endl;
        cout<<"Sconto applicato: "<<sconto<<"€"<<endl;
        cout<<"Imposte applicate: "<<imposte<<"€"<<endl;
        cout<<"TOTALE: "<<totale<<"€"<<endl;
        cout<<"\n\nPremere "<<boldColorCode<<"INVIO"<<resetColorCode<<" per tornare indietro: ";
        cin.get();
        cin.ignore();
        ClearScreen();
        main();
        break;
    }
    
    return 0;
}