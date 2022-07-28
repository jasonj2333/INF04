#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string> //Trzeba dodać w VS 2022 żeby działała funkcja stoi()

using namespace std;

//Definicje pomocniczych funkcji pomocniczych
bool wejscieFormat(string sDana) {
	for (int i = 0; i < sDana.length(); i++)
	{
		if (isdigit(sDana[i]) == false) {
			return false;
		}
	}
	return true;
}

bool wejscieZakres(int iDana) {
	if ((iDana >= 1) && (iDana <= 6)) return true;
	else return false;
}

int main()
{
	//Deklaracja i inicjalizacja danych wejściowych sOcena reprezentującej ocenę semestralną ucznia
	string sOcena = "10"; //wartość danych jest celowo niepoprawną oceną.
	try
	{//początek bloku kodu w którym realizowana jest inspekcja kodu źródłowego
		if (wejscieFormat(sOcena) == false) {//próba wykrycia błędu.
			throw sOcena; //zgłoszenie wyjątku sOcena
		}
		//Konwersja łańcucha sOcena na liczbę całkowitą
		int ocena = stoi(sOcena);
		/*UWAGA:
		Instrukcja powyżej zostanie wykonana tylko w przypadku, jeśli sOcena nie zgłosi wyjątku - błędu.*/
		if (wejscieZakres(ocena) == false) {//próba wykrycia błędu
			throw ocena; //zgłoszenie wyjątku ocena
		}
		//Instrukcje, które zostaną wykonane, jeśli nie zostanie zgłoszony żaden błąd.
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
	//Procedura obsługi wyjątku zgłoszonego przez zmienną sOcena.
	catch (string sOcena)
	{
		cout << "Uwaga błąd!" << endl;
		cout << "Format danej wejściowej nie odpowiada liczbie całkowitej!" << endl;
	}
	//Procedura obsługi wyjątku zgłoszonego przez zmienną ocena.
	catch (int ocena) {
		cout << "Uwaga błąd!" << endl;
		cout << "Wartość danej wejściowej nie mieści się w zakresie <1,6>!" << endl;
	}
    return 0;
}