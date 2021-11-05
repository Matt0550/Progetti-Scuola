/*
Website: https://matt05.ml
GitHub: @Matt0550
6. Stampare i dieci numeri pari successivi al numero N.
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;

    cout<<"Inserisci un numero intero (N): ";
    cin>>n;


    while(i <= 20) {
        int numeri = n+i;
        if(numeri%2==0) {
            cout<<numeri<<endl;
        }
        i++;     
    }
    
    cout<<"Uscita...";
    return 0;
}
