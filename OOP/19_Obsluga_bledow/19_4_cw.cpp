#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string> //Trzeba dodać w VS 2022 żeby działała funkcja stoi()

using namespace std;
class Wyjatek {
public:	

	bool inputFormat(string sDana) {
		for (int i = 0; i < sDana.length(); i++)
		{
			if (isdigit(sDana[i]) == false) {
				return false;
			}
		}
		return true;
	}
	bool inputRange(int iDana) {
		if (!(iDana >= 1) && (iDana <= 6)) throw true;
		else return false;
	}
};

int main()
{
	//Deklaracja i inicjalizacja danych wejściowych sOcena reprezentującej ocenę semestralną ucznia
	string sOcena = "7"; //wartość danych jest celowo niepoprawną oceną.
	try
	{//początek bloku kodu w którym realizowana jest inspekcja kodu źródłowego
		Wyjatek checkInput;
		if(checkInput.inputFormat(sOcena) == false) throw sOcena;
		//Konwersja łańcucha sOcena na liczbę całkowitą
		int ocena = stoi(sOcena);

		if(checkInput.inputRange(ocena) == false) throw ocena;
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
	catch (string)
	{
		cout << "Uwaga błąd!" << endl;
		cout << "Format danej wejściowej nie odpowiada liczbie całkowitej!" << endl;
	}
	//Procedura obsługi wyjątku zgłoszonego przez zmienną ocena.
	catch (int) {
		cout << "Uwaga błąd!" << endl;
		cout << "Wartość danej wejściowej nie mieści się w zakresie <1,6>!" << endl;
	}
    return 0;
}