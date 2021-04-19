#ifndef INTERPOLACJA_H
#define INTERPOLACJA_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Define.h"

class Interpolacja
{
public:
    ///Newton
    static double obliczWartoscFunkcjiInterpolowanej_Newton(std::vector<Punkt<double>> wezly, double x);
    static std::vector<Punkt<double>> obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami);

    ///Lagrange
    static double obliczWartoscFunkcjiInterpolowanej_Lagrange(std::vector<Punkt<double>> wezly, double x);
    static std::vector<Punkt<double>> obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami);

};

#endif // INTERPOLACJA_H
