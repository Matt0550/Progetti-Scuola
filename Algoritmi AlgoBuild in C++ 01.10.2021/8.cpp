#include <iostream>

using namespace std;

int main()
{
    int a,b,c;

    cout<<"Inserisci il primo valore ";
    cin>>a;
    cout<<"Inserisci il secondo valore ";
    cin>>b;
    cout<<"Inserisci il terzo valore ";
    cin>>c;

    if (a>b && a>c) {
        cout<<"Il valore più grande è "<< a;
    } else if (b>a && b>c) {
        cout<<"Il valore più grande è "<< b;
    } else {
        cout<<"Il valore più grande è "<< c;
    }
    
    return 0;
}
