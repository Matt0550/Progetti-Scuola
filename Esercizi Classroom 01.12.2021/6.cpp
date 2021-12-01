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

    cout<<"Inserisci un numero intero (N): ";
    cin>>n;


    for(int i = 1; i <= 20; i++) {
        int numeri = n+i;
        if(numeri%2==0) {
            cout<<numeri<<endl;
        }
    }
    
    cout<<"Uscita...";
    return 0;
}