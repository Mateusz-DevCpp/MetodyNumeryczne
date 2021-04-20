#ifndef FUNKCJA_H
#define FUNKCJA_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Define.h"
#include "Horner.h"

class Funkcja
{
public:
    static double liniowa(double x);
    static std::string liniowa_str();
    static std::string liniowa_przedzial_str();

    static double wartosc_bzw(double x);
    static std::string wartosc_bzw_str();
    static std::string wartosc_bzw_przedzial_str();

    static double wielomian(double x);
    static std::string wielomian_str();
    static std::string wielomian_przedzial_str();

    static double trygonometryczna(double x);
    static std::string trygonometryczna_str();
    static std::string trygonometryczna_przedzial_str();

    static double zlozona(double x);
    static std::string zlozona_str();
    static std::string zlozona_przedzial_str();

    static std::string podajWzor(char funkcja);
    static std::string podajSugerowanyPrzedzial(char funkcja);
    static double oblicz(char funkcja, double x);
    static std::vector<Punkt<double>> obliczPunkty(Punkt<double> przedzial, char funkcja, double odleglosc_miedy_punktami);
    static char idToFunkcja(int id);
};

#endif // FUNKCJA_H
