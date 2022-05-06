/*
Website: https://matt05.ml
GitHub: @Matt0550
4. Trovare la lunghezza di una stringa tramite puntatori: ricordarsi che le stringhe terminano con '\0'
*/
#include <iostream>

using namespace std;

int lenString(char *str) {
    int len = 0;
    int i = 0;
    char *puntatore = &str[0];
    
    bool flag = false;
    
    while(flag == false) {
        if(*puntatore == '\0') {
            len = i;
            flag = true;
        } else {
            puntatore++;
            i++;
        }
    }
    
    return len;
}

int main()
{
    char txt[1000];
    cout<<"Inserisci una frase: ";
    cin>>txt;
    cout<<lenString(txt);
    return 0;
}