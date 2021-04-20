#include "Interpolacja.h"

double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Newton_wspolczynniki(std::vector<Punkt<double>> wezly, int n)
{
    double wynik = 0;
    double tmp = 1;

    for(int k = 0; k < n; k++) {
        for(int j=0; j < n; j++) {
            if(k==j)
            {
                continue;
            }
            tmp *= (wezly[k].x - wezly[j].x);
        }
        wynik += (wezly[k].y / tmp);
        tmp = 1;
    }
    return wynik;

}

double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Newton_wartosc(std::vector<Punkt<double>> wezly, double x, int n)
{
    double tmp = 1.0;
    for(int i = 0;i<n-1;i++)
    {
        tmp *= (x-wezly[i].x);
    }
    return tmp;
}

double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Newton(std::vector<Punkt<double>> wezly, double x, int n)
{
    double finish = 0;
    for(int i = 0; i<n;i++)
    {
        finish += obliczWartoscFunkcjiInterpolowanej_Newton_wspolczynniki(wezly, i+1) * obliczWartoscFunkcjiInterpolowanej_Newton_wartosc(wezly, x, i+1);
    }
    return finish;
}


std::vector<Punkt<double>> Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami)
{
    std::vector<Punkt<double>> wynik;

    for(double x=przedzial.x; x<=przedzial.y; x+=odleglosc_miedy_punktami)
    {
        wynik.push_back( Punkt<double>(x, obliczWartoscFunkcjiInterpolowanej_Newton(wezly, x, wezly.size())) );
    }

    return wynik;
}



double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Lagrange(std::vector<Punkt<double>> wezly, double x)
{
    double wynik = 0, tmp;
    for(int i=0; i<wezly.size(); i++)
    {
        tmp = wezly[i].y;
        for(int j=0; j<wezly.size(); j++)
        {
            if(i != j)
            {
                tmp *= ((x - wezly[j].x) / (wezly[i].x - wezly[j].x));
            }
        }
        wynik += tmp;
    }
    return wynik;
}

std::vector<Punkt<double>> Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami)
{
    std::vector<Punkt<double>> wynik;

    for(double x=przedzial.x; x<=przedzial.y; x+=odleglosc_miedy_punktami)
    {
        wynik.push_back( Punkt<double>(x, obliczWartoscFunkcjiInterpolowanej_Lagrange(wezly, x)) );
    }

    return wynik;
}
