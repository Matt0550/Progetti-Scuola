/*
Website: https://matt05.ml
GitHub: @Matt0550
3. Implementare una funzione che inserita una data, converte il mese da numero a parola.
*/

#include <iostream>

using namespace std;

string meseStringa(int month) {
    switch (month) {
	case 1: return "gennaio"; break;
	case 2: return "febbraio"; break;
	case 3: return "marzo"; break;
	case 4: return "aprile"; break;
	case 5: return "maggio"; break;
	case 6: return "giugno"; break;
	case 7: return "luglio"; break;
	case 8: return "agosto"; break;
	case 9: return "settembre"; break;
	case 10: return "ottobre"; break;
	case 11: return "novembre"; break;
	case 12: return "dicembre"; break;
	default:
		return "not-valid";
		break;
	}
}

int main()
{
    cout<<"Il mese 12 a parole è "<<meseStringa(12);

    return 0;
}