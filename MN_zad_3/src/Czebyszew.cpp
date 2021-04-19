#include "Czebyszew.h"

std::vector<Punkt<double>> Czebyszew::obliczWartosciWezlow(int ilosc_wezlow, Punkt<double> przedzial, char funkcja)
{
    std::vector<Punkt<double>> wynik;

    double x = 0;
    for(int k=0; k<ilosc_wezlow; k++)
    {
        x = cos( M_PI * (2*k + 1)/(2*ilosc_wezlow + 1) );
        x = 0.5*( (przedzial.y - przedzial.x)*x + (przedzial.y + przedzial.x) );

        wynik.push_back(Punkt<double>( x, Funkcja::oblicz(funkcja, x) ));
    }

    return wynik;
}
