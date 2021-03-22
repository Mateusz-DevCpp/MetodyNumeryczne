#include "MetodaStycznych.h"

#include "Horner.h"

unsigned int MetodaStycznych::liczba_iteracji = 0;
double MetodaStycznych::error = 100;

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
        a = x;
    }

    error = fabs(f(x));
    return x;
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
        a = x;
    }
    error = fabs(f(x));
    return x;
}

int MetodaStycznych::PodajIloscIteracji()
{
    return liczba_iteracji;
}

double MetodaStycznych::szukanieMtStycznych_IT_W(std::vector<double> wsp_f, std::vector<double> wsp_p, Przedzial p, int ilosc_iteracji)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    for(int i=0; i<ilosc_iteracji; i++)
    {
        liczba_iteracji++;

        x = a - (Horner::wartoscWielomianuHorner(a, wsp_f)/Horner::wartoscWielomianuHorner(a, wsp_p));
        a = x;
    }

    error = fabs(Horner::wartoscWielomianuHorner(x, wsp_f));
    return x;
}

double MetodaStycznych::szukanieMtStycznych_E_W(std::vector<double> wsp_f, std::vector<double> wsp_p, Przedzial p, double blad)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    while(fabs(Horner::wartoscWielomianuHorner(a, wsp_f)) >= blad)
    {
        liczba_iteracji++;

        x = a - (Horner::wartoscWielomianuHorner(a, wsp_f)/Horner::wartoscWielomianuHorner(a, wsp_p));
        a = x;
    }

    error = fabs(Horner::wartoscWielomianuHorner(x, wsp_f));
    return x;
}

double MetodaStycznych::PodajWartoscBledu()
{
    return error;
}
