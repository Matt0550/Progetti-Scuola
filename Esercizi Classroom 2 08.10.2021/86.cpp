/*
Website: https://matt05.ml
GitHub: @Matt0550
86. Classificare un triangolo rispetto agli angoli. 
*/

#include <iostream>

using namespace std;

string determinaTriangolo(double angolo1, double angolo2, double angolo3) {
    if (angolo1 == 90 && angolo2 == 90 && angolo3 == 90) {
        return "rettangolo";
        
    } else if (angolo1!=angolo2 && angolo2!=angolo3 && angolo1!=angolo3) {
        return "scaleno";
        
    } else {
        return "isoscele";
    }
}


int main()
{
    double angolo1, angolo2, angolo3;
    
    cout << "Inserire il primo angolo: ";
    cin >> angolo1;
    
    cout << "Inserire il secondo angolo: ";
    cin >> angolo2;
    
    cout << "Inserire il terzo angolo: ";
    cin >> angolo3;
    
    if (angolo1+angolo2+angolo3 == 180) {
        cout << "Il triangolo è " << determinaTriangolo(angolo1, angolo2, angolo3);
    } else {
        cout << "La somma degli angoli non fa 180.";
    }
    
    
    return 0;
}