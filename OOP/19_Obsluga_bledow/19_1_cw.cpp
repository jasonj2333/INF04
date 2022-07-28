#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string> //Trzeba dodać w VS 2022 żeby działała funkcja stoi()

using namespace std;

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

void promocja(int ocena) {
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
void raportOceny(string sOcena) {
	if (wejscieFormat(sOcena)) {
		int ocena = stoi(sOcena);

		if (wejscieZakres(ocena)) {
			promocja(ocena);
		}
		else {
			cout << "Uwaga błąd!" << endl;
			cout << "Wartość danej wejściowej nie mieści się w zakresie <1,6>!" << endl;
		}
	}
	else {
		cout << "Uwaga błąd!" << endl;
		cout << "Format danej wejściowej nie odpowiada liczbie całkowitej!" << endl;

	}
}

int main()
{
	string sOceny[4] = { "4", "5", "2", "10" };
	
	for(string sOcena : sOceny) raportOceny(sOcena);
	
    return 0;
}