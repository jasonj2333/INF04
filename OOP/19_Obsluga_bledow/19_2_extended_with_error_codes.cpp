#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string> //Trzeba dodać w VS 2022 żeby działała funkcja stoi()

using namespace std;

//Definicje pomocniczych funkcji globalnych
int wejscieFormat(string sDana, string& info) {
	string sTemp = "Format danej wejściowej nie odpowiada liczbie całkowitej!.";
	for (int i = 0; i < sDana.length(); i++)
	{
		if (isdigit(sDana[i]) == false) {
			info = sTemp;
			return -1;
		}
	}
	info = "";
	return 0;
}

//UWAGA:
//Zadaniem funkcji wejscieFormat() jest sprawdzenie, czy format parametru sDana należącego do typu łańcuchowego
//odpowiada liczbie całkowitej bez znaku. Jeśli tak zwraca na zewnątrz kod zwrotny 0, w przeciwnym razie zwraca kod -1.
//Oprócz tego funkcja przekazuje do swojego otoczenia informacje - treść komunikatu o ewentualnym błędzie.
//Wspomniany komunikat jest reprezentowany przez parametr łańcuchowy info przekazywany przez referencje.

int wejscieZakres(int iDana, string& info) {
	if ((iDana >= 1) && (iDana <= 6)) {
		info = "";
		return 0;
	}
	else {
		info = "Wartość danej wejściowej nie mieści się w zakresie <1,6>...";
		return -1;
	};
}
//UWAGA:
//Zadaniem funkcji wejscieZakres() jest sprawdzenie, czy wartość parametru iDana (będącego liczbą całkowitą) odpowiada
//ocenie szkolnej, tj. mieści się zakresie dokmnietym <1,6>.
//Jeśli tak - funkcja zwraca na zewnątrz kod zwrotny 0, w przeciwnym razie - kod równy -1.
//Oprócz tego funkcja przekazuje na zewnątrz za pośrednictwem parametru info informację o ewentualnym błędzie.


int main()
{
	//Definicje zmiennych pomocniczych
	string komunikat{}; //opis błędu (treść komunikatu o błędzie)
	int kod{}; //kod błędu
	
	//Deklaracja i inicjalizacja danych wejściowych sOcena reprezentującej ocenę semestralną ucznia
	string sOcena = "10"; //wartość danych jest celowo niepoprawną oceną.

	//Wywołanie oceny pomocnicznej wejscieFormat()
	kod = wejscieFormat(sOcena, komunikat);
	if (kod == 0) {//Sprawdzenie czy format łańcucha sOcena odpowiada liczbie całkowitej bez znaku.
		//Konwersja łańcucha sOcena na liczbę całkowitą
		int ocena = stoi(sOcena);
		/*UWAGA:
		Funkcja stoi() została wprowadzona w standardzie C++11
		Jej użycie wymaga dołączenia biblioteki cmath.*/
		kod = wejscieZakres(ocena, komunikat);
		if (kod == 0) {//sprawdzenie czy wartość zmiennej ocena należy do zakresu <1,6>
			//Przetwarzanie danych wejściowych
			switch (ocena)
			{
			case 1:
				cout << "Uczeń nie otrzymuje promocji do następnej klasy..." << endl;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				cout << "Uczeń otrzymuje promocji do następnej klasy..." << endl;
				break;
			}
			return 0;
		}
	}
	
	//Wyświetlenie informacji o błędzie (kodu zwrotnego i komunikatu kontrolnego)
	cout << "Uwaga błąd!" << endl;
	cout << "Kod: " << kod <<endl;
	cout << "Opis: " << komunikat <<endl;
	/*UWAGA:
	Instrukcje powyżej są odpowiedzialne za wyświetlanie informacji o błędzie tj. kodu zwrotnego i komunikatu kontrolnego.*/

    return kod;
}