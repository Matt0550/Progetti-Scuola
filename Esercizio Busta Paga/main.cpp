/*
Website: https://matt05.ml
GitHub: @Matt0550

Lo studio commerciale “Bardini & Roversi” vi chiede di realizzare un programma che permetta di elaborare
la busta paga dei dipendenti tenuto conto che le fasi sono le seguenti:
1. Definizione dello stipendio lordo (n° ore lavorate * paga base oraria);
2. Calcolo delle ritenute previdenziali (stipendio lordo * 23,81%)
3. Calcolo dell’imponibile fiscale (stipendio lordo – ritenuta previdenziale)

4. Calcolo dell’imposta lorda sull’imponibile fiscale.
Reddito Mensile - Aliquota Irpef
Fino a 1.154 23%
Oltre 1.154 fino a 2.154 25%
Oltre 2.154 35%

5. Calcolo delle seguenti detrazioni per lavoro dipendente:
Reddito Mensile - Importo Della Detrazione
Fino a 1.154 144
Oltre 1.154 fino a 2.154 146+92*(2.154-reddito)/1.000.

Oltre 2.154 0

6. Calcolo detrazioni per familiari a carico

Tipo - Importo Della Detrazione
figlio di età superiore ai tre anni; 220,00
figlio di età inferiore a tre anni 350,00
figlio disabile. 620,00

7. Calcolo detrazione coniuge e carico
Reddito Mensile - Importo Della Detrazione
Fino a 1.154 67
Oltre 1.154 fino a 3.333 58
Oltre 3.333 0

8. Calcolo dell’imposta netta (imposta lorda-detrazioni)

9. Calcolo dello stipendio netto da liquidare al lavoratore (Stipendio lordo-ritenute previdenziali-imposta netta)
Realizzare un programma che permetta di gestire attraverso le funzioni di calcolare la retribuzione mensile
di un dipendente
*/

#include <iostream>

using namespace std;

string CompanyName = "Bardini & Roversi";

const string greenColorCode = "\033[92m";
const string redColorCode = "\033[91m";
const string cyanColorCode = "\033[96m";
const string orangeColorCode = "\033[93m";
const string purpleColorCode = "\033[95m";
const string boldColorCode = "\033[1m";
const string resetColorCode = "\033[0m";

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
    double calcoloImpostaLorda(double imponibileFiscale) {
        double impostaLorda = (imponibileFiscale*23)/100;
        imponibileFiscale -= 1154;
        if(imponibileFiscale > 1154 && imponibileFiscale <= 2154) {
            impostaLorda += (imponibileFiscale*25)/100;
            imponibileFiscale -= 2154;
            if(imponibileFiscale > 0) {
                impostaLorda += (imponibileFiscale*35)/100;
                return impostaLorda;
            } else {
                return impostaLorda;
            }
        } else {
            return impostaLorda;
        }
    }
    
    double calcoloDetrazioniLavoroDipendente(double imponibileFiscale) {
        double detrazione = 144;
        imponibileFiscale -= 1154;
        if(imponibileFiscale > 1154 && imponibileFiscale < 2154) {
            detrazione += 146 + 92 *(2154 - imponibileFiscale)/1000;
            return detrazione;
        } else {
            return detrazione;
        }
    }
    
    double calcoloDetrazioniFamiliari(int nFigli) {
        double detrazione = 0;
        int tmp;
        if(nFigli > 0) {
            for(int i = 0; i < nFigli; i++) {
                cout<<"Inserisci i dati del "<<i+1<<" figlio:"<<endl;
                cout<<"1. Figlio di età superiore a 3 anni"<<endl;
                cout<<"2. Figlio di età inferiore a 3 anni"<<endl;
                cout<<"3. Figlio con una disabilità"<<endl;
                cout<<"4. Nessuna"<<endl;
                cout<<"Scelta: "<<greenColorCode;
                cin>>tmp;
                cout<<resetColorCode;
                switch(tmp) {
                    case 1: 
                        detrazione += 220;
                        break;
                    case 2:
                        detrazione += 350;
                        break;
                    case 3:
                        detrazione += 620;
                        break;
                    case 4:
                        detrazione += 0;
                    default:
                        cout<<endl<<redColorCode<<"Scelta non valida!"<<redColorCode<<endl;
                        detrazione += 0;
                        break;
                        
                }
            }
        }
        return detrazione;
    }

    
    double calcoloDetrazioniConiugeCarico(double imponibileFiscale) {//Funzione che mi serve per calcolare le detrazioni coniuge a carico
    	double detrazioni = 0;
    	detrazioni += 67;
    	imponibileFiscale -= 1154;
    	if (imponibileFiscale > 1154 && imponibileFiscale < 3333) {
    		detrazioni += 58;
    		return detrazioni;
    	} else {
    		return detrazioni;
    	}
    }
    
    void home() { 
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", CompanyName)<<resetColorCode;
        cout<<"Benvenuto nel calcolatore di busta paga. Compila i campi"<<endl;
        double oreLavorate;
        double pagaOraria;
        int nFigli;

        cout<<"Inserire il numero di ore lavorate: "<<greenColorCode;
        cin>>oreLavorate;
        cout<<resetColorCode;
        
        cout<<"Inserire la paga oraria in €: "<<greenColorCode;
        cin>>pagaOraria;
        cout<<resetColorCode;
        
        cout<<"Inserire il numero di figli: "<<greenColorCode;
        cin>>nFigli;
        cout<<resetColorCode;
        
        double stipendioLordo = oreLavorate*pagaOraria;
        double ritenutePrevidenziale = (stipendioLordo * 100)/23.81;
        double imponibileFiscale = stipendioLordo - ritenutePrevidenziale;
        double impostaLorda = calcoloImpostaLorda(imponibileFiscale);
        double DetrazioniFamiliari = calcoloDetrazioniFamiliari(nFigli);
        double DetrazioniConiugeCarico = calcoloDetrazioniConiugeCarico(imponibileFiscale);
        double DetrazioniLavoroDipendente = calcoloDetrazioniLavoroDipendente(imponibileFiscale);
        double detrazioni = DetrazioniFamiliari + DetrazioniConiugeCarico + DetrazioniLavoroDipendente;
        double impostaNetto = impostaLorda - detrazioni;
        double stipendioNetto = stipendioLordo - ritenutePrevidenziale - impostaNetto;
        
        cout << endl << "Il tuo stipendio netto è: " << greenColorCode<<stipendioNetto;
    }
};

int main() {
    Program program;
    program.home();
    return 0;
}
