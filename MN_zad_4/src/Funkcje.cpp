#include "Funkcje.h"

double funkcja1(double x)
{
    return x-5;
}

std::string funkcja1_ts()
{
    return "x-5";
}

double funkcja2(double x)
{
    return 3*x*x*x*x-2*x*x+6;
}

std::string funkcja2_ts()
{
    return "3x^4-2x^2+6";
}

double funkcja3(double x)
{
    return sin(x);
}

std::string funkcja3_ts()
{
    return "sin(x)";
}

double funkcja4(double x)
{
    return fabs(x*x*x+cos(x));
}

std::string funkcja4_ts()
{
    return "|x^3+cos(x)|";
}


double f_w(double x)
{
    return exp(-x*x);
}
