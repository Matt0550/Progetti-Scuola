/*
Website: https://matt05.ml
GitHub: @Matt0550
*/

#include <iostream>

using namespace std;

int main()
{   
    int a,b,c;
    cout<<"Inserisci il valore di A ";
    cin>>a;
    cout<<"Inserisci il valore di B ";
    cin>>b;
    cout<<"Inserisci il valore di C ";
    cin>>c;
    int totale = a+b+c;
    cout << totale<<"\n";
    if (totale==180) {
        cout << "Angolo interno";
    } else {
        cout << "Angolo non interno";
    }
    return 0;
}
