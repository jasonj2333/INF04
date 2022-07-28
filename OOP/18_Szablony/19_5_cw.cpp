#include<iostream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

//Definicja struktury (klasy) abstrakcyjnej Wyjatek
struct Wyjatek {
    //Deklaracja metody abstrakcyjnej komunikat()
    virtual string komunikat() = 0;
};

//Definicja klasy Format, która jest pochodną klasy Wyjatek
class Format : public Wyjatek {
    //Deklaracja prywatnej zmienne członkowskiej
    string sOcena;
public:
    //Definicja konstruktora
    Format(string sOcena) : sOcena(sOcena) {}
    //Definicja metody komunikat() oddziedziczonej po klasie abstrakcyjnej Wyjatek
    string komunikat() {
        stringstream sTemp;
        sTemp << "Uwaga błąd! Format danej wejściowej " << sOcena << " nie odpowiada liczbie całkowitej!" << endl;
        return sTemp.str();
    }
};

//Definicja klasy Zakres, która jest pochodną klasy Wyjatek
class Zakres : public Wyjatek {
    int ocena;
public:
    //Definicja konstruktora
    Zakres(int ocena) : ocena(ocena) {}
    //Definicja metody komunikat() oddziedziczonej po klasie abstrakcyjnej Wyjatek
    string komunikat() {
        stringstream sTemp;
        sTemp << "Uwaga błąd! Wartość danej wejściowej " << ocena << " nie mieści się w zakresie <1,6>!" << endl;
        return sTemp.str();
    }
};

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
    try
    {
        //Deklaracja i inicjalizacja danych wejściowych sOcena reprezentującej ocenę semestralną ucznia
        string sOcena = "5"; //wartość danych jest celowo niepoprawną oceną.

        //Inspekcja kodu źródłowego w celu wykrycia błędu związanego z nieprawidłowym formatem danych wejściowych
        if (wejscieFormat(sOcena) == false) throw Format(sOcena);//zgłoszenie obiektu stanowiącego instacje klasy Format
        //Konwersja łańcucha sOcena na liczbę całkowitą
        int ocena = stoi(sOcena);

        //Inspekcja kodu źródłowego w celu wykrycia błędu związanego z nieprawidłowym zakresem danych wejściowych
        if (wejscieZakres(ocena) == false) throw Zakres(ocena); 

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
    catch (Zakres& zakres)
    {
        cerr << "Błąd zakresu" << endl;
        cerr << zakres.komunikat() << endl;
    }
    catch (Format& format)
    {
        cerr << "Błąd formatu" << endl;
        cerr << format.komunikat() << endl;
    }
    return 0;
}