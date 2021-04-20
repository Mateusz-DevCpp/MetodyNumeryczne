#ifndef BLEDY_H
#define BLEDY_H

#include <vector>
#include <algorithm>
#include <cmath>

#include "Define.h"

class Bledy
{
public:
    static double najwiekszyBladZbioru(std::vector<Punkt<double>> wartosci_poprawne, std::vector<Punkt<double>> wartosci_wyliczone);
    static double bladDanegoPunktu(Punkt<double> poprawny, Punkt<double> obliczony);
};

#endif // BLEDY_H
