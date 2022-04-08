/*
Website: https://matt05.ml
GitHub: @Matt0550
2. Risolve un equazione di secondo grado del tipo ax2+bx+c=0
*/
#include <iostream>
#include <cmath> // Radice (sqrt)

using namespace std;

string risolviEquazione(double a, double b, double c) {
   
    double delta = (b*b)-(4*a*c);
    int sol1 = (-(b)-(sqrt(delta)))/(2*a);
    int sol2 = (-(b)+(sqrt(delta)))/(2*a);
    
    if (delta < 0) {
        return "\nNon esistono soluzioni reali\n";
        
    } else if (delta == 0) {
        return "\nLe soluzioni sono coincidenti:\n\nSoluzione 1: "+to_string(sol1)+"\nSoluzione 2: "+to_string(sol2);
        
    } else {
        return "\nSoluzione 1: "+to_string(sol1)+"\nSoluzione 2: "+to_string(sol2);
    }
}

int main()
{
    double a, b, c, sol1, sol2, delta;
    cout<<"Inserisci X^2: ";
    cin>>a;
    
    cout<<"Inserisci X: ";
    cin>>b;
    
    cout<<"Inserisci il termine noto: ";
    cin>>c;
    
    cout<<risolviEquazione(a, b, c);
    return 0;
}