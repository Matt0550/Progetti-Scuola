/*
Website: https://matt05.ml
GitHub: @Matt0550
5. Implementare una funzione che dato in ingresso una stringa (array di char) restituisca la stringa inversa.
*/

#include <iostream>
#include <string.h>

using namespace std;

char *reverseArray(char *s){
	int j = strlen(s)-1;
	char temp;
	for (int i = 0; i<j; i++) {
	    temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		j--;
	}
	return s;
}

int main()
{
    char text[]="Ciao";
    cout<<"Ciao: "<<reverseArray(text);

    return 0;
}