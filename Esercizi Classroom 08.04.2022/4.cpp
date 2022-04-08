/*
Website: https://matt05.ml
GitHub: @Matt0550
4. Restituisce il maggiore e il minore di una serie di numeri inseriti da tastiera
*/
#include <iostream>

using namespace std;

string calcoloNumeri(int *numeri, int nNumeri) {
    int max = 0;
    int min;
    for(int i = 0; i < nNumeri; i++){
        if (numeri[i] > max) {
            max=numeri[i];
        }
        if (numeri[i] < min) {
            min=numeri[i];
        }
    }
    return "\nIl numero più grande è: "+to_string(max)+"\nIl numero più grande è: "+to_string(min)+"\n";
}

int main()
{
    cout<<"Quanti numeri vuoi inserire? ";
    int n;
    cin>>n;
    
    int numeri[n] = {};

    for(int i = 0; i< n; i++){
        cout << to_string(i+1) + ". Inserire 10 numeri interi (premi invio ad ogni numero): ";
        cin>>numeri[i];
    }
    
    cout<<calcoloNumeri(numeri, n);

}