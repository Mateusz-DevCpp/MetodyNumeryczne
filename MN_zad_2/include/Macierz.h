#ifndef MACIERZ_H
#define MACIERZ_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define uint unsigned int

#include "Wiersz.h"

enum Status
{
    oznaczony = 0,
    nieoznaczony = 1,
    sprzeczny = 2
};

class Macierz
{
private:
    std::vector<Wiersz*> wiersze;
    Status status;

public:
    Macierz();
    Macierz(uint kolumny, uint wiersze);
    Macierz(std::string nazwa_pliku);
    ~Macierz();

    Status getStatus();
    std::string statusToString();

    void Clear();
    void loadFromFile(std::string nazwa_pliku);
    void allocateMemory(uint kolumny, uint wiersze);


    double getValue(uint wiersz, uint kolumna);
    bool setValue(uint wiersz, uint kolumna, double v);
    int getSizeC();
    int getSizeR();

    Wiersz oblicz();

    std::string toString();
};

#endif // MACIERZ_H
