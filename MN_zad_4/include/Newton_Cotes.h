#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

#include <cmath>

#include "Funkcje.h"
#include "Define.h"
#include "Wykres.h"

class Newton_Cotes
{
public:
    static int ilosc_iteracji;
    static double Oblicz(funkcja f, double pp, double kp, double dokladnosc, double ilosc_przedzialow);
    static double ObliczINF(funkcja f, double dokladnosc, double krok);
};

#endif // NEWTON_COTES_H
