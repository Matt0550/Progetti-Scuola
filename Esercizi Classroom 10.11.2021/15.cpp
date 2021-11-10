/*
Website: https://matt05.ml
GitHub: @Matt0550
15. Determinare la somma dei numeri negativi e positivi di un insieme di N numeri relativi.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int numeri = 0;
    int i = 1;
    int positivi = 0;
    int negativi = 0;

    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        if(n>0) {
            positivi+=n;
        } else {
            negativi+=n;
        }

        i++;
    }
    cout<<endl<<"La somma dei numeri positivi è: "<<positivi<<endl;
    cout<<"La somma dei numeri negativi è: "<<negativi<<endl;
    
    cout<<"Uscita...";
    return 0;
}
