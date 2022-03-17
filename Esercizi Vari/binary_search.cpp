/*
Website: https://matt05.ml
GitHub: @Matt0550
Ricerca binaria 17/03/2022
*/

#include <iostream>

using namespace std;

int binary_search(int *array, int array_len, int cerca) {
    int start = 0;
    int stop = array_len;
    int mediana = 0;
    int indice = -1;
    
    while(start <= stop) {
        mediana =  (start+stop)/2;
        if(array[mediana] == cerca) {
            indice = mediana;
            return indice;
            break;
        } else if (array[mediana] < cerca) {
            start = mediana + 1;
        } else {
            stop = mediana - 1;
        }
    }
    return indice;
}

int main() {
    int cerca;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int a_len = sizeof(a)/sizeof(a[0]);
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
