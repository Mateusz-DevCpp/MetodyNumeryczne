#include "../include/Funkcje.h"

double wartoscWielomianu(double x, std::vector<double> wspolczynniki)
{
    double wynik = 0;

    for(unsigned int i=0; i<wspolczynniki.size(); i++)
    {
        wynik *= x;
        wynik += wspolczynniki[i];
    }

    return wynik;
}

double funkcja(double x, char wybor)
{
    switch(wybor)
    {
    case '1':
    {
        return x-5;
    }
    case '2':
    {
        std::vector<double> wsp;
        wsp.push_back(2);
        wsp.push_back(0.2);
        wsp.push_back(-1);
        wsp.push_back(1);

        return wartoscWielomianu(x, wsp);
    }
    case '3':
    {
        return sin(x);
    }
    case '4':
    {
        return fabs(x*x*x+cos(x));
    }
    case '5':
    {
        return fabs(x);
    }
    }
}

std::string funkcja_str(char wybor)
{
    switch(wybor)
    {
    case '1':
    {
        return "(x-5)";
    }
    case '2':
    {
        return "(2x^3+0.2x^2-1x+1)";
    }
    case '3':
    {
        return "(sin(x))";
    }
    case '4':
    {
        return "(|x^3+cos(x)|)";
    }
    case '5':
    {
        return "(|x|)";
    }
    }
}

double silnia(int k)
{
    double wynik = 1;
    for(int i=1; i<=k; i++)
    {
        wynik *= i;
    }
    return wynik;
}

double potega(double n, int k)
{
    double wynik = 1;
    for(int i=0; i<k; i++)
    {
        wynik *= n;
    }
    return wynik;
}
