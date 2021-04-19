#ifndef CZEBYSZEW_H
#define CZEBYSZEW_H

#include <vector>
#include <string>
#include <math.h>
#include "Define.h"
#include "Funkcja.h"

class Czebyszew
{
public:
    static std::vector<Punkt<double>> obliczWartosciWezlow(int ilosc_wezlow, Punkt<double> przedzial, char funkcja);
};

#endif // CZEBYSZEW_H
