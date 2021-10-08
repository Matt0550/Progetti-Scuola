#include <iostream>

using namespace std;

int main()
{
    int somma = 0;
    int i = 0;

    while (i!=99) {
        cout << "Inserisci un valore ";
        cin>>i;
        somma = i + somma;
        cout<<"Totale: "<<somma<<"\n";
    }
    cout<<"\nIl numero è uguale a 99";
    
    return 0;
}
