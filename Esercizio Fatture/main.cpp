/*
Website: https://matt05.ml
GitHub: @Matt0550
Realizzare un programma che permetta di calcolare il totale
di una fattura tenuto conto che:

1. L’operatore dovrà inserire:
    a. La quantità della merce acquistata;
    b. Il prezzo unitario;
    c. L’aliquota IVA
    d. La modalità di pagamento
    
2. Il programma dovrà prevedere le seguenti funzioni:
    a. Calcolo dell’imponibile (quantità*prezzo unitario)
    b. Calcolo dell’IVA (imponibile*aliquota iva/100)
    c. Calcolo del totale lordo (imponibile + IVA)
    d. Calcolo dello sconto tenuto conto che:
        i. Se il pagamento è in contanti si avrà diritto ad uno sconto del 10%;
        ii. Se il pagamento è a 30gg l’importo totale dovrà essere aumentato degli interessi al 5% sul totale;
        iii. Se il pagamento è superiore a 30gg gli interessi saranno calcolati al 7%
        
3. Visualizzare:
    a. L’imponibile
    b. L’iva
    c. Il totale lordo
    d. Lo sconto
    e. Il totale netto (totale lordo-sconto+interessi)
*/

#include <iostream>

using namespace std;

string greenColorCode = "\033[92m";
string redColorCode = "\033[91m";
string cyanColorCode = "\033[96m";
string orangeColorCode = "\033[93m";
string purpleColorCode = "\033[95m";
string boldColorCode = "\033[1m";
string resetColorCode = "\033[0m";

// Function to clear the screen
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

class Program {
    public:
    float calcoloImponibile(float quantita, float prezzoUnitario) {
        return quantita * prezzoUnitario;
    }
    float calcoloIVA(float imponibile, float aliquotaIVA) {
        return imponibile * aliquotaIVA / 100;
    }
    float calcoloTotaleLordo(float imponibile, float iva) {
        return imponibile + iva;
    }
    float calcoloTotaleNetto(float totaleLordo, float sconto) {
        return totaleLordo + sconto;
    }
    float calcoloSconto(float totaleLordo, int pagamento) {
        if (pagamento == 1) { // Contanti
            return (totaleLordo * 0.1)*-1;
        } else if (pagamento == 2) { // 30gg
            return totaleLordo * 0.05;
        } else { // Più di 30gg
            return totaleLordo * 0.07;
        }
    }

    void menu() {
        cout << cyanColorCode<<CustomSeparatorWithText("=", "Inserisci i dati") << resetColorCode << endl;
        float quantita, prezzo, aliquota, pagamento;
        string choose;
        cout << "Quantita: ";
        cin >> quantita;
        cout << "Prezzo unitario: ";
        cin >> prezzo;
        cout << "Aliquota IVA: ";
        cin >> aliquota;
        cout << "\n\n1. Contanti\n2. 30 giorni\n3. Superiore a 30 giorni\nPagamento: ";
        cin >> pagamento;

        float imponibile = calcoloImponibile(quantita, prezzo);
        float iva = calcoloIVA(imponibile, aliquota);
        float totaleLordo = calcoloTotaleLordo(imponibile, iva);
        float sconto = calcoloSconto(totaleLordo, pagamento);
        float totaleNetto = calcoloTotaleNetto(totaleLordo, sconto);

        ClearScreen();
        cout << cyanColorCode<<CustomSeparatorWithText("=", "Totale") << resetColorCode << endl;
        cout << "Imponibile: " << orangeColorCode << imponibile << "€" << resetColorCode << endl;
        cout << "IVA: " << purpleColorCode << iva << "€" << resetColorCode << endl;
        cout << "Totale lordo: " << greenColorCode << totaleLordo << "€" << resetColorCode << endl;
        cout << "Totale netto: " << redColorCode << totaleNetto << "€" << resetColorCode << endl;
        if(sconto > 0) {
            cout << "Interesse: " << boldColorCode << sconto << "€" << resetColorCode << endl;
        } else {
            sconto *= -1;
            cout << "Sconto: " << cyanColorCode << sconto << "€" << resetColorCode << endl;
        }
        // Pause the program
        cout << "\n\nScrivere EXIT per uscire\n";
        cin >> choose;
        if (choose == "EXIT") {
            return;
        } else {
            menu();
        }
    }
};

int main() {
    Program program;
    program.menu();
    return 0;
}