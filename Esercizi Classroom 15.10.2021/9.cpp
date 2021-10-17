/*
Website: https://matt05.ml
GitHub: @Matt0550
9. Dato il numeratore e il denominatore di una frazione, stabilire se tale frazione è propria, impropria o apparente. 
*/

#include <iostream>

using namespace std;

string calcolo_frazione(int n, int d) { 
    if(n < d) {
        return "propria";
        
    } else if(n%d == 0) {
        return "apparente";
        
    } else {
        return "impropria";
    }
}

int main()
{
    int n,d;

    cout << "Inserire il numeratore: ";
    cin >> n;
    
    cout << "Inserire il denominatore: ";
    cin >> d;
    
    
    cout << "La frazione è " << calcolo_frazione(n, d);
    return 0;
}