#include "../include/Hermite.h"

double obliczCalke(char wybor, int wezly, int stopien)
{
    double wezel[4][5];
    double waga[4][5];

    wezel[0][0] = -0.707107;
    waga[0][0]  = 0.886227;
    wezel[0][1] = 0.707107;
    waga[0][1]  = 0.886227;

    wezel[1][0] = -1.224745;
    waga[1][0]  = 0.295409;
    wezel[1][1] = 0.000000;
    waga[1][1]  = 1.181636;
    wezel[1][2] = 1.224745;
    waga[1][2]  = 0.295409;

    wezel[2][0] = -1.650680;
    waga[2][0]  = 0.081313;
    wezel[2][1] = -0.534648;
    waga[2][1]  = 0.804914;
    wezel[2][2] = 0.534648;
    waga[2][2]  = 0.804914;
    wezel[2][3] = 1.650680;
    waga[2][3]  = 0.081313;

    wezel[3][0] = -2.020183;
    waga[3][0]  = 0.019953;
    wezel[3][1] = -0.958572;
    waga[3][1]  = 0.393619;
    wezel[3][2] = 0.000000;
    waga[3][2]  = 0.945309;
    wezel[3][3] = 0.958572;
    waga[3][3]  = 0.393619;
    wezel[3][4] = 2.020183;
    waga[3][4]  = 0.019953;

    double calka = 0;
    for(int i=0; i <wezly; i++)
    {
        calka += waga[wezly-2][i] * funkcja(wezel[wezly-2][i], wybor) * wielomianHermite(stopien, wezel[wezly-2][i]);
    }
    return calka;
}

double wspolczynnikHermite(int stopien, char wybor, int wezly)
{
    double wartosc = 0;
    wartosc = (1/(sqrt(M_PI) * potega(2, stopien) * silnia(stopien))) * obliczCalke(wybor, wezly, stopien);
    return wartosc;
}

double aproksymacjaHermite(int stopien, char wybor, int wezly, double x)
{
    double suma = 0;
    for(int i=0; i<=stopien; i++)
    {
        suma += wspolczynnikHermite(i, wybor, wezly) * wielomianHermite(i, x);
    }
    return suma;
}

vector<Punkt<double> > obliczPunktyAproksymacji(double a, double b, int stopien, char wybor, int wezly, double PRECYZJA)
{
    vector<Punkt<double> > pkt_apr;
    for(double x=a; x<=b; x=x+PRECYZJA)
    {
        pkt_apr.push_back(Punkt<double>(x, aproksymacjaHermite(stopien, wybor, wezly, x)));
    }
    return pkt_apr;
}

double bladAproksymacji(int stopien, char wybor, int wezly, double a, double b)
{
    double blad = 0;
    double h =(fabs(a-b) /(wezly-1));

    for(double i = a; i <= b; i = i + h)
    {
        blad +=(funkcja(i, wybor) - aproksymacjaHermite(stopien, wybor, wezly, i)) *(funkcja(i, wybor) - aproksymacjaHermite(stopien, wybor, wezly, i));
    }
    return blad;
}

double wielomianHermite(int stopien, double x)
{
    if(stopien == 0)
    {
        return 1;
    }
    else if(stopien == 1)
    {
        return 2*x;
    }
    else
    {
        return 2*x * wielomianHermite(stopien-1, x)-2 * (stopien-1) * wielomianHermite(stopien-2, x);
    }
}
