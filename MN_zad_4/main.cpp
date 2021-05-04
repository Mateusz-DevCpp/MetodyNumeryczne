#include <iostream>

#include "Newton_Cotes.h"
#include "Hermit.h"
#include "Wykres.h"

using namespace std;

int main()
{
    Hermit::wczytajKwadratury();

    funkcja f[4] = {funkcja1,funkcja2,funkcja3,funkcja4};

    funkcja_srt fs[4] = {funkcja1_ts,funkcja2_ts,funkcja3_ts,funkcja4_ts};

    int wybor;
    cout << "Wybierz funkcje:" << endl;
    for(int i=0; i<4; i++)
        cout << i+1 << ". " << fs[i]() << endl;
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
            cout << "Przedzial od: \n>";
            cin >> pp;
            cout << "do \n>";
            cin >> kp;

            int il;
            cout << "Ile przedzialow: \n>";
            cin >> il;

            cout << "Wynik: " << Newton_Cotes::Oblicz(f[wybor], pp, kp, dok, il) << endl;
            cout << "Wykonano " << Newton_Cotes::ilosc_iteracji << " iteracji." << endl;
            Wykres::Rysuj(fs[wybor](), f[wybor], pp, kp);
        }
        else
        {
            double kr;
            cout << "Podaj krok" << endl << ">";
            cin >> kr;

            cout << "Wynik: " << Newton_Cotes::ObliczINF(f[wybor], dok, kr) << endl;
            cout << "Wykonano " << Newton_Cotes::ilosc_iteracji << " iteracji." << endl;
            Wykres::Rysuj(fs[wybor](), f[wybor], -4, 4);
        }
    }
    else
    {
        double il;
        cout << "Podaj ilosc wezlow (2,3,4,5):" << endl << ">";
        cin >> il;

        cout << "Wynik: " << Hermit::ObliczINF(f[wybor], il) << endl;
        cout << "Wykonano " << Hermit::ilosc_iteracji << " iteracji." << endl;
        Wykres::Rysuj(fs[wybor](), f[wybor], -4, 4);
    }

    return 0;
}
