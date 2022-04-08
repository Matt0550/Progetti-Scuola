/*
Website: https://matt05.ml
GitHub: @Matt0550
3. Calcola la media dei voti presi da un numero N di studenti in un compito in classe, con N inserito da tastiera
*/
#include <iostream>

using namespace std;

double calcolaMedia(double *studenti, double nStudenti) {
   int somma = 0;
    for(int i = 0; i< nStudenti; i++) {
        somma += studenti[i];
    }
    return somma/nStudenti;
}

int main()
{
    int studenti;
    cout<<"Quanti studenti ci sono in classe? ";
    cin>>studenti;
    
    double numeri[studenti] = {};
    int numeri_len = sizeof(numeri)/sizeof(numeri[0]);
    
    for(int i = 0; i< numeri_len; i++) {
        cout << to_string(i+1)+"/"+to_string(studenti) + ". Inserire un voto per ogni studente (premi invio ad ogni numero): ";
        cin>>numeri[i];
    }
    cout<<calcolaMedia(numeri, studenti);

    
}