/*
Website: https://matt05.ml
GitHub: @Matt0550
55. Dati un quadrato di lato L ed una circonferenza di raggio R stabilire quale delle due figure 
ha perimetro maggiore e quale delle due ha area maggiore. 
*/

#include <iostream>

using namespace std;

void CalcoloArea(double lato, double raggio) {
    double perimetroQuadrato = lato*4;
    double areaQuadrato= lato*lato;
    
    double perimetroCerchio = 2*3.14*raggio ;
    double areaCerchio = 3.14*lato*lato ;
    
    //cout << perimetroQuadrato << endl << perimetroCerchio << endl << areaQuadrato << endl << areaCerchio <<endl;

    if (perimetroQuadrato > perimetroCerchio) {
        cout << "Il quadrato ha il perimetro più grande" << endl;
    } else {
        cout << "La circonferenza ha il perimetro più grande" << endl;
    }
    
    if (areaCerchio > areaQuadrato) {
        cout << "La circonferenza ha l'area più grande" << endl;
    } else {
        cout << "Il quadrato ha l'area più grande" << endl;

    }
    
}

int main()
{
    double lato, raggio;
    
    cout << "Inserire il lato del quadrato: ";
    cin >> lato;
    
    cout << "Inserire il raggio della circonferenza: ";
    cin >> raggio;
    
    
    CalcoloArea(lato, raggio);

    
    
    return 0;
}
