/*
Website: https://matt05.ml
GitHub: @Matt0550
51. Date le misure dei lati di un triangolo, stabilire e il triangolo è equilatero, isoscele o scaleno. 
*/

#include <iostream>

using namespace std;

string VerificaTipoTriangolo(double lato1, double lato2, double lato3) {
    if (lato1 == lato2 && lato2 == lato3) {
        return "equilatero";
        
    } else if (lato1 != lato2 and lato2 != lato3 and lato1 != lato3) {
        return "scaleno";
    } else {
        return "isoscele";
    }
    return "errore";
}

int main()
{
    double lato1, lato2, lato3;
    
    cout << "Inserire la misura del lato 1: ";
    cin >> lato1;
    
    cout << "Inserire la misura del lato 2: ";
    cin >> lato2;
    
    cout << "Inserire la misura del lato 3: ";
    cin >> lato3;
    
    cout<<"Il triangolo è " << VerificaTipoTriangolo(lato1, lato2, lato3);

    
    
    return 0;
}
