#ifndef RAPORT_H
#define RAPORT_H

#include <string>
#include <sstream>
#include <vector>

#include "../gnuplot_manager/include/GnuPlot.h"

class Raport
{
public:
    unsigned int ilosc_iteracji;
    unsigned int ilosc_iteracji_z_dzialaniami;
    std::vector<Point<double>> historia;

public:
    Raport();

    void reset();
    void dodajHistorie(int x, int y);
    std::string toString();
    void drawRaport();
};

#endif // RAPORT_H
