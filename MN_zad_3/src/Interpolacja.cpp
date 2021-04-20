#include "Interpolacja.h"

std::vector<double> liczAn(std::vector<Punkt<double>> wezly)
{
    std::vector<double> a_;

    double an = 1;

    for(int i=0; i<wezly.size(); i++)
    {
        a_.push_back(an);
        double iloczyn = 1;
        for(int j=0; j<wezly.size(); j++)
        {
            if(i != j)
            {
                iloczyn *= (wezly[i].x - wezly[j].x);
            }
        }

        an += wezly[i].y / iloczyn;
    }

    std::vector<double> a;
    for(int i=a_.size(); i>=0; i--)
        a.push_back(a_[i]);

    return a;
}

std::vector<double> liczQn(std::vector<Punkt<double>> wezly, double x)
{
    std::vector<double> q_;
    double qn = wezly[0].y;

    for(int i=0; i<wezly.size(); i++)
    {
        q_.push_back(qn);

        qn *= (x - wezly[i].x);
    }

    std::vector<double> q;
    for(int i=q_.size(); i>=0; i--)
        q.push_back(q_[i]);

    return q_;
}

double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Newton(std::vector<Punkt<double>> wezly, double x)
{
    double wynik = 0, tmp;

    std::vector<double> a = liczAn(wezly);
    std::vector<double> q = liczQn(wezly, x);

    for(int k=0; k<wezly.size(); k++)
    {
        wynik += a[k] * q[k];
    }

    return wynik;
}

std::vector<Punkt<double>> Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami)
{
    std::vector<Punkt<double>> wynik;

    for(double x=przedzial.x; x<=przedzial.y; x+=odleglosc_miedy_punktami)
    {
        wynik.push_back( Punkt<double>(x, obliczWartoscFunkcjiInterpolowanej_Newton(wezly, x)) );
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
