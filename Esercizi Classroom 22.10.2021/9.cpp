/*
Website: https://matt05.ml
GitHub: @Matt0550
9. Calcola la media dei voti presi da un numero N di studenti in un compito in classe, con N inserito da tastiera
*/

#include <iostream>

using namespace std;

int main()
{

    int studenti;
    double somma = 0;
    double media = 0;
    cout<<"Quanti studenti ci sono in classe? ";
    cin>>studenti;
    
    double numeri[studenti] = {};
    int numeri_len = sizeof(numeri)/sizeof(numeri[0]);
    
    for(int i = 0; i< numeri_len; i++){
        cout << to_string(i+1)+"/"+to_string(studenti) + ". Inserire un voto per ogni studente (premi invio ad ogni numero): ";
        cin>>numeri[i];
        somma+=numeri[i];
    }

    
    media = somma/studenti;
    cout<<"\nLa media dei voti è: " << media;

    
    return 0;
}