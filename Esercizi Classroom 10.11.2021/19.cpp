/*
Website: https://matt05.ml
GitHub: @Matt0550
19. Dati N numeri determinare il valore maggiore e quante volte esso ricorre.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int numeri = 0;
    int i = 1;
    int max = 0;
    int num_tot = 1;
    
    cout<<"Quanti numeri vuoi inserire? ";
    cin>>numeri;

    while(i <= numeri) {
        cout<<i<<"/"<<numeri<<" Inserisci un numero intero (N): ";
        cin>>n;
        
        if(n==max) {
            num_tot++;
        }

        if (n>max) {
            num_tot = 1;
            max = n;
        }

        i++;
    }
    
    cout<<endl<<"Il numero più grande è: "<<max<<endl;
    cout<<"Il numero appare "<<num_tot<<" volte"<<endl;

    cout<<"Uscita...";
    return 0;
}
