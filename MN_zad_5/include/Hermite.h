#include <vector>

#include "Funkcje.h"

#include "../gnuplot_manager/include/Define.h"

using namespace std;

double obliczCalke(char wybor, int wezly, int stopien);
double wspolczynnikHermite(int stopien, char wybor, int wezly);
double aproksymacjaHermite(int stopien, char wybor, int wezly, double x);
vector<Punkt<double> > obliczPunktyAproksymacji(double a, double b, int stopien, char wybor, int wezly, double PRECYZJA=0.01);
double bladAproksymacji(int stopien, char wybor, int wezly, double a, double b);
double wielomianHermite(int stopien, double x);
