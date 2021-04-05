#ifndef MACIERZ_H
#define MACIERZ_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define uint unsigned int

#include "Wiersz.h"

class Macierz
{
private:
    std::vector<Wiersz*> wiersze;

private:
    void allocateMemory(uint n, uint m);

public:
    Macierz(uint n, uint m);
    Macierz(std::string nazwa_pliku);
    ~Macierz();

    double getValue(uint n, uint m);
    bool setValue(uint n, uint m, double v);
    int getSizeX();
    int getSizeY();

    Wiersz oblicz();

    std::string toString();
};

#endif // MACIERZ_H
