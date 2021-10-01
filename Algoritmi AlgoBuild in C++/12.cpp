/*
Website: https://matt05.ml
GitHub: @Matt0550
*/

#include <iostream>

using namespace std;

int main()
{   
    int a,b;
    cout<<"Inserisci il valore di A ";
    cin>>a;
    cout<<"Inserisci il valore di B ";
    cin>>b;

    if (a == b-1) {
        cout << "Successivo";
    } else {
        cout << "Precedente";  
    }
    return 0;
}
