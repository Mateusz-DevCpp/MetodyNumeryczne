#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

#include "Funkcje.h"

class Newton_Cotes
{
public:
    static double Oblicz(funkcja f, double pp, double kp, double dokladnosc, double ilosc_przedzialow);
    static double ObliczINF(funkcja f, double dokladnosc, double krok);
};

#endif // NEWTON_COTES_H
