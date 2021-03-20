#ifndef METODASIECZNYCH_H
#define METODASIECZNYCH_H

#include "Define.h"

class MetodaSiecznych
{
private:
    static unsigned int liczba_iteracji;

public:
    static double szukanieMtSiecznych_IT(fun f, Przedzial p, int ilosc_iteracji);
    static double szukanieMtSiecznych_E(fun f, Przedzial p, double blad);

    static int PodajIloscIteracji();
};

#endif // METODASIECZNYCH_H
