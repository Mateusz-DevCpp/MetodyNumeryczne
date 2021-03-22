#include "MetodaSiecznych.h"

#include "Horner.h"

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
        else
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
        else
            a = x;
    }

    return x;
}

int MetodaSiecznych::PodajIloscIteracji()
{
    return liczba_iteracji;
}

double MetodaSiecznych::szukanieMtSiecznych_IT_W(std::vector<double> wsp_f, Przedzial p, int ilosc_iteracji)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;


    for(int i=0; i<ilosc_iteracji; i++)
    {
        liczba_iteracji++;
        x = a - (Horner::wartoscWielomianuHorner(a,wsp_f)/(Horner::wartoscWielomianuHorner(b,wsp_f)-Horner::wartoscWielomianuHorner(a,wsp_f))) * (b-a);

        if(Horner::wartoscWielomianuHorner(x,wsp_f)*Horner::wartoscWielomianuHorner(a,wsp_f) < 0)
            b = x;
        else
            a = x;
    }
    return x;
}

double MetodaSiecznych::szukanieMtSiecznych_E_W(std::vector<double> wsp_f, Przedzial p, double blad)
{
    liczba_iteracji = 0;

    double a=p.begin;
    double b=p.end;
    double x=0;

    while(fabs(Horner::wartoscWielomianuHorner(x,wsp_f)) >= blad)
    {
        liczba_iteracji++;
        x = a - (Horner::wartoscWielomianuHorner(a,wsp_f)/(Horner::wartoscWielomianuHorner(b,wsp_f)-Horner::wartoscWielomianuHorner(a,wsp_f))) * (b-a);

        if(Horner::wartoscWielomianuHorner(x,wsp_f)*Horner::wartoscWielomianuHorner(a,wsp_f) < 0)
            b = x;
        else
            a = x;
    }

    return x;
}
