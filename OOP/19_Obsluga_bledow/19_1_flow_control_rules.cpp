#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string> //Trzeba dodać w VS 2022 żeby działała funkcja stoi()

using namespace std;

//Definicje pomocniczych funkcji kontrolnych
bool wejscieFormat(string sDana) {
	for (int i = 0; i < sDana.length(); i++)
	{
		if (isdigit(sDana[i]) == false) {
			return false;
		}
	}
	return true;
}
//UWAGA:
//Zadaniem funkcji wejście format jest sprawdzenie czy format parametru sDana należącego do typu łańcuchowego
//odpowiada liczbie całkowitej bez znaku.Jeśli tak - funkcja wejscieFormat() zwraca na zewnątrz wartość true,
//w przeciwnym razie false;

bool wejscieZakres(int iDana) {
	if ((iDana >= 1) && (iDana <= 6)) return true;
	else return false;
}
//UWAGA:
//Zadaniem funkcji wejscieZakres() jest sprawdzenie, czy wartość parametru iDana będącego liczbą całkowitą odpowiada
//ocenie szkolnej, tj. mieści się w zakresie domkniętym <1,6>.
//Jeśli tak - funkcja zwraca true, w przeciwnym razie false.

int main()
{
	//Deklaracja i inicjalizacja danych wejściowych sOcena reprezentującej ocenę semestralną ucznia
	string sOcena = "10"; //wartość danych jest celowo niepoprawną oceną.
	
	if (wejscieFormat(sOcena)) {//Sprawdzenie czy format łańcucha sOcena odpowiada liczbie całkowitej bez znaku.
		//Konwersja łańcucha sOcena na liczbę całkowitą
		int ocena = stoi(sOcena);
		/*UWAGA:
		Funkcja stoi() została wprowadzona w standardzie C++11
		Jej użycie wymaga dołączenia biblioteki cmath.*/
		if (wejscieZakres(ocena)) {//sprawdzenie czy wartość zmiennej ocena należy do zakresu <1,6>
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

		}
		else { //Jeśli wartość danych wejściowych nie miejści się w zakresie <1,6>
			//Wyświetlanie na ekranie monitora komunikatu o błędzie
			cout << "Uwaga błąd!" << endl;
			cout << "Wartość danej wejściowej nie mieści się w zakresie <1,6>!" << endl;
		}
	}
	else { //Jeśli format danych wejściowych nie odpowiada liczbie całkowitej bez znaku
		//Wyświetlanie na ekranie monitora komunikatu o błędzie
		cout << "Uwaga błąd!" << endl;
		cout << "Format danej wejściowej nie odpowiada liczbie całkowitej!" << endl;

	}
    return 0;
}