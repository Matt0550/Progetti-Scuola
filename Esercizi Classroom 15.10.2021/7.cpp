/*
Website: https://mAtt05.ml
GitHub: @MAtt0550
7. Stabilire se un numero naturale N, diverso da zero, è divisore di altri due numeri qualsiasi.
*/

#include <iostream>

using namespace std;

string calcolo_divisore(int A, int N, int N2){
    if(N%A == 0 && N2%A == 0){
        return to_string(A) + " è divisore di entrambi i numeri";
    }
    else if(N%A == 0 && N2%A != 0){
        return to_string(A) +" è divisore di " + to_string(N) + " ma non di "+ to_string(N2);
    }
    else if(N%A != 0 && N2%A == 0){
        return to_string(A) + " è divisore di " + to_string(N2) + " ma non di " + to_string(N);
    }
    else{
        return to_string(A) + " non è divisore di nessuno dei due numeri";
    }
}

int main(){
    int A,N,N2;
    cout<<"Inserisci un numero: ";
    cin>>A;
    if(A == 0){
        cout<<"Numero non valido, riprova"<<endl;
        main();
    }
    cout<<"Inserisci il primo numero da verificare come dividendo: ";
    cin>>N;
    cout<<"Inserisci il secondo numero da verificare come dividendo: ";
    cin>>N2;
    cout << calcolo_divisore(A,N,N2);
    return 0;
}