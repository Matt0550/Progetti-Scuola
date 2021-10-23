/*
Website: https://matt05.ml
GitHub: @Matt0550
8. Risolve un equazione di secondo grado del tipo ax2+bx+c=0
*/

#include <iostream>
#include <cmath> // Radice (sqrt)

using namespace std;

int main()
{
    double a, b, c, sol1, sol2, delta;
    cout<<"Inserisci X^2: ";
    cin>>a;
    
    cout<<"Inserisci X: ";
    cin>>b;
    
    cout<<"Inserisci il termine noto: ";
    cin>>c;
    
    delta = (b*b)-(4*a*c);
    sol1 = (-(b)-(sqrt(delta)))/(2*a);
    sol2 = (-(b)+(sqrt(delta)))/(2*a);
    
    if (delta < 0) {
        cout << "\nNon esistono soluzioni reali\n";
        return 0;
        
    } else if (delta == 0) {
        cout << "\nLe soluzioni sono coincidenti:\n\n";
        cout<<"\nSoluzione 1: "<<sol1<<"\nSoluzione 2: "<< sol2;
        
    } else {
        cout<<"\nSoluzione 1: "<<sol1<<"\nSoluzione 2: "<< sol2;
    }
    return 0;
}