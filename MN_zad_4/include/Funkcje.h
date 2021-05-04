#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "Horner.h"

#include <string>
#include <cmath>

typedef double (*funkcja)(double);
typedef std::string (*funkcja_srt)();

double funkcja1(double x);
std::string funkcja1_ts();
double funkcja2(double x);
std::string funkcja2_ts();
double funkcja3(double x);
std::string funkcja3_ts();
double funkcja4(double x);
std::string funkcja4_ts();

double f_w(double x);

#endif // FUNKCJE_H
