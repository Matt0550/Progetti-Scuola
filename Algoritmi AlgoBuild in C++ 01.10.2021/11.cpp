#include <iostream>

using namespace std;

int main()
{   
    int a,b;
    cout<<"Inserisci il valore di A ";
    cin>>a;
    cout<<"Inserisci il valore di B ";
    cin>>b;

    if (a == b*b) {
        cout << "A è il quadrato di B";
    } else {
        cout << "A non è il quadrato di B";  
    }
    return 0;
}
