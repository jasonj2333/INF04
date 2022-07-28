#include<iostream>
#include<exception> //Dołączenie biblioteki exception pozwala wykorzystać w programie klasę exception.
using namespace std;

class Wyjatek : public exception {
public:
    //Definicja funkcji what()
    const char* what() const throw() {
        return "Błąd! Próba dzielenia przez zero!";
    }
    /*Funkcja what() została zdefiniowana w klasie bazowej exception jako metoda wirtualna.
    Tym samym można  ją "przedefiniować" (napisać) w klasie pochodnej klasy exception - jak tutaj.
    Funkcja what() zwraca na zewnątrz wskaźnik do C-napisu.*/
};


int main()
{
	try
	{ //początek bloku kodu w którym realizowana jest inspekcja kodu źródłowego
		//Dane wejściowe
		double licznik = 1, mianownik = 0;
		if (mianownik == 0) {
			//Definicja obiektu wyjatek będącego instancją klasy Wyjatek
			Wyjatek wyjatek;
			//Zgłoszenie wyjątku - błędu.
			throw wyjatek;
			/*UWAGA:
			Błąd zostanie zgłoszony tylko w przypadku gdy wartość zmiennej mianownik jest równa 0.*/
		}
		else {
			cout << "Licznik: " << licznik << endl;
			cout << "Mianownik: " << mianownik << endl;
			cout << "Iloraz wynosi: " << licznik / mianownik << endl;
		}

	}
	catch (exception& e)
	{
		/*UWAGA:
		Wyjątek - obiekt należący do klasy bazowej exception jest przekazywany do procedury obsługi przez referencje.
		Celem jest umożliwienie przechwycienia wyjątków będących obiektami klas pochodnych wzgłędem klasy bazowej exception.
		Tutaj dotyczy to obiketu wyjatek będacego instacją klasy Wyjatek.*/
		cout << e.what() << endl;
	}
    return 0;
}