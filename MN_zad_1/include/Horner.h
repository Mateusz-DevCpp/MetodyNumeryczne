#ifndef HORNER_H
#define HORNER_H

#include <vector>

class Horner
{
public:
    static double wartoscWielomianuHorner(double x, double stopien, double* wspolczynniki);
    static double wartoscWielomianuHorner(double x, std::vector<double> wspolczynniki);
};

#endif // HORNER_H
