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
    static double obliczWartoscFunkcjiInterpolowanej_Newton_wspolczynniki(std::vector<Punkt<double>> wezly, int n);
    static double obliczWartoscFunkcjiInterpolowanej_Newton_wartosc(std::vector<Punkt<double>> wezly, double x, int n);
    static double obliczWartoscFunkcjiInterpolowanej_Newton(std::vector<Punkt<double>> wezly, double x, int n);
    static std::vector<Punkt<double>> obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami);
    static double liczAn(std::vector<Punkt<double>> wezly, int n);
    static double liczQn(std::vector<Punkt<double>> wezly, double x, int n);


    ///Lagrange
    static double obliczWartoscFunkcjiInterpolowanej_Lagrange(std::vector<Punkt<double>> wezly, double x);
    static std::vector<Punkt<double>> obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami);

};

#endif // INTERPOLACJA_H
