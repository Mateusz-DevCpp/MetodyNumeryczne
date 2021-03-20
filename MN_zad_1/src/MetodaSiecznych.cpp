#include "MetodaSiecznych.h"

unsigned int MetodaSiecznych::liczba_iteracji = 0;

double MetodaSiecznych::szukanieMtSiecznych_IT(fun f, Przedzial p, int ilosc_iteracji)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    for(int i=0; i<ilosc_iteracji; i++)
    {
        liczba_iteracji++;
        x = a - (f(a)/(f(b)-f(a))) * (b-a);

        if(f(x)*f(a) < 0)
            b = x;
        else if(f(x)*f(a) > 0)
            a = x;
    }
    return x;
}

double MetodaSiecznych::szukanieMtSiecznych_E(fun f, Przedzial p, double blad)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    while(fabs(f(x)) >= blad)
    {
        liczba_iteracji++;
        x = a - (f(a)/(f(b)-f(a))) * (b-a);

        if(f(x)*f(a) < 0)
            b = x;
        else if(f(x)*f(a) > 0)
            a = x;
    }

    return x;
}

int MetodaSiecznych::PodajIloscIteracji()
{
    return liczba_iteracji;
}
