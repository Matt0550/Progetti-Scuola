/*
Website: https://matt05.ml
GitHub: @Matt0550
54. Date le dimensioni di due rettangoli calcolarne l'area e determinare quale dei due ha superficie maggiore. 
*/

#include <iostream>

using namespace std;

string CalcoloArea(double b1, double h1, double b2, double h2) {
    double area1 = (b1*h1)/2;
    double area2 = (b2*h2)/2;
    
    if (area1 > area2) {
        return "Il primo rettangolo è il più grande: "+to_string(area1);
    } else {
        return "Il secondo rettangolo è il più grande: "+to_string(area2);
    }
}

int main()
{
    double b1, b2, h1, h2;
    
    cout << "Inserire la base del primo rettangolo: ";
    cin >> b1;
    
    cout << "Inserire l'area del primo rettangolo: ";
    cin >> h1;
    
    cout << "Inserire la base del secondo rettangolo: ";
    cin >> b2;
    
    cout << "Inserire l'area del secondo rettangolo: ";
    cin >> h2;
    
    cout<< CalcoloArea(b1, h1, b2, h2);

    
    
    return 0;
}
