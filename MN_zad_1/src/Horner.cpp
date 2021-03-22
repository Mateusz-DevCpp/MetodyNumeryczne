#include "Horner.h"

double Horner::wartoscWielomianuHorner(double x, double stopien, double* wspolczynniki)
{
    double wynik = 0;

    for(int i=0; i<=stopien; i++)
    {
        wynik *= x;
        wynik += wspolczynniki[i];
    }

    return wynik;
}

double Horner::wartoscWielomianuHorner(double x, std::vector<double> wspolczynniki)
{
    double wynik = 0;

    for(int i=0; i<wspolczynniki.size(); i++)
    {
        wynik *= x;
        wynik += wspolczynniki[i];
    }

    return wynik;
}
