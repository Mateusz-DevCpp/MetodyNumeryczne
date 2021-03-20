#include "MetodaStycznych.h"

unsigned int MetodaStycznych::liczba_iteracji = 0;

double MetodaStycznych::szukanieMtStycznych_IT(fun f, fun pf, Przedzial p, int ilosc_iteracji)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    for(int i=0; i<ilosc_iteracji; i++)
    {
        liczba_iteracji++;
        x = a - (f(a)/pf(a));
        if(x < p.begin)
            a += 0.25*(a+b);
        else
            a = x;
    }
    return a;
}

double MetodaStycznych::szukanieMtStycznych_E(fun f, fun pf, Przedzial p, double blad)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    while(fabs(f(a)) >= blad)
    {
        liczba_iteracji++;
        x = a - (f(a)/pf(a));
        if(x < p.begin)
            a += 0.25*(a+b);
        else
            a = x;
    }
    return a;
}

int MetodaStycznych::PodajIloscIteracji()
{
    return liczba_iteracji;
}
