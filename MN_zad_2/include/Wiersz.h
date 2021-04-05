#ifndef WIERSZ_H
#define WIERSZ_H

#include <sstream>
#include <iomanip>

class Wiersz
{
private:
    double* wartosci;
    int n;

public:
    Wiersz(int n);
    ~Wiersz();

    bool setValue(int id, double v);
    double getValue(int id) const;

    unsigned int getSize() const;

    std::string toString();

    Wiersz &operator+(const Wiersz &other);
    Wiersz &operator-(const Wiersz &other);
    Wiersz &operator*(double x);
    Wiersz &operator/(double x);
    bool operator+=(const Wiersz &other);
    bool operator-=(const Wiersz &other);
    bool operator/=(double x);
    bool operator*=(double x);
};

#endif // WIERSZ_H
