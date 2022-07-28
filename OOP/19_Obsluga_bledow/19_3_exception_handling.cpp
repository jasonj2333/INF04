#include<iostream>
using namespace std;

int main()
{
	try
	{ //początek bloku kodu w którym realizowana jest inspekcja kodu źródłowego
		//Dane wejściowe
		double licznik = 1, mianownik = 0;
		if (mianownik == 0) //próba wykrycia wyjątku - błędu
			throw mianownik; //zgłoszenie błędu
			/*UWAGA:
			Obiektem zgłaszającym wyjątek (błąd) jest zmienna mianownik należąca do typu double*/
		
		cout << "Licznik: " << licznik << endl;
		cout << "Mianownik: " << mianownik << endl;
		cout << "Iloraz wynosi: " << licznik/mianownik << endl;
		/*UWAGA:
		Jeśli zostanie zgłoszonowy wyjątek, zestaw instrukcji powyżej nie zostanie wykonany.*/

	}
	catch (double mianownik)
	{
		cout << "Błąd! Próba dzielenia przez zero "  << endl;
		/*UWAGA:
		Jeżeli w treści procedury obsługi parametr formalny nie jest wykorzystywany - czyli tak jak tutaj - to 
		w nagłówku procedury obsługi można go pominąć.
		W taki przypadku nagłówek procedury obłsugi błędu miałby postać: catch(double).*/
	}
    return 0;
}