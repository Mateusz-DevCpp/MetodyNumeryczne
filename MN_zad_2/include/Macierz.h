#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#define uint unsigned int

#include "Wiersz.h"
#include "Raport.h"

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
    bool show_steps;

    Raport raport;

private:
    void resetKonfig();

public:
    Macierz();
    Macierz(uint kolumny, uint wiersze);
    Macierz(std::string nazwa_pliku);
    ~Macierz();

    Status getStatus();
    void showSteps(bool type);
    void init();
    void prepare();
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
    Raport getRaport();
    int iloscZer();
};

#endif // MACIERZ_H
