/*
Website: https://matt05.ml
GitHub: @Matt0550

2. Realizziamo un semplice diagramma a blocchi che rappresenti un algoritmo per
il calcolo del precedente e successivo di un numero preso in input.
*/

#include <iostream>

using namespace std;

int main()
{
    int a;
    cout<<"Inserisci il numero ";
    cin>>a;

    cout<<"Il numero prima di "<< a << " è " << a-1<<"\n";
    cout<<"Il numero dopo di "<< a << " è " << a+1;


    return 0;
}
