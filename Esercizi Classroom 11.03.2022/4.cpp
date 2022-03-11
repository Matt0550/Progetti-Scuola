/*
Website: https://matt05.ml
GitHub: @Matt0550

Realizzare un programma, utilizzando lo switch case, che legga in input un voto 
rappresentato da un carattere tra A ed E e ne stampi il significato.
Ad esempio:
A significa ottimo;
B significa distinto;
C significa discreto;
D significa sufficiente;
E significa insufficiente.
*/

#include <iostream>

using namespace std;

int main()
{
    char voto;
    cout<<"Inserisci il voto: ";
    cin>>voto;
    switch(voto) {
        case 'A':
            cout<<"Ottimo";
            break;
        case 'B':
            cout<<"Distinto";
            break;
        case 'C':
            cout<<"Discreto";
            break;
        case 'D':
            cout<<"Sufficiente";
            break;
        case 'E':
            cout<<"Insufficiente";
            break;
        default:
            cout<<"Voto non valido!\n";
            main();
            break;
    }

    return 0;
}
