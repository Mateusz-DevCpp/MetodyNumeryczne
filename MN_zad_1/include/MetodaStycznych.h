#ifndef METODASTYCZNYCH_H
#define METODASTYCZNYCH_H

#include "Define.h"

#include <vector>

class MetodaStycznych
{
private:
    static unsigned int liczba_iteracji;

public:
    static double szukanieMtStycznych_IT(fun f, fun pf, Przedzial p, int ilosc_iteracji);
    static double szukanieMtStycznych_E(fun f, fun pf, Przedzial p, double blad);

    static double szukanieMtStycznych_IT_W(std::vector<double> wsp_f, std::vector<double> wsp_p, Przedzial p, int ilosc_iteracji);
    static double szukanieMtStycznych_E_W(std::vector<double> wsp_f, std::vector<double> wsp_p, Przedzial p, double blad);

    static int PodajIloscIteracji();
};

#endif // METODASTYCZNYCH_H






















