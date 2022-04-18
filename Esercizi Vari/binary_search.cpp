/*
Website: https://matt05.ml
GitHub: @Matt0550
Ricerca binaria 17/03/2022
*/

#include <iostream>

using namespace std;

int binary_search(int *array, int array_len, int cerca) {
    int start = 0; // Posizione d'inizio dell'array
    int stop = array_len; // Posizione di fine dell'array
    int mediana = 0; // Punto medio dell'array
    int indice = -1;
    
    while(start <= stop) {
        mediana =  (start+stop)/2; // Calcolo della mediana (la metà dell'array)
        if(array[mediana] == cerca) { // Se il valore mediano dell'array è uguale a quello che dobbiamo cercare ritorna la poszione dell'elemento
            indice = mediana;
            return indice;
            break;
        } else if (array[mediana] < cerca) { // Se il valore mediano dell'array è minore rispetto all'elemento da cercare, aumentiamo la posizione di inzio di 1
            start = mediana + 1;
        } else {
            stop = mediana - 1; // Altrimenti la diminuiamo di 1
        }
    }
    return indice;
}

int main() {
    int cerca;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; // Array ordinato
    int a_len = sizeof(a)/sizeof(a[0]); // Calcolo della lunghezza dell'array
    cout<<"Che numero vuoi cercare? ";
    cin>>cerca;
    int result = binary_search(a, a_len, cerca);
    
    if(result == -1) {
        cout<<"\nNon trovato"<<endl;
    } else {
        cout<<"Trovato alla posizione "<<result;
    }
    return 0;
}
