#include <iostream>

using namespace std;

int main()
{
    int somma = 0;

    while (somma <= 30) {
        int i;
        cout << "Inserisci un valore ";
        cin>>i;
        somma = i + somma;
        cout<<"Totale: "<<somma<<"\n";
    }
    cout<<"\nLa somma ha superato il numero 30";
    
    return 0;
}
