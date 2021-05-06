#ifndef WYKRES_H
#define WYKRES_H

#include <iostream>

#include "Funkcje.h"
#include "../interpolacja/interpolacja.h"

#include "../gnuplot_manager/Gnuplot_manager.h"
#include "../gnuplot_manager/include/Define.h"

class Wykres
{
public:
    static void Rysuj(std::string funkcja_str, funkcja wzor, double przedzial_p, double przedzial_k);
    static void Rysuj_Hermite(std::vector<Punkt<double>> punkty);
    static void Rysuj_Simsona(std::vector<Punkt<double>> punkty);
};

#endif // WYKRES_H
