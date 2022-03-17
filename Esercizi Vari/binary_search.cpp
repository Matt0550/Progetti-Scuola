/*
Website: https://matt05.ml
GitHub: @Matt0550
Ricerca binaria 17/03/2022
*/

#include <iostream>

using namespace std;

int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int cerca = 0;
int a_len = sizeof(a)/sizeof(a[0]);
int start = 0;
int stop = a_len;
bool trovato = false;
int mediana = 0;
int indice = -1;
int main() {
    cout<<"Che numero vuoi cercare? ";
    cin>>cerca;
    while(start <= stop) {
        mediana =  (start+stop)/2;
        
        if(a[mediana] == cerca) {
            indice = mediana;
            break;
        } else if (a[mediana] < cerca) {
            start = mediana + 1;
            
        } else {
            stop = mediana - 1;
        }
    }
    
    if(indice == -1) {
        cout<<"\nNon trovato"<<endl;
    } else {
        cout<<"Trovato alla posizione "<<indice;
    }
    return 0;
}
