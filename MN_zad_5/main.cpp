#include <iostream>

#include <cmath>
#include <vector>

using namespace std;

#include "Funkcje.h"
#include "Hermite.h"

#include "gnuplot_manager/Gnuplot_manager.h"
#include "Wykres.h"

int main()
{
    vector<Punkt<double> > pkt_apr;

    cout << "wybierz funkcje: "<< endl;
    for(char i='1'; i<='5'; i++)
    {
        cout << i << ": " << funkcja_str(i) << endl;
    }

    char wybor;
    cout << ">";
    cin >> wybor;

    double a, b;
    cout << endl << "Podaj przedzial aproksymacji: \n(poczatek)>";
    cin >> a;
    cout << "(koniec)>";
    cin >> b;

    int wezly;
    cout << endl << "Ile wezlow Hermite'a (2, 3, 4, 5)? \n>";
    cin >> wezly;

    char dokladnosc;
    cout << "Czy chcesz podac oczekiwany blad aproksymacji \n[1] - tak\n[0] - nie\n>";
    cin >> dokladnosc;

    if(dokladnosc == '1')
    {
        double moj_blad, blad;
        cout << "Podaj dokladnosc aproksymacji: \n>";
        cin >> moj_blad;

        int stopien = 1;
        do
        {
            blad = bladAproksymacji(stopien, wybor, wezly, a, b);
            stopien++;

            cout << stopien-1 << " : " << blad << endl;
        }
        while(blad > moj_blad);

        cout << "Stopien wielomianu: " << stopien << endl;
        cout << "Blad aproksymacji: " << blad;
        pkt_apr = obliczPunktyAproksymacji(a, b, stopien, wybor, wezly);
    }
    else
    {
        int stopien;
        cout << endl << "Podaj stopien wielomianu aproksymujacego: \n>";
        cin >> stopien;

        pkt_apr = obliczPunktyAproksymacji(a, b, stopien, wybor, wezly);
        cout << "Blad aproksymacji wynosi: "<< bladAproksymacji(stopien, wybor, wezly, a, b);
    }

    rysuj_wykres(a, b, wybor, pkt_apr);

    return 0;
}
