#include <iostream>

#include "Newton_Cotes.h"
#include "Hermit.h"

using namespace std;

int main()
{
    Hermit::wczytajKwadratury();

    funkcja f[4];
    f[0] = funkcja1;
    f[1] = funkcja2;
    f[2] = funkcja3;
    f[3] = funkcja4;

    int wybor;
    cout << "Wybierz funkcje:" << endl;
    cout << "1. " << funkcja1_ts() << endl;
    cout << "2. " << funkcja2_ts() << endl;
    cout << "3. " << funkcja3_ts() << endl;
    cout << "4. " << funkcja4_ts() << endl;
    cout << ">";
    cin >> wybor;
    wybor--;

    char metoda;
    cout << "Wybierz metode:" << endl;
    cout << "1. Metoda Newtona-Cotes'a" << endl;
    cout << "2. Wybierz Hermitea" << endl;
    cout << ">";
    cin >> metoda;

    if(metoda == '1')
    {
        char wyb;
        cout << "1. Na wybranym przedziale" << endl;
        cout << "2. Na przedziale -inf;inf" << endl;
        cout << ">";
        cin >> wyb;
        double dok;
        cout << "Podaj dokladnosc" << endl << ">";
        cin >> dok;
        if(wyb == '1')
        {
            double pp, kp;
            cout << "Przedzial od: \n >";
            cin >> pp;
            cout << "do \n>";
            cin >> kp;

            int il;
            cout << "Ile przedzialow: \n >";
            cin >> il;

            cout << Newton_Cotes::Oblicz(f[wybor], pp, kp, dok, il) << endl;
        }
        else
        {
            double kr;
            cout << "Podaj krok" << endl << ">";
            cin >> kr;

            cout << Newton_Cotes::ObliczINF(f[wybor], dok, kr) << endl;
        }
    }
    else
    {
        double il;
        cout << "Podaj ilosc wezlow (2,3,4,5):" << endl << ">";
        cin >> il;

        cout << Hermit::ObliczINF(f[wybor], 2) << endl;
    }
    return 0;
}
