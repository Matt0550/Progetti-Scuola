/*
Website: https://matt05.ml
GitHub: @Matt0550
52. Date le misure degli angoli di un triangolo, stabilire se il triangolo è rettangolo. 
*/

#include <iostream>

using namespace std;

string VerificaTipoTriangoloIpo(double angolo1, double angolo2, double angolo3) {
    double somma = angolo1+angolo2+angolo3;
    if (angolo1 == 90 or angolo2 == 90 or angolo3 == 90 and somma == 180) {
        return "rettangolo";
    } else {
        return "non rettangolo";
    }
    return "errore";
}

int main()
{
    double angolo1, angolo2, angolo3;
    
    cout << "Inserire la misura del primo angolo: ";
    cin >> angolo1;
    
    cout << "Inserire la misura del secondo angolo: ";
    cin >> angolo2;
    
    cout << "Inserire la misura del terzo angolo: ";
    cin >> angolo3;
    
    cout<<"Il triangolo è " << VerificaTipoTriangoloIpo(angolo1, angolo2, angolo3);

    
    
    return 0;
}
